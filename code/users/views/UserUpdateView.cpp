//
// Created by ajatprabha on 1/4/18.
//

#include <admin/forms/UserCreateUpdateForm.h>
#include <base/controller.h>
#include <init/Application.h>
#include <base/utils/Input.h>
#include "UserUpdateView.h"

void UserUpdateView::display() {
    BaseUser loggedInUser = *Application::getInstance().getCurrentUser();
    cout << "To update a user fill in the details asked below: \n";
    string email, firstName, lastName, password;
    bool adminStatus;
    if (loggedInUser.isAdmin()) {
        cout << "Email: ";
        email = Input::getEmail();
    } else {
        email = loggedInUser.getEmail();
    }
    cout << "First name: ";
    firstName = Input::getString();
    cout << "Last name: ";
    lastName = Input::getString();
    cout << "Password: ";
    password = Input::getPassword();
    if (loggedInUser.isAdmin()) {
        cout << "Should this user be an admin? (y/n): ";
        adminStatus = (Input::getChar() == 'y');
    } else adminStatus = false;
    BaseUser *user = BaseUser::findByEmail(email);
    if (user) {
        form = new UserCreateUpdateForm(firstName, lastName, email, password, adminStatus, user);
        if (form->isValid()) {
            user = &form->save();
            cout << "User " + user->getFullName() + " updated successfully.\n";
        } else {
            form->printErrors();
        }
    } else {
        cout << "A user with " + email + " email address doesn't exist.\n";
    }
    response->view = loggedInUser.isAdmin() ? Controller::getInstance().getView("admin-panel")
                                            : Controller::getInstance().getView("faculty-panel");
}
