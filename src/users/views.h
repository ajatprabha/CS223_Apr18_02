//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_USERS_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_USERS_VIEWS_H

#include "../init.h"
#include "../base/views.h"

class LoginView : public View {
public:
    LoginView() : View("Enter your credentials to login to the system\n", {}, {}) {}

    void display() override;
};

class UserCreateView : public CreateView<BaseUser> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEWS_H
