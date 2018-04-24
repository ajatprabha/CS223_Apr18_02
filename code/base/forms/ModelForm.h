//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_MODELFORM_H
#define CLASSROOMBOOKINGSYSTEM_MODELFORM_H

#include "Form.h"

template<class T>
class ModelForm : public Form {
protected:
    T *instance = nullptr;
public:
    virtual T &save() = 0;
};

#endif //CLASSROOMBOOKINGSYSTEM_MODELFORM_H
