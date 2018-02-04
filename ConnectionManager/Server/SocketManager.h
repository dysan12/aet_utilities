//
// Created by Michal on 1/19/2018.
//
#include <winsock2.h>
#include <string>

#ifndef AET_SOCKETMANAGER_H
#define AET_SOCKETMANAGER_H

namespace Server
{
    class SocketManager {
    public:
        SocketManager(u_short port, const char* ip);
        void prepareConnection();
        void listenForConnection();
        int sendData(const char* data);
        std::string receiveData();
        void destroyConnectedSocket();
    private:
        u_short port;
        const char *ip;
        WSADATA wsaData;
        SOCKET mainSocket;
        sockaddr_in sockAddr;
        SOCKET connectedSocket = SOCKET_ERROR;

        void initializeWSAData();
        void createSocket();
        void prepareMainSocketAddr();
        void bindSocketToAddr();
    };
}
#endif //AET_SOCKETMANAGER_H
