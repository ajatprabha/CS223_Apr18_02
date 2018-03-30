//
// Created by ajatprabha on 21/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_CONTROLLER_H
#define CLASSROOMBOOKINGSYSTEM_CONTROLLER_H

#include <iostream>
#include <base/views.h>
#include <vector>

using namespace std;

struct ViewPattern {
    string name;
    View *view;

    ViewPattern(const string &name, View *view);
};

class Controller {
private:
    static Controller *instance;
    static vector<ViewPattern> *views_list;

    Controller() = default;

public:
    static Controller &getInstance();

    void addViewPattern(const string &name, View *view);

    View *getView(const string &name);
};


#endif //CLASSROOMBOOKINGSYSTEM_CONTROLLER_H
