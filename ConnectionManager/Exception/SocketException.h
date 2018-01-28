//
// Created by Michal on 1/21/2018.
//

#ifndef AET_SOCKETEXCEPTION_H
#define AET_SOCKETEXCEPTION_H


#include "Exception.h"

class SocketException : public Exception {
public:
    explicit SocketException(const char* message = "", int errorCode = 0) : Exception(message, errorCode){}
};


#endif //AET_SOCKETEXCEPTION_H
