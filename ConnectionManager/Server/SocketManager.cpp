//
// Created by Michal on 1/19/2018.
//

#include <iostream>
#include "SocketManager.h"
#include "../Exception/InitializationException.h"
#include "../Exception/SocketException.h"

Server::SocketManager::SocketManager(u_short port, const char *ip) {
    this->port = port;
    this->ip = ip;
}

void Server::SocketManager::prepareConnection() {
    try {
        this->initializeWSAData();
        this->createSocket();
        this->prepareMainSocketAddr();
        this->bindSocketToAddr();

    } catch (InitializationException& exception) {
        WSACleanup();
    }
}

/**
 * @throw InitializationException
 */
void Server::SocketManager::initializeWSAData() {
    int result = WSAStartup( MAKEWORD( 2, 2 ), & this->wsaData );
    if (result != NO_ERROR) {
        throw InitializationException("Cannot initialize WSADATA");
    }
}

void Server::SocketManager::createSocket() {
    this->mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if (this->mainSocket == INVALID_SOCKET) {
        throw InitializationException("Cannot create main socket");
    }
}

void Server::SocketManager::prepareMainSocketAddr() {
    memset(&this->sockAddr, 0, sizeof(this->sockAddr));
    this->sockAddr.sin_family = AF_INET;
    this->sockAddr.sin_addr.s_addr = inet_addr(this->ip);
    this->sockAddr.sin_port = htons(this->port);
}

void Server::SocketManager::bindSocketToAddr() {
    if (bind(this->mainSocket,(SOCKADDR*) &this->sockAddr, sizeof(this->sockAddr)) == SOCKET_ERROR) {
        throw InitializationException("Cannot bind socket to address");
    }
}

void Server::SocketManager::listenForConnection() {
    if (listen(this->mainSocket, 1) == SOCKET_ERROR) {
        throw InitializationException("I cant hear you!");
    }

    while (this->connectedSocket == SOCKET_ERROR) {
        this->connectedSocket = accept(this->mainSocket, nullptr, nullptr);
    }
}

int Server::SocketManager::sendData(const char *data) {
    int bytesSent;

    if (this->connectedSocket != SOCKET_ERROR) {
        bytesSent = send(this->connectedSocket, data, strlen(data), 0);
    } else {
        throw SocketException("To send data first initialize connection");
    }

    return bytesSent;
}

std::string Server::SocketManager::receiveData() {
    int bytesRecv;
    char recvbuf[64000] = "";

    if (this->connectedSocket != SOCKET_ERROR) {
        bytesRecv = recv(this->connectedSocket, recvbuf, 64000, 0 );
    } else {
        throw SocketException("To receive data first initialize connection");
    }
    std::string responseString(recvbuf);

    return responseString;
}

void Server::SocketManager::destroyConnectedSocket() {
    this->connectedSocket = SOCKET_ERROR;
}
