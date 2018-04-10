//
// Created by ajatprabha on 12/3/18.
//

#include "../init.h"
#include "views.h"

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
    Application::saveData();
    response->view = nullptr;
}

int Input::getInt() {
    int number;
    cin >> number;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter a valid number!\n";
        cin >> number;
    }
    return number;
}
