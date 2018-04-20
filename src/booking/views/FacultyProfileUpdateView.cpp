//
// Created by ajatprabha on 1/4/18.
//

#include <admin/forms/UserCreateUpdateForm.h>
#include <init/Application.h>
#include "FacultyProfileUpdateView.h"

void FacultyProfileUpdateView::display() {
    cout << "Fill in the details asked below: \n";
    string firstName, lastName, password;
    string email = Application::getInstance().getCurrentUser()->getEmail();
    cout << "Enter first name, last name and password respectively.\n";
    cin >> firstName >> lastName >> password;
    BaseUser *user = BaseUser::findByEmail(email);
    if (user) {
        form = new UserCreateUpdateForm(firstName, lastName, email, password, false, user);
        if (form->isValid()) {
            user = &form->save();
            cout << "User " + user->getFullName() + " updated successfully.\n";
        } else {
            form->printErrors();
        }
    } else {
        cout << "A user with " + email + " email address doesn't exist.\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}
