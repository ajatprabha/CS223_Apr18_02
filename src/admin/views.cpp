//
// Created by ajatprabha on 1/4/18.
//

#include "views.h"

void AdminDetailView::display() {
    cout << "Admin detail view called\n";
    response->view = nullptr;
}

void AdminPanelView::display() {
    cout << "Admin: " << context.user->getFullName() << endl;
    populateMenu();
    callAction(Input::getInt() - 1);
}

void AdminPanelView::deleteUser() {
    cout << "Enter the ID of user to delete:\n";
    AdminDeleteView().call({Application::getInstance().getCurrentUser(), Input::getInt()});
    response->view = Controller::getInstance().getView("admin-panel");
}

void AdminPanelView::createUser() {
    response->view = Controller::getInstance().getView("create-user");
}

void AdminDeleteView::display() {
    DeleteView::display();
}

Context::Context(BaseUser *passedUser, int passedRequestObjectId) {
    user = passedUser;
    requestObjectId = passedRequestObjectId;
}