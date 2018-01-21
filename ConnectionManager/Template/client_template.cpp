//
// Created by Michal on 1/19/2018.
//
// Server side C/C++ program to demonstrate ConnectionManager programming
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <winsock2.h>
#include "../Client/SocketManager.h"
#include "../Exception/InitializationException.h"

int main(int argc, char const *argv[])
{
    Client::SocketManager manager;
    manager.prepareConnection();

    try {
        manager.connectToServer(10000, "127.0.0.1");

    } catch (InitializationException &exception)
    {

    }

    while(1)
    {
        std::string str;
        std::cin >> str;
        manager.sendData(str.c_str());
    }
}
