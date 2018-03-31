//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_INIT_H
#define CLASSROOMBOOKINGSYSTEM_INIT_H

#include <iostream>
#include <base/views.h>
#include "users/models.h"
#include "controller.h"
#include "admin/views.h"
#include "users/views.h"

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

    void loadViewPatterns();

    BaseUser *getCurrentUser();
};

class SplashView : public View {
public:
    SplashView() : View("Welcome to ClassRoomBooking system\nChoose from the options below\n", {"Login", "Exit"},
                        {callLoginView, exit}) {}

    void display() override;

    static void callLoginView();
};


#endif //CLASSROOMBOOKINGSYSTEM_INIT_H
