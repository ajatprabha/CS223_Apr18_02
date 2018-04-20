//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMIN_H
#define CLASSROOMBOOKINGSYSTEM_ADMIN_H

#include <base/models/BaseUser.h>

class Admin : public BaseUser {
public:
    Admin() = default;

    Admin(const string &passedFirstName, const string &passedLastName, const string &passedEmail,
          const string &passedPassword) : BaseUser(passedFirstName.c_str(), passedLastName.c_str(), passedEmail.c_str(),
                                                   passedPassword.c_str(), true) {}
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_H
