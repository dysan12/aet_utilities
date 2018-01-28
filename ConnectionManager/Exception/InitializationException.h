//
// Created by Michal on 1/19/2018.
//

#ifndef AET_INITIALIZATIONEXCEPTION_H
#define AET_INITIALIZATIONEXCEPTION_H

#include "Exception.h"

class InitializationException : public Exception {
public:
    explicit InitializationException(const char* message = "", int errorCode = 0) :  Exception(message, errorCode){}
};


#endif //AET_INITIALIZATIONEXCEPTION_H
