//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_CREATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_CREATEVIEW_H

#include <base/forms/ModelForm.h>
#include "View.h"

template<class T>
class CreateView : public View {
protected:
    ModelForm<T> *form;
public:
    void display() override = 0;
};


#endif //CLASSROOMBOOKINGSYSTEM_CREATEVIEW_H
