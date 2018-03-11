//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_INIT_H
#define CLASSROOMBOOKINGSYSTEM_INIT_H

#include <iostream>

using namespace std;


class Application {
private:
    static Application *instance;

    Application() = default;

public:
    static Application &getInstance();

    void start();
};


#endif //CLASSROOMBOOKINGSYSTEM_INIT_H
