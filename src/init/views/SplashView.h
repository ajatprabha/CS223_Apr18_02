//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SPLASHVIEW_H
#define CLASSROOMBOOKINGSYSTEM_SPLASHVIEW_H

#include <base/views/View.h>

class SplashView : public View {
public:
    SplashView() : View("Welcome to ClassRoomBooking system\nChoose from the options below\n", {"Login", "Exit"},
                        {callLoginView, exit}) {}

    void display() override;

    static void callLoginView();
};


#endif //CLASSROOMBOOKINGSYSTEM_SPLASHVIEW_H
