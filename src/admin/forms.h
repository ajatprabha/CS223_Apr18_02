//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMIN_FORMS_H
#define CLASSROOMBOOKINGSYSTEM_ADMIN_FORMS_H


#include "../base/forms.h"

class UserCreateUpdateForm : public ModelForm<BaseUser> {
    string firstName, lastName, email, password;
    bool adminStatus;
public:
    UserCreateUpdateForm(const string &passedFirstName, const string &passedLastName,
                   const string &passedEmail, const string &passedPassword, bool passedAdmin,
                   BaseUser *passedInstance = nullptr);

    void clean() override;

    BaseUser &save() override;
};

class RoomCreateUpdateForm : public ModelForm<Room> {
    int roomNumber, strength;
    bool audio, video;
    Room *room;
public:

    RoomCreateUpdateForm(int roomNumber, int strength, bool audio, bool video, Room *passedInstance = nullptr);

    void clean() override;

    Room &save() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_FORMS_H
