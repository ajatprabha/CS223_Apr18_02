//
// Created by ajatprabha on 12/3/18.
//

#include <base/utils/Input.h>
#include <base/controller.h>
#include "SplashView.h"

void SplashView::display() {
    populateMenu();
    callView(Input::getInt() - 1);
}

void SplashView::callLoginView() {
    response->view = Controller::getInstance().getView("login");
}
