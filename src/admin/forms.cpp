//
// Created by ajatprabha on 1/4/18.
//

#include "forms.h"

UserCreateForm::UserCreateForm(const string &passedFirstName, const string &passedLastName, const string &passedEmail,
                                 const string &passedPassword, bool passedAdmin) {
    firstName = passedFirstName;
    lastName = passedLastName;
    email = passedEmail;
    password = passedPassword;
    adminStatus = passedAdmin;
}

void UserCreateForm::clean() {
    if (firstName.empty() || firstName.size() > 32) addError("invalid first name length");
    if (lastName.empty() || lastName.size() > 64) addError("invalid last name length");
    if (email.empty() || email.size() > 64) addError("invalid first name length");
    for (auto &it : BaseUser::all()) {
        if (it.second.getEmail() == email) addError("A user with this email already exists");
    }
    if (password.empty() || password.size() > 64) addError("invalid password length");
}

BaseUser &UserCreateForm::save() {
    BaseUser *temp;
    if (adminStatus) {
        temp = new Admin(firstName, lastName, email, password);
    } else {
        temp = new Professor(firstName, lastName, email, password);
    }
    temp->save();
    return *temp;
}
