//
// Created by ajatprabha on 12/3/18.
//

#include <init.h>
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
    menuActions[menuPosition]();
}

void View::exit() {
    response->view = nullptr;
}

template<class T>
void DeleteView<T>::display() {
    T *object = SingleObjectMixin<T>::getObject(context.requestObjectId);
    if (object) {
        object->remove();
    }
    cout << "Successfully deleted.\n";
}

void SplashView::display() {
    populateMenu();
    int choice;
    cin >> choice;
    callAction(choice - 1);
}

void SplashView::callLoginView() {
    response->view = Controller::getInstance().getView("login");
}

void LoginView::display() {
    populateMenu();
    string email, password;
    cout << "Enter your email and password\n";
    cin >> email >> password;
    Application appInstance = Application::getInstance();
    if (appInstance.login(email, password)) {
        Controller controller = Controller::getInstance();
        if (appInstance.getCurrentUser()->isAdmin()) {
            response->view = controller.getView("admin-panel");
        }
    } else {
        response->view = nullptr;
        cout << "Invalid credentials\n";
    }
}

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
        for (auto &error : form->getErrors()) {
            cout << error << endl;
        }
    }
    response->view = Controller::getInstance().getView("admin-panel");
}
