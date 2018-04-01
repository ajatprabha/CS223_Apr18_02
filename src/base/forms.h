//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_FORMS_H
#define CLASSROOMBOOKINGSYSTEM_FORMS_H

#include <iostream>
#include <vector>
#include <string>
#include "../users/models.h"
#include "models.h"

using namespace std;

class Form {
private:
    vector<string> errors;
public:
    bool isValid();

    vector<string> getErrors();

    void addError(const string &error);

    virtual void clean() = 0;

    void printErrors();
};

template<class T>
class ModelForm : public Form {
public:
    virtual T &save() = 0;
};

#endif //CLASSROOMBOOKINGSYSTEM_FORMS_H
