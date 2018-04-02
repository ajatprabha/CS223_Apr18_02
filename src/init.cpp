//
// Created by ajatprabha on 12/3/18.
//

#include <booking/models.h>
#include <booking/views.h>
#include "init.h"

Application *Application::instance = nullptr;
BaseUser *Application::user = nullptr;
View *Application::view = nullptr;

Application &Application::getInstance() {
    if (!Application::instance) {
        Application::instance = new Application();
    }
    return *Application::instance;
}

void Application::start() {
    // Initialise all the static properties
    readData();
    loadViewPatterns();
    Admin("Admin", "user", "admin@iitj.ac.in", "admin@123").save();     // creates a permanent admin
    this->view = controller.getView("splash");
    while (this->view) {
        Context tmp(this->user, -1);
        Response response = this->view->call(tmp);
        this->view = response.view;
        cout << "=========================================================\n\n";
    }
}

bool Application::login(const string &_email, const string &_password) {
    BaseUser *temp = BaseUser::findByEmail(_email);
    if (temp) {
        if (temp->checkPassword(_password)) {
            this->user = temp;
            return true;
        }
    } else return false;
}

void Application::loadViewPatterns() {
    controller.addViewPattern("splash", new SplashView);
    controller.addViewPattern("login", new LoginView);
    controller.addViewPattern("create-user", new UserCreateView);
    controller.addViewPattern("update-user", new UserUpdateView);
    controller.addViewPattern("admin-panel", new AdminPanelView);
    controller.addViewPattern("admin-detail", new AdminDetailView);
    controller.addViewPattern("admin-delete", new DeleteUserView);
    controller.addViewPattern("create-room", new RoomCreateView);
    controller.addViewPattern("admin-unseen-slot-list", new UnseenSlotRequestListView);
    controller.addViewPattern("faculty-panel", new FacultyPanelView);
    controller.addViewPattern("slot-notification-list", new SlotNotificationListView);
    controller.addViewPattern("empty-rooms-list", new EmptyRoomListView);
}

BaseUser *Application::getCurrentUser() {
    return user;
}

void Application::saveData() {
    BaseUser::writeToFile("BaseUser.dat");
    Professor::writeToFile("Professor.dat");
    Admin::writeToFile("Admin.dat");
    Room::writeToFile("Room.dat");
    Slot::writeToFile("Slot.dat");
}

void Application::readData() {
    BaseUser::readFromFile("BaseUser.dat");
    Professor::readFromFile("Professor.dat");
    Admin::readFromFile("Admin.dat");
    Room::readFromFile("Room.dat");
    Slot::readFromFile("Slot.dat");
}

void Application::logout() {
    user = nullptr;
}

void SplashView::display() {
    populateMenu();
    callAction(Input::getInt() - 1);
}

void SplashView::callLoginView() {
    response->view = Controller::getInstance().getView("login");
}