//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_VIEWS_H

#include <iostream>
#include "models.h"
#include "exceptions.h"
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
    vector<FnPtr> menuActions;

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
class ModelView : public View {
private:
    T *object;
public:
    explicit ModelView(T *object);
};

template<class T>
ModelView<T>::ModelView(T *object) {
    this->object = object;
}

class SplashView : public View {
public:
    SplashView() : View("Welcome to ClassRoomBooking system\nChoose from the options below\n", {"Login", "Exit"},
                        {exit, exit}) {}

    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEWS_H
