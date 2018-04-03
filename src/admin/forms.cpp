//
// Created by ajatprabha on 1/4/18.
//

#include <init.h>
#include "forms.h"

UserCreateUpdateForm::UserCreateUpdateForm(const string &passedFirstName, const string &passedLastName,
                                           const string &passedEmail, const string &passedPassword, bool passedAdmin,
                                           BaseUser *passedInstance) {
    firstName = passedFirstName;
    lastName = passedLastName;
    email = passedEmail;
    password = passedPassword;
    adminStatus = passedAdmin;
    instance = passedInstance;
}

void UserCreateUpdateForm::clean() {
    if (firstName.empty() || firstName.size() > 32) addError("invalid first name length");
    if (lastName.empty() || lastName.size() > 64) addError("invalid last name length");
    if (email.empty() || email.size() > 64) addError("invalid first name length");
    for (auto &it : BaseUser::all()) {
        if (it.second.getEmail() == email && !instance) addError("A user with this email already exists");
    }
    if (password.empty() || password.size() > 64) addError("invalid password length");
}

BaseUser &UserCreateUpdateForm::save() {
    BaseUser *temp;
    bool loginUser = false;
    int id;
    if (adminStatus) {
        temp = new Admin(firstName, lastName, email, password);
    } else {
        temp = new Professor(firstName, lastName, email, password);
    }
    if (instance) {
        if (instance == Application::getInstance().getCurrentUser()) {
            loginUser = true;
            Application::getInstance().logout();
        }
        id = instance->getId();
        instance->remove();
        temp->setId(id);
    }
    temp->save();
    if (loginUser) Application::getInstance().login(temp->getEmail(), password);
    return *temp;
}

RoomCreateUpdateForm::RoomCreateUpdateForm(int roomNumber, int strength, bool audio, bool video, Room *passedInstance)
        : roomNumber(roomNumber), strength(strength), audio(audio), video(video) {
    instance = passedInstance;
}

void RoomCreateUpdateForm::clean() {
    if(!room) {
        for (auto &i :Room::all()) {
            if (i.second.getRoomNumber() == roomNumber) addError("A room with this room number already exists.");
        }
    }
}

Room &RoomCreateUpdateForm::save() {
    Room *temp;
    int id;
    temp = new Room(roomNumber, strength, audio, video);
    if (instance) {
        id = instance->getId();
        instance->remove();
        temp->setId(id);
    }
    temp->save();
    return *temp;
}
