//
// Created by ajatprabha on 1/4/18.
//


#include <limits>
#include "Input.h"

long long Input::getInt() {
    regex intRegex("[0-9]{1,15}");
    return stoll(regexInputValidate(intRegex, "Enter a valid number!"));
}

string Input::getEmail() {
    regex emailRegex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return regexInputValidate(emailRegex, "Enter a valid email!");
}

string Input::regexInputValidate(const regex &regEx, const string &errorMessage) {
    string input;
    cin.getline(input);
    while (!regex_match(input, regEx)) {
        cout << errorMessage << endl;
        cin.getline(input);
    }
    return input;
}
