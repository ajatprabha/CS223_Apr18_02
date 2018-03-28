//
// Created by ajatprabha on 12/3/18.
//

#include "init.h"

Application *Application::instance = nullptr;
BaseUser *Application::user = nullptr;
View *Application::view = nullptr;

Application &Application::getInstance() {
    if (!Application::instance) {
        Application::instance = new Application();
    }
    return *Application::instance;
}

void Application::start() {
    cout << "Application started!\n";
    // Initialise all the static properties
    this->user = new BaseUser;
    controller.addViewPattern("splash", new SplashView);
    this->view = controller.getView("splash");
    while (this->view) {
        this->display();
    }
}

bool Application::login(const string &_email, const string &_password) {
    BaseUser *temp = BaseUser::findByEmail(_email);
    if (temp) {
        if (temp->checkPassword(_password)) {
            this->user = temp;
            return true;
        }
    } else return false;
}

void Application::display() {
    //TODO
    Context tmp{};
    Response response = view->call(tmp);
    this->view = response.view;
}
