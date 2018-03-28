//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_VIEWS_H

#include <iostream>
#include "models.h"
#include "exceptions.h"
#include <users/models.h>

using namespace std;


struct Context {
    BaseUser user;
};

struct Response;


class View {
private:
    Context context;
public:
    virtual void display();
    virtual Response call(const Context&);
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
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEWS_H
