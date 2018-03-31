//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_VIEWS_H

#include <iostream>
#include "models.h"
#include "exceptions.h"
#include "mixins.h"
#include <users/models.h>
#include <vector>
#include <map>

using namespace std;

typedef void (*FnPtr)();

struct Context {
    BaseUser user;
};

struct Response;


class View {
protected:
    Context context;
    static Response *response;
    string title;
    vector<string> menuOptions;
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

template<class T>
class DetailView : public SingleObjectMixin<T>, public View {

};

class LoginView : public View {
public:
    LoginView() : View("Enter your credentials to login to the system\n", {}, {}) {}

    void display() override;
};

class SplashView : public View {
public:
    SplashView() : View("Welcome to ClassRoomBooking system\nChoose from the options below\n", {"Login", "Exit"},
                        {callLoginView, exit}) {}

    void display() override;

    static void callLoginView();
};

class AdminDetailView : public DetailView<BaseUser> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEWS_H
