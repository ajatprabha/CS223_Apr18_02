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
    const vector<string> &getErrors() const;

    bool isValid();

    void addError(const string &error);

    virtual void clean() = 0;

    void printErrors();
};

template<class T>
class ModelForm : public Form {
protected:
    T *instance = nullptr;
public:
    virtual T &save() = 0;
};

#endif //CLASSROOMBOOKINGSYSTEM_FORMS_H
