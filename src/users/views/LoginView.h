//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_LOGINVIEW_H
#define CLASSROOMBOOKINGSYSTEM_LOGINVIEW_H

#include <base/views/View.h>

class LoginView : public View {
public:
    LoginView() : View("Enter your credentials to login to the system\n", {}, {}) {}

    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_LOGINVIEW_H
