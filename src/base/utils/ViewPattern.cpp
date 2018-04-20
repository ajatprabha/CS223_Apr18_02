//
// Created by ajatprabha on 12/3/18.
//

#include "ViewPattern.h"

ViewPattern::ViewPattern(const string &name, View *view) : name(name), view(view) {}

const string &ViewPattern::getName() const {
    return name;
}

void ViewPattern::setName(const string &name) {
    ViewPattern::name = name;
}

View *ViewPattern::getView() const {
    return view;
}

void ViewPattern::setView(View *view) {
    ViewPattern::view = view;
}
