//
// Created by ajatprabha on 25/3/18.
//

#include "Exception.h"

Exception::Exception(const string &_errorMessage) {
    errorMessage = _errorMessage;
}

string &Exception::getError() {
    return errorMessage;
}
