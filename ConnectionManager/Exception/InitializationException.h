//
// Created by Michal on 1/19/2018.
//

#ifndef AET_INITIALIZATIONEXCEPTION_H
#define AET_INITIALIZATIONEXCEPTION_H

#include "AbstractException.h"

class InitializationException : public AbstractException {
public:
    explicit InitializationException(const char* message = "", int errorCode = 0) : AbstractException(message, errorCode){}
};


#endif //AET_INITIALIZATIONEXCEPTION_H
