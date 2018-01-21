//
// Created by Michal on 1/19/2018.
//

#include <iostream>
#include "SocketManager.h"
#include "../Exception/InitializationException.h"
#include "../Exception/SocketException.h"


void Client::SocketManager::prepareConnection() {
    try {
        this->initializeWSAData();
        this->createSocket();

    } catch (InitializationException& exception) {
        WSACleanup();
    }
}

/**
 * @throw InitializationException
 */
void Client::SocketManager::initializeWSAData() {
    int result = WSAStartup( MAKEWORD( 2, 2 ), & this->wsaData );
    if (result != NO_ERROR) {
        throw InitializationException("Cannot initialize WSADATA");
    }
}

void Client::SocketManager::createSocket() {
    this->mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if (this->mainSocket == INVALID_SOCKET) {
        throw InitializationException("Cannot create main socket");
    }
}

void Client::SocketManager::connectToServer(u_short port, const char *ip) {
    sockaddr_in service;

    memset(&service, 0, sizeof(service));
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(ip);
    service.sin_port = htons(port);

    if(connect(this->mainSocket,(SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR )
    {
        throw InitializationException("Cannot connect to the server");
    }
    this->connectedSocket = this->mainSocket;
}

int Client::SocketManager::sendData(const char *data) {
    int bytesSent;

    if (this->connectedSocket != SOCKET_ERROR) {
        bytesSent = send(this->connectedSocket, data, strlen(data), 0);
    } else {
        throw SocketException("To send data first connect to the server");
    }

    return bytesSent;
}

std::string Client::SocketManager::receiveData() {
    int bytesRecv;
    char recvbuf[64000] = "";


    if (this->connectedSocket != SOCKET_ERROR) {
        bytesRecv = recv(this->connectedSocket, recvbuf, 64000, 0 );
    } else {
        throw SocketException("To receive data first connect to teh server");
    }
    std::string responseString(recvbuf);

    return responseString;
}
