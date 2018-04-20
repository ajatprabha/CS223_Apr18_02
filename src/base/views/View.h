//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_VIEW_H
#define CLASSROOMBOOKINGSYSTEM_VIEW_H

#include <string>
#include <vector>
#include <iostream>
#include <base/models/BaseUser.h>
#include <base/utils/Context.h>
#include <base/utils/Response.h>

using namespace std;

struct Response;

class View {
protected:
    Context context{};
    static Response *response;
    string title;
    vector<string> menuOptions{};
    vector<View *> menuChoices = {};

    View(const string &passedTitle, const vector<string> &passedVector, const vector<View *> &passedChoices);

public:
    View() = default;

    virtual void display() = 0;

    virtual Response call(const Context &);

    void populateMenu();

    void callView(int menuPosition = 0);
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEW_H
