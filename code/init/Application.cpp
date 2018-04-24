//
// Created by ajatprabha on 12/3/18.
//

#include <init/views/SplashView.h>
#include <users/models/Admin.h>
#include <users/views/LoginView.h>
#include <users/views/LogoutView.h>
#include <users/views/UserCreateView.h>
#include <users/views/UserUpdateView.h>
#include <users/views/UserDeleteView.h>
#include <admin/views/AdminPanelView.h>
#include <admin/views/AdminDetailView.h>
#include <admin/views/RoomCreateView.h>
#include <admin/views/RoomUpdateView.h>
#include <admin/views/RoomDetailView.h>
#include <admin/views/RoomDeleteView.h>
#include <admin/views/UnseenSlotRequestListView.h>
#include <booking/views/FacultyPanelView.h>
#include <booking/views/SlotCreateView.h>
#include <booking/views/SlotUpdateView.h>
#include <booking/views/SlotDeleteView.h>
#include <booking/views/SlotNotificationListView.h>
#include <booking/views/EmptyRoomListView.h>
#include <base/views/ExitView.h>
#include "Application.h"

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
    //Admin("Saksham", "Banga", "banga.1@iitj.ac.in", "password").save();
    view = controller.getView("splash");
    while (view) {
        Context tmp(user, -1);
        view = view->call(tmp).view;
        cout << "=========================================================\n\n";
    }
    saveData();
}

bool Application::login(const string &_email, const string &_password) {
    BaseUser *temp = BaseUser::findByEmail(_email);
    if (temp) {
        if (temp->checkPassword(_password)) {
            user = temp;
            return true;
        }
    }
    return false;
}

void Application::loadViewPatterns() {
    controller.addViewPattern("exit", new ExitView);
    controller.addViewPattern("login", new LoginView);
    controller.addViewPattern("splash", new SplashView);
    controller.addViewPattern("logout", new LogoutView);
    controller.addViewPattern("create-user", new UserCreateView);
    controller.addViewPattern("update-user", new UserUpdateView);
    controller.addViewPattern("delete-user", new UserDeleteView);
//    controller.addViewPattern("admin-detail", new AdminDetailView);
    controller.addViewPattern("create-room", new RoomCreateView);
    controller.addViewPattern("update-room", new RoomUpdateView);
    controller.addViewPattern("room-details", new RoomDetailView);
    controller.addViewPattern("delete-room", new RoomDeleteView);
    controller.addViewPattern("admin-unseen-slot-list", new UnseenSlotRequestListView);
    controller.addViewPattern("create-slot", new SlotCreateView);
    controller.addViewPattern("update-slot", new SlotUpdateView);
    controller.addViewPattern("delete-slot", new SlotDeleteView);
    controller.addViewPattern("slot-notification-list", new SlotNotificationListView);
    controller.addViewPattern("empty-rooms-list", new EmptyRoomListView);
    controller.addViewPattern("admin-panel", new AdminPanelView);
    controller.addViewPattern("faculty-panel", new FacultyPanelView);
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