//
// Created by ajatprabha on 12/3/18.
//

#include "controller.h"

Controller *Controller::instance = nullptr;
vector<ViewPattern> *Controller::views_list = nullptr;

void Controller::addViewPattern(const string &name, View *view) {
    ViewPattern temp = ViewPattern(name, view);
    if (!views_list) views_list = new vector<ViewPattern>;
    views_list->push_back(temp);
}

View *Controller::getView(const string &name) {
    for (auto &i : *views_list) {
        if (i.getName() == name) {
            return i.getView();
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
