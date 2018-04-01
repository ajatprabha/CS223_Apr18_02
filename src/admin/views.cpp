//
// Created by ajatprabha on 1/4/18.
//

#include "views.h"

void AdminDetailView::display() {
    cout << "Admin detail view called\n";
    response->view = nullptr;
}

void AdminPanelView::display() {
    populateMenu();
    int choice;
    cin >> choice;
    callAction(choice - 1);
}

void AdminPanelView::deleteUser() {
    cout << "Enter the ID of user to delete:\n";
    int id;
    cin >> id;
    AdminDeleteView().call({*Application::getInstance().getCurrentUser(), id});
    response->view = Controller::getInstance().getView("admin-panel");
}

void AdminPanelView::createAdmin() {
    response->view = Controller::getInstance().getView("admin-create");
}

void AdminDeleteView::display() {
    DeleteView::display();
}

Context::Context(const BaseUser &passedUser, int passedRequestObjectId) {
    user = passedUser;
    requestObjectId = passedRequestObjectId;
}

void AdminCreateView::display() {
    cout << "To create a new admin fill in the details asked below: \n";
    string firstName, lastName, email, password;
    cout << "Enter first name, last name, email and password respectively.\n";
    cin >> firstName >> lastName >> email >> password;
    form = new AdminCreateForm(firstName, lastName, email, password);
    if (form->isValid()) {
        BaseUser user = form->save();
        cout << "New admin saved successfully.\n";
    } else {
        form->printErrors();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}