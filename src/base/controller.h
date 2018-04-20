//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_CONTROLLER_H
#define CLASSROOMBOOKINGSYSTEM_CONTROLLER_H

#include <iostream>
#include <vector>
#include <base/views/View.h>
#include <base/utils/ViewPattern.h>

using namespace std;


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
