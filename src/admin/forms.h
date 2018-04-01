//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMIN_FORMS_H
#define CLASSROOMBOOKINGSYSTEM_ADMIN_FORMS_H


#include "../base/forms.h"

class AdminCreateForm : public ModelForm<BaseUser> {
    string firstName, lastName, email, password;
public:
    AdminCreateForm(const string &passedFirstName, const string &passedLastName, const string &passedEmail,
                    const string &passedPassword);

    void clean() override;

    BaseUser &save() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_FORMS_H
