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

using namespace std;

typedef void (*FnPtr)();

struct Response;

class View {
protected:
    Context context{};
    static Response *response;
    string title;
    vector<string> menuOptions{};
    vector<FnPtr> menuActions = {};

    View(const string &passedTitle, const vector<string> &passedVector, const vector<FnPtr> &passedActions);

public:
    View() = default;

    virtual void display() = 0;

    virtual Response call(const Context &);

    void populateMenu();

    void callAction(int menuPosition = 0);

    static void exit();
};

struct Response {
    View *view;
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEW_H
