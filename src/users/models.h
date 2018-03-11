//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_USER_MODELS_H
#define CLASSROOMBOOKINGSYSTEM_USER_MODELS_H

#include "../base/models.h"

class BaseUser : public Model<BaseUser> {
private:
    char firstName[32];
    char lastName[64];
    char password[64];
    char email[64];
public:
    BaseUser() = default;

    virtual bool isAdmin() = 0;

    string getFullName();

    void setPassword(const string &_password);

    bool checkPassword(const string &_password);
};


#endif //CLASSROOMBOOKINGSYSTEM_USER_MODELS_H
