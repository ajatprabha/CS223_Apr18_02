//
// Created by ajatprabha on 25/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_NOTIMPLEMENTEDERROR_H
#define CLASSROOMBOOKINGSYSTEM_NOTIMPLEMENTEDERROR_H

#include "Exception.h"

class NotImplementedError : public Exception {
public:
    explicit NotImplementedError(const string &_errorMessage) : Exception(_errorMessage) {}
};

#endif //CLASSROOMBOOKINGSYSTEM_NOTIMPLEMENTEDERROR_H
