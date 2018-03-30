//
// Created by ajatprabha on 12/3/18.
//

#include <init.h>
#include "views.h"

Response *View::response = nullptr;

Response View::call(const Context &contextPassed) {
    response = new Response;
    context = contextPassed;
    display();
    return *response;
}

void View::populateMenu() {
    cout << title << endl;
    for (int i = 0; i < menuOptions.size(); ++i) {
        cout << i + 1 << ". " << menuOptions[i] << endl;
    }
}

View::View(const string &passedTitle, const vector<string> &passedVector, const vector<FnPtr> &passedActions) {
    title = passedTitle;
    menuOptions = passedVector;
    menuActions = passedActions;
}

void View::callAction(int menuPosition) {
    menuActions[menuPosition]();
}

void View::exit() {
    response->view = nullptr;
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

void LoginView::display() {
    populateMenu();
    string email, password;
    cout << "Enter your email and password\n";
    cin >> email >> password;
    if (Application::getInstance().login(email, password)) {
        cout << "Logged in\n";
        response->view = nullptr;
    } else {
        cout << "Invalid credentials\n";
    }
}
