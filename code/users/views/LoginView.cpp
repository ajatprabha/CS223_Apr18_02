//
// Created by ajatprabha on 1/4/18.
//

#include <base/controller.h>
#include <init/Application.h>
#include <base/utils/Input.h>
#include "LoginView.h"

void LoginView::display() {
    populateMenu();
    string email, password;
    cout << "Enter your email: ";
    email = Input::getEmail();
    cout << "Enter your password: ";
    password = Input::getPassword();
    Controller controller = Controller::getInstance();
    Application appInstance = Application::getInstance();
    if (appInstance.login(email, password)) {
        if (appInstance.getCurrentUser()->isAdmin()) {
            response->view = controller.getView("admin-panel");
        } else response->view = controller.getView("faculty-panel");
    } else {
        response->view = controller.getView("splash");
        cout << "Invalid credentials\n";
    }
}