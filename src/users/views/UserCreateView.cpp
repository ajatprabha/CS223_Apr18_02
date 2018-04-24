//
// Created by ajatprabha on 1/4/18.
//

#include <admin/forms/UserCreateUpdateForm.h>
#include <base/controller.h>
#include <base/utils/Input.h>
#include "UserCreateView.h"

void UserCreateView::display() {
    cout << "To create a new user fill in the details asked below: \n";
    string firstName, lastName, email, password;
    bool adminStatus;
    cout << "First name: ";
    firstName = Input::getString();
    cout << "Last name: ";
    lastName = Input::getString();
    cout << "Email: ";
    email = Input::getEmail();
    cout << "Password: ";
    password = Input::getPassword();
    cout << "Should this user be an admin? (y/n): ";
    adminStatus = (Input::getChar() == 'y');
    form = new UserCreateUpdateForm(firstName, lastName, email, password, adminStatus);
    if (form->isValid()) {
        BaseUser user = form->save();
        cout << "New user, " + user.getFullName() + " saved successfully.\n";
    } else {
        form->printErrors();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}