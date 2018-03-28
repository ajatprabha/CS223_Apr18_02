//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_INIT_H
#define CLASSROOMBOOKINGSYSTEM_INIT_H

#include <iostream>
#include <base/views.h>
#include "users/models.h"
#include "controller.h"

using namespace std;

class Application {
private:
    static Application *instance;
    static BaseUser *user;
    static View *view;
    Controller controller = Controller::getInstance();

    Application() = default;

public:
    static Application &getInstance();

    void start();

    bool login(const string &_email, const string &_password);

    void display();
};


#endif //CLASSROOMBOOKINGSYSTEM_INIT_H
