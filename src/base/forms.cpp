//
// Created by ajatprabha on 1/4/18.
//

#include "forms.h"

vector<string> Form::getErrors() {
    return errors;
}

bool Form::isValid() {
    clean();
    return errors.empty();
}

void Form::addError(const string &error) {
    errors.push_back(error);
}

void Form::printErrors() {
    for (auto &error : getErrors()) {
        cout << error << endl;
    }
}
