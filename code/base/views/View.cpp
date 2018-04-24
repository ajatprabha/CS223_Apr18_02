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

void View::populateMenu() {
    cout << title << endl;
    for (int i = 0; i < menuOptions.size(); ++i) {
        cout << i + 1 << ". " << menuOptions[i] << endl;
    }
}

View::View(const string &passedTitle, const vector<string> &passedVector, const vector<View *> &passedActions) {
    title = passedTitle;
    menuOptions = passedVector;
    menuChoices = passedActions;
}

void View::callView(int menuPosition) {
    if (menuPosition >= menuChoices.size()) {
        response->view = this;
        cout << "Invalid choice, try again!\n";
    } else response->view = menuChoices[menuPosition];
}
