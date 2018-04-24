//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_INPUT_H
#define CLASSROOMBOOKINGSYSTEM_INPUT_H

#include <iostream>
#include <regex>

using namespace std;

class Input {
public:
    static int getInt();

    static char getChar();

    static string getEmail();

    static string getPassword();

    static string regexInputValidate(const regex& regEx, const string &errorMessage);
};


#endif //CLASSROOMBOOKINGSYSTEM_INPUT_H
