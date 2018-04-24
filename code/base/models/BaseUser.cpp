//
// Created by ajatprabha on 12/3/18.
//

#include "BaseUser.h"

bool BaseUser::isAdmin() {
    return admin;
}

string BaseUser::getFullName() const {
    return string(firstName) + " " + string(lastName);
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

const char *BaseUser::getFirstName() const {
    return firstName;
}

const char *BaseUser::getLastName() const {
    return lastName;
}

const char *BaseUser::getEmail() const {
    return email;
}

void *BaseUser::setFirstName(const string &_fname) {
    for (int i = 0; i < _fname.size(); ++i) {
        firstName[i] = _fname[i];
    }
    firstName[_fname.size()] = '\0';
}

void *BaseUser::setLastName(const string &_lname) {
    for (int i = 0; i < _lname.size(); ++i) {
        lastName[i] = _lname[i];
    }
    lastName[_lname.size()] = '\0';
}

void *BaseUser::setEmail(const string &_email) {
    for (int i = 0; i < _email.size(); ++i) {
        email[i] = _email[i];
    }
    email[_email.size()] = '\0';
}

BaseUser *BaseUser::findByEmail(const string &_email) {
    for (auto &i: BaseUser::all()) {
        if (i.second.getEmail() == _email) {
            return &(i.second);
        }
    }
    return nullptr;
}

BaseUser::BaseUser(const char *passedFirstName, const char *passedLastName, const char *passedEmail,
                   const char *passedPassword, bool passedAdmin) : admin(passedAdmin) {
    strcpy(firstName, passedFirstName);
    strcpy(lastName, passedLastName);
    strcpy(password, passedPassword);
    strcpy(email, passedEmail);
    BaseUser *user = BaseUser::findByEmail(passedEmail);
    if(user) id = user->getId();
}
