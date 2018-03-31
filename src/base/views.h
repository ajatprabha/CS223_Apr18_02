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
    BaseUser *user = nullptr;
    int requestObjectId = -1;

    Context() = default;

    Context(BaseUser *passedUser, int passedRequestObjectId);
};

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

template<class T>
void DeleteView<T>::display() {
    T *object = SingleObjectMixin<T>::getObject(context.requestObjectId);
    if (object) {
        object->remove();
        cout << "Successfully deleted.\n";
    } else cout << "Not found.\n";
}

#endif //CLASSROOMBOOKINGSYSTEM_VIEWS_H
