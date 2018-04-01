//
// Created by ajatprabha on 1/4/18.
//

#include "views.h"


void LoginView::display() {
    populateMenu();
    string email, password;
    cout << "Enter your email and password\n";
    cin >> email >> password;
    Controller controller = Controller::getInstance();
    Application appInstance = Application::getInstance();
    if (appInstance.login(email, password)) {
        if (appInstance.getCurrentUser()->isAdmin()) {
            response->view = controller.getView("admin-panel");
        }
    } else {
        response->view = controller.getView("splash");
        cout << "Invalid credentials\n";
    }
}

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
    form = new UserCreateUpdateForm(firstName, lastName, email, password, adminStatus == 'y',
                                    BaseUser::findByEmail(email));
    if (form->isValid()) {
        BaseUser user = form->save();
        cout << "User " + user.getFullName() + " updated successfully.\n";
    } else {
        form->printErrors();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}
