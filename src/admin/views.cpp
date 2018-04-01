//
// Created by ajatprabha on 1/4/18.
//

#include "views.h"

void AdminDetailView::display() {
    cout << "Admin detail view called\n";
    response->view = nullptr;
}

void AdminPanelView::display() {
    cout << "Admin: " << Application::getInstance().getCurrentUser()->getFullName() << endl;
    populateMenu();
    callAction(Input::getInt() - 1);
}

void AdminPanelView::deleteUser() {
    cout << "Enter the email of user to delete:\n";
    string email;
    cin >> email;
    BaseUser *user = BaseUser::findByEmail(email);
    if (!user) {
        cout << "No user with this email exists.\n";
    } else {
        DeleteUserView().call({Application::getInstance().getCurrentUser(), user->getId()});
    }
    response->view = Controller::getInstance().getView("admin-panel");
}

void AdminPanelView::createUser() {
    response->view = Controller::getInstance().getView("create-user");
}

void AdminPanelView::updateUser() {
    response->view = Controller::getInstance().getView("update-user");
}

void DeleteUserView::display() {
    DeleteView::display();
}

Context::Context(BaseUser *passedUser, int passedRequestObjectId) {
    user = passedUser;
    requestObjectId = passedRequestObjectId;
}