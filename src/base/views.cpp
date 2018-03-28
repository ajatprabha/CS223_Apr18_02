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

void SplashView::display() {
    cout << "Splash View called\n";
}
