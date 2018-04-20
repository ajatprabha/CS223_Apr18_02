//
// Created by ajatprabha on 1/4/18.
//

#include <base/utils/Input.h>
#include <booking/models/Room.h>
#include <booking/models/Slot.h>
#include <init/Application.h>
#include "AdminPanelView.h"
#include "DeleteUserView.h"

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
        if (Application::getInstance().getCurrentUser()->getEmail() == email)
            cout << "You cannot delete yourself!" << endl;
        else
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

void AdminPanelView::listUnseenSlots() {
    response->view = Controller::getInstance().getView("admin-unseen-slot-list");
}

void AdminPanelView::createRoom() {
    response->view = Controller::getInstance().getView("create-room");
}

void AdminPanelView::updateRoom() {
    response->view = Controller::getInstance().getView("update-room");
}

void AdminPanelView::deleteRoom() {
    cout << "Enter the Room number to be deleted:\n. Note that all slots with the room number entered will also be deleted so be careful ";
    int id = Input::getInt();
    Room *room = Room::findByRoomNumber(id);
    if (!room) {
        cout << "No room with this number exists.\n";
    } else {

        DeleteView<Room>().call({Application::getInstance().getCurrentUser(), room->getId()});
        for(auto &it :Slot::all())
        {
            if(it.second.getRoom().getRoomNumber()==room->getRoomNumber())
                DeleteView<Slot>().call({Application::getInstance().getCurrentUser(), it.second.getId()});
        }
    }
    response->view = Controller::getInstance().getView("admin-panel");
}

void AdminPanelView::roomDetails() {
    response->view = Controller::getInstance().getView("room-details");
}

void AdminPanelView::callLogoutView() {
    response->view = Controller::getInstance().getView("logout");
}
