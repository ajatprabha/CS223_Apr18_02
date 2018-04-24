//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_FORM_H
#define CLASSROOMBOOKINGSYSTEM_FORM_H

#include <vector>
#include <iostream>

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

#endif //CLASSROOMBOOKINGSYSTEM_FORM_H
