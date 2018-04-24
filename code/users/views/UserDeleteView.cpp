//
// Created by ajatprabha on 1/4/18.
//

#include <init/Application.h>
#include <base/utils/Input.h>
#include "UserDeleteView.h"

void UserDeleteView::display() {
    cout << "Enter the email of user to delete: ";
    string email;
    email = Input::getEmail();
    BaseUser *user = BaseUser::findByEmail(email);
    if (!user) {
        cout << "No user with this email exists.\n";
    }
    else if (Application::getInstance().getCurrentUser()->getEmail() == email)
        cout << "You cannot delete yourself!" << endl;
    else {
        context.requestObjectId = user->getId();
        DeleteView::display();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}
