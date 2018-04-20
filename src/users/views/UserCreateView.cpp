//
// Created by ajatprabha on 1/4/18.
//

#include <admin/forms/UserCreateUpdateForm.h>
#include <base/controller.h>
#include "UserCreateView.h"

void UserCreateView::display() {
    cout << "To create a new user fill in the details asked below: \n";
    string firstName, lastName, email, password;
    char adminStatus;
    cout << "Enter first name, last name, email and password respectively.\n";
    cin >> firstName >> lastName >> email >> password;
    cout << "Should this user be an admin? (y/n)\n";
    cin >> adminStatus;
    form = new UserCreateUpdateForm(firstName, lastName, email, password, adminStatus == 'y');
    if (form->isValid()) {
        BaseUser user = form->save();
        cout << "New user, " + user.getFullName() + " saved successfully.\n";
    } else {
        form->printErrors();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}