//
// Created by ajatprabha on 1/4/18.
//

#include <admin/forms/UserCreateUpdateForm.h>
#include <base/controller.h>
#include "UserUpdateView.h"

void UserUpdateView::display() {
    cout << "To update a user fill in the details asked below: \n";
    string email, firstName, lastName, password;
    char adminStatus;
    cout << "Enter the email of user:\n";
    cin >> email;
    cout << "Enter first name, last name and password respectively.\n";
    cin >> firstName >> lastName >> password;
    cout << "Should this user be an admin? (y/n)\n";
    cin >> adminStatus;
    BaseUser *user = BaseUser::findByEmail(email);
    if (user) {
        form = new UserCreateUpdateForm(firstName, lastName, email, password, adminStatus == 'y', user);
        if (form->isValid()) {
            user = &form->save();
            cout << "User " + user->getFullName() + " updated successfully.\n";
        } else {
            form->printErrors();
        }
    } else {
        cout << "A user with " + email + " email address doesn't exist.\n";
    }
    response->view = Controller::getInstance().getView("admin-panel");
}
