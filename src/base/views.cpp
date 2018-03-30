//
// Created by ajatprabha on 12/3/18.
//

#include "views.h"

void View::display() {
    throw NotImplementedError("Method display of class View must be implemented by subclass");
}

Response View::call(const Context &contextPassed) {
    context = contextPassed;
    display();
    Response response{};
    response.view = nullptr;
    return response;
}

void View::populateMenu() {
    cout << title << endl;
    for (int i = 0; i < menu_options.size(); ++i) {
        cout << i + 1 << ". " << menu_options[i] << endl;
    }
}

View::View(const string &passedTitle, const vector<string> &passedVector) {
    title = passedTitle;
    menu_options = passedVector;
}

void SplashView::display() {
    populateMenu();
}
