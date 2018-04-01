//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_VIEWS_H

#include <iostream>
#include "models.h"
#include "exceptions.h"
#include "mixins.h"
#include "forms.h"
#include <users/models.h>
#include <vector>
#include <map>

using namespace std;

typedef void (*FnPtr)();

struct Context {
    BaseUser user;
    int requestObjectId = -1;

    Context() = default;

    Context(const BaseUser &passedUser, int passedRequestObjectId);
};

struct Response;


class View {
protected:
    Context context{};
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
class CreateView : public View {
protected:
    ModelForm<T> *form;
public:
    void display() override = 0;
};

template<class T>
class DetailView : public SingleObjectMixin<T>, public View {
public:
    DetailView() = default;
};

template<class T>
class DeleteView : public SingleObjectMixin<T>, public View {
public:
    void display() override;
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
    AdminDetailView() = default;

    void display() override;
};

class AdminCreateView : public CreateView<BaseUser> {
public:
    AdminCreateView() = default;

    void display() override;
};

class AdminPanelView : public View {
public:
    AdminPanelView() : View("\tAdmin panel\n\tHere you can perform the following actions.\n",
                            {"Create new admin", "Delete admin/professor", "Exit"},
                            {createAdmin, deleteUser, exit}) {}

    void display() override;

    static void deleteUser();

    static void createAdmin();
};

class AdminDeleteView : public DeleteView<BaseUser> {
public:
    void display() final;
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEWS_H
