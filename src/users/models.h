//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_USER_MODELS_H
#define CLASSROOMBOOKINGSYSTEM_USER_MODELS_H

#include "../base/models.h"

class BaseUser : public Model<BaseUser> {
private:
    char firstName[32]{};
    char lastName[64]{};
    char password[64]{};
    char email[64]{};
    bool admin = false;
public:
    BaseUser() = default;

    BaseUser(const string &passedFirstName, const string &passedLastName, const string &passedEmail,
             const string &passedPassword, bool passedAdmin);

    bool isAdmin();

    string getFullName();

    void setPassword(const string &_password);

    bool checkPassword(const string &_password);

    const char *getFirstName() const;

    const char *getLastName() const;

    const char *getEmail() const;

    void *setFirstName(const string &_fname);

    void *setLastName(const string &_lname);

    void *setEmail(const string &_email);

    static BaseUser *findByEmail(const string &_email);
};

class Admin : public BaseUser {

};

class Professor : public BaseUser {

};

#endif //CLASSROOMBOOKINGSYSTEM_USER_MODELS_H
