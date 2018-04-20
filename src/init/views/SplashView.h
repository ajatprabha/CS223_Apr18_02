//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SPLASHVIEW_H
#define CLASSROOMBOOKINGSYSTEM_SPLASHVIEW_H

#include <controller.h>
#include <base/views/View.h>

class SplashView : public View {
public:
    SplashView() : View("Welcome to ClassRoomBooking system\nChoose from the options below\n", {"Login", "Exit"},
                        {Controller::getInstance().getView("login"), Controller::getInstance().getView("exit")}) {}

    void display() override;

    static void callLoginView();
};


#endif //CLASSROOMBOOKINGSYSTEM_SPLASHVIEW_H
