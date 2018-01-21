//
// Created by Michal on 1/21/2018.
//

#ifndef AET_SOCKETEXCEPTION_H
#define AET_SOCKETEXCEPTION_H


#include "AbstractException.h"

class SocketException : public AbstractException {
public:
    explicit SocketException(const char* message = "", int errorCode = 0) : AbstractException(message, errorCode){}
};


#endif //AET_SOCKETEXCEPTION_H
