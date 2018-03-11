//
// Created by ajatprabha on 12/3/18.
//

#include "models.h"

string BaseUser::getFullName() {
    return string(firstName) + string(lastName);
}

void BaseUser::setPassword(const string &_password) {
    for (int i = 0; i < _password.size(); ++i) {
        password[i] = _password[i];
    }
    password[_password.size()] = '\0';
}

bool BaseUser::checkPassword(const string &_password) {
    return _password == string(password);
}
