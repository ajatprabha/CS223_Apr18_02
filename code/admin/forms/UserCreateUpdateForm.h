//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_USERCREATEUPDATEFORM_H
#define CLASSROOMBOOKINGSYSTEM_USERCREATEUPDATEFORM_H

#include <base/forms/ModelForm.h>
#include <base/models/BaseUser.h>

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


#endif //CLASSROOMBOOKINGSYSTEM_USERCREATEUPDATEFORM_H
