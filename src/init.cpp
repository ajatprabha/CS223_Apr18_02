//
// Created by ajatprabha on 12/3/18.
//

#include "init.h"

Application *Application::instance = nullptr;

Application &Application::getInstance() {
    if (!Application::instance) {
        Application::instance = new Application();
    }
    return *Application::instance;
}

void Application::start() {
    cout << "Application started!\n";
}
