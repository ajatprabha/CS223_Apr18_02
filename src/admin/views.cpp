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
    response->view = Controller::getInstance().getView("delete-room");
}

void AdminPanelView::roomDetails() {
    response->view = Controller::getInstance().getView("room-details");
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
