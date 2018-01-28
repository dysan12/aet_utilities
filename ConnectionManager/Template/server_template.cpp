// Server side C/C++ program to demonstrate Socket programming
#include <cstdio>
#include <cstdlib>

#include <winsock2.h>
#include <unistd.h>
#include <iostream>
#include "../Server/SocketManager.h"

#define PORT 10000
int main(int argc, char const *argv[])
{
    Server::SocketManager manager(7000,"127.0.0.1");
    manager.prepareConnection();
    manager.listenForConnection();

    manager.sendData("kropka");

    while(1)
    {
        std::string cos = manager.receiveData();
        std::cout<< cos;
    }
}