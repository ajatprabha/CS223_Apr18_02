//
// Created by ajatprabha on 1/4/18.
//

#include "Input.h"

int Input::getInt() {
    int number;
    cin >> number;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid number!\n";
        cin >> number;
    }
    return number;
}