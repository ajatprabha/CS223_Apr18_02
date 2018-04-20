//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_APPLICATION_H
#define CLASSROOMBOOKINGSYSTEM_APPLICATION_H


#include <base/models/BaseUser.h>
#include <base/views/View.h>
#include <base/controller.h>

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

    void logout();

    void loadViewPatterns();

    BaseUser *getCurrentUser();

    static void saveData();

    static void readData();
};


#endif //CLASSROOMBOOKINGSYSTEM_APPLICATION_H
