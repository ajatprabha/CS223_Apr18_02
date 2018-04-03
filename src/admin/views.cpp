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


void DeleteUserView::display() {
    DeleteView::display();
}



Context::Context(BaseUser *passedUser, int passedRequestObjectId) {
    user = passedUser;
    requestObjectId = passedRequestObjectId;
}

vector<Slot> UnseenSlotRequestListView::getQueryset() {
    vector<Slot> objects{};
    for (auto &i : objectList) {
        if (i.second.getApproved() == 0) objects.push_back(i.second);
    }
    return objects;
}

void UnseenSlotRequestListView::display() {
    cout << "Following are the unsen slot requests.\nSelect slot ID to approve/deny\n";
    for (auto &slot: getQueryset()) {
        cout << slot.getId() << ". " << slot.getRequestedBy().getFullName() << " Time: "
             << slot.getStartTime().getTimestamp();
    }
    Slot *slot = Slot::findById(Input::getInt());
    if (slot) {
        cout << "Enter 1 to approve, 2 to deny\n";
        int approval = Input::getInt();
        slot->setApproved(approval);
        slot->save();
    } else cout << "Invalid slot selection\n";
    response->view = Controller::getInstance().getView("admin-panel");
}

void RoomCreateView::display() {
    cout << "To create a room fill in the details asked below: \n";
    int roomNumber, strength;
    bool audio, video;
    char choice;
    cout << "Enter room number, strength, audio(y/n) and video(y/n) respectively.\n";
    roomNumber = Input::getInt();
    strength = Input::getInt();
    cin >> choice;
    audio = (choice == 'y');
    cin >> choice;
    video = (choice == 'y');
    form = new RoomCreateUpdateForm(roomNumber, strength, audio, video);
    if (form->isValid()) {
        Room room = form->save();
        cout << "Room #" + to_string(room.getRoomNumber()) + " created successfully.\n";
    } else {
        form->printErrors();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}

void RoomUpdateView::display() {
    cout << "To update a room fill in the details asked below: \n";
    int roomNumber, strength;
    bool audio, video;
    char choice;
    cout << "Enter the room number:\n";
    roomNumber = Input::getInt();
    cout << "Enter new strength, audio(y/n) and video(y/n) capabilities respectively.\n";
    strength = Input::getInt();
    cin >> choice;
    audio = (choice == 'y');
    cin >> choice;
    video = (choice == 'y');
    Room *room = Room::findByRoomNumber(roomNumber);
    if (room) {
        form = new RoomCreateUpdateForm(roomNumber, strength, audio, video, room);
        if (form->isValid()) {
            room = &form->save();
            cout << "Room #" + to_string(room->getRoomNumber()) + " updated successfully.\n";
        } else {
            form->printErrors();
        }
    } else {
        cout << "The room #" << roomNumber << " doesn't exist.\n";
    }
    response->view = Controller::getInstance().getView("admin-panel");
}

void RoomDetailView::display() {
    cout << "Enter room number to get details for: \n";
    int roomNumber = Input::getInt();
    Room *room = Room::findByRoomNumber(roomNumber);
    if (room) {
        cout << "Details for room #" << room->getRoomNumber() << "\n\tStrength: " << room->getStrength()
             << "\n\tAudio: ";
        if (room->hasVideo()) cout << "Yes"; else cout << "No";
        cout << "\n\tVideo: ";
        if (room->hasVideo()) cout << "Yes"; else cout << "No";
        cout << endl;
    } else {
        cout << "Room #" << roomNumber << " doesn't exist.\n";
    }
    response->view = Controller::getInstance().getView("admin-panel");
}

