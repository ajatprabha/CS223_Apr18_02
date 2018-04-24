//
// Created by ajatprabha on 1/4/18.
//

#include <init/Application.h>
#include <base/controller.h>
#include "LogoutView.h"

void LogoutView::display() {
    Application::getInstance().logout();
    cout << "Logged out successfully.\n";
    // Application::saveData();
    response->view = Controller::getInstance().getView("splash");
}
