//
// Created by ajatprabha on 12/3/18.
//

#include "View.h"

Response *View::response = nullptr;

Response View::call(const Context &contextPassed) {
    response = new Response;
    context = contextPassed;
    display();
    return *response;
}

Context::Context(BaseUser *passedUser, int passedRequestObjectId) {
    user = passedUser;
    requestObjectId = passedRequestObjectId;
}

void View::populateMenu() {
    cout << title << endl;
    for (int i = 0; i < menuOptions.size(); ++i) {
        cout << i + 1 << ". " << menuOptions[i] << endl;
    }
}

View::View(const string &passedTitle, const vector<string> &passedVector, const vector<FnPtr> &passedActions) {
    title = passedTitle;
    menuOptions = passedVector;
    menuActions = passedActions;
}

void View::callAction(int menuPosition) {
    if (menuPosition >= menuActions.size()) {
        response->view = this;
        cout << "Invalid choice, try again!\n";
    } else menuActions[menuPosition]();
}

void View::exit() {
    response->view = nullptr;
}
