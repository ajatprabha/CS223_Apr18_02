//
// Created by saksham on 3/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_DATETIME_H
#define CLASSROOMBOOKINGSYSTEM_DATETIME_H

#include <iostream>
#include "Input.h"

using namespace std;

class DateTime {
public:
    DateTime() = default;

    DateTime(int date, int month, int year, int hour, int minute, int second, char meridy);

    int date{};
    int month{};
    int year{};
    int hour{};
    int minute{};
    int second{};
    char meridy = 'A';
    long long value{};

    string getTimestamp() const;

    void inputValidate();

    bool operator<(const DateTime &rhs) const;

    bool operator>(const DateTime &rhs) const;

    bool operator<=(const DateTime &rhs) const;

    bool operator>=(const DateTime &rhs) const;

};


#endif //CLASSROOMBOOKINGSYSTEM_DATETIME_H
