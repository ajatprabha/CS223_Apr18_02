//
// Created by ajatprabha on 1/4/18.
//

#include <users/models/Admin.h>
#include <users/models/Professor.h>
#include <init/Application.h>
#include "UserCreateUpdateForm.h"

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
        int id = instance->getId();
        instance->remove();
        temp->setId(id);
    }
    temp->save();
    if (loginUser) Application::getInstance().login(temp->getEmail(), password);
    return *temp;
}
