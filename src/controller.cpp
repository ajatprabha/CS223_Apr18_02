//
// Created by ajatprabha on 21/3/18.
//

#include "controller.h"

Controller *Controller::instance = nullptr;

ViewPattern::ViewPattern(const string &name, View *view) {
    this->name = name;
    this->view = view;
}

void Controller::addViewPattern(const string &name, View *view) {
    ViewPattern temp = ViewPattern(name, view);
    views_list.push_back(temp);
}

View *Controller::getView(const string &name) {
    for (auto &i : views_list) {
        if (i.name == name) {
            return i.view;
        }
    }
    return nullptr;
}

Controller &Controller::getInstance() {
    if (!instance) {
        instance = new Controller;
    }
    return *instance;
}
