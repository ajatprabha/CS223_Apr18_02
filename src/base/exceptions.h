//
// Created by ajatprabha on 25/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_EXCEPTIONS_H
#define CLASSROOMBOOKINGSYSTEM_EXCEPTIONS_H

#include <iostream>

using namespace std;

class Exception {
    string errorMessage;
public:
    explicit Exception(const string &_errorMessage);

    string &getError();
};

class NotImplementedError : public Exception {
public:
    explicit NotImplementedError(const string &_errorMessage) : Exception(_errorMessage) {}
};


#endif //CLASSROOMBOOKINGSYSTEM_EXCEPTIONS_H
