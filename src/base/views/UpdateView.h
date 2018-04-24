//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_UPDATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_UPDATEVIEW_H


#include <base/forms/ModelForm.h>
#include <base/mixins/SingleObjectMixin.h>
#include "View.h"

template<class T>
class UpdateView : public SingleObjectMixin<T>, public View {
protected:
    ModelForm<T> *form;
public:
    void display() override = 0;
};


#endif //CLASSROOMBOOKINGSYSTEM_UPDATEVIEW_H
