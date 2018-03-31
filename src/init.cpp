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
    // Initialise all the static properties
    loadViewPatterns();
    BaseUser("Ajat", "Prabha", "admin@email.com", "password", true).save();
    this->view = controller.getView("splash");
    while (this->view) {
        Context tmp(this->user, -1);
        Response response = this->view->call(tmp);
        this->view = response.view;
        cout << "=========================================================\n";
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

void Application::loadViewPatterns() {
    controller.addViewPattern("splash", new SplashView);
    controller.addViewPattern("login", new LoginView);
    controller.addViewPattern("admin-panel", new AdminPanelView);
    controller.addViewPattern("admin-create", new AdminCreateView);
    controller.addViewPattern("admin-detail", new AdminDetailView);
    controller.addViewPattern("admin-delete", new AdminDeleteView);
}

BaseUser *Application::getCurrentUser() {
    return user;
}

void SplashView::display() {
    populateMenu();
    int choice;
    cin >> choice;
    callAction(choice - 1);
}

void SplashView::callLoginView() {
    response->view = Controller::getInstance().getView("login");
}