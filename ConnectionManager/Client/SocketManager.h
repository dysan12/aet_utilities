//
// Created by Michal on 1/21/2018.
//
#include <winsock2.h>
#include <string>

#ifndef AET_SOCKETMANAGER_H
#define AET_SOCKETMANAGER_H

namespace Client
{
    class SocketManager {
    public:
        void prepareConnection();
        void connectToServer(u_short port, const char *ip);
        int sendData(const char *data);
        std::string receiveData();
    private:
        WSADATA wsaData{};
        SOCKET mainSocket{};
        SOCKET connectedSocket = SOCKET_ERROR;
        void initializeWSAData();
        void createSocket();
    };
}



#endif //AET_SOCKETMANAGER_H
