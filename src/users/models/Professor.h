//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_PROFESSOR_H
#define CLASSROOMBOOKINGSYSTEM_PROFESSOR_H

#include <base/models/BaseUser.h>

class Professor : public BaseUser {
public:
    Professor() = default;

    Professor(const string &passedFirstName, const string &passedLastName, const string &passedEmail,
              const string &passedPassword) : BaseUser(passedFirstName.c_str(), passedLastName.c_str(),
                                                       passedEmail.c_str(), passedPassword.c_str(), false) {}
};


#endif //CLASSROOMBOOKINGSYSTEM_PROFESSOR_H
