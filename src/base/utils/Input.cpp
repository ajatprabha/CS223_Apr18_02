//
// Created by ajatprabha on 1/4/18.
//


#include <limits>
#include "Input.h"

long long Input::getInt() {
    regex intRegex("[0-9]{1,15}");      // accepts a number input between 1-15 length
    return stoll(regexInputValidate(intRegex, "Enter a valid number!"));
}

string Input::getEmail() {
    regex emailRegex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");       // accepts only a valid email address
    return regexInputValidate(emailRegex, "Enter a valid email!");
}

string Input::regexInputValidate(const regex &regEx, const string &errorMessage) {
    string input;
    cin.clear();
    getline(cin,input);
    while (!regex_match(input, regEx)) {
        cout << errorMessage << endl;
        getline(cin,input);
    }
    cin.clear();
    return input;
}

string Input::getPassword() {
    regex passwordRegex("^[^-\\s][a-zA-Z0-9_\\s-]+$");      // rejects strings starting with spaces, containing only spaces or empty strings
    return regexInputValidate(passwordRegex, "Invalid input!");
}
