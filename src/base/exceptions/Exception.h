//
// Created by ajatprabha on 25/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_EXCEPTION_H
#define CLASSROOMBOOKINGSYSTEM_EXCEPTION_H

#include <string>

using namespace std;

class Exception {
    string errorMessage;
public:
    explicit Exception(const string &_errorMessage);

    string &getError();
};


#endif //CLASSROOMBOOKINGSYSTEM_EXCEPTION_H
