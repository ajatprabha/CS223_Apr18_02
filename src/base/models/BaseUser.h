//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_BASEUSER_H
#define CLASSROOMBOOKINGSYSTEM_BASEUSER_H

#include <cstring>
#include <base/models/Model.h>

class BaseUser : public Model<BaseUser> {
private:
    char firstName[32]{};
    char lastName[64]{};
    char email[64]{};
    char password[64]{};
    bool admin = false;
public:
    BaseUser() = default;

    BaseUser(const char *firstName, const char *lastName, const char *email, const char *password, bool admin);

    bool isAdmin();

    string getFullName() const;

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


#endif //CLASSROOMBOOKINGSYSTEM_BASEUSER_H
