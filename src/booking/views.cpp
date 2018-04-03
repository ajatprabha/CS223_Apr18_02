//
// Created by ajatprabha on 1/4/18.
//

#include "views.h"
#include "forms.h"

void FacultyPanelView::display() {
    cout << "Professor: " << Application::getInstance().getCurrentUser()->getFullName() << endl;
    populateMenu();
    callAction(Input::getInt() - 1);
}

void FacultyPanelView::bookSlot() {
    response->view = Controller::getInstance().getView("create-slot");
}

void FacultyPanelView::listSlotStatus() {
    response->view = Controller::getInstance().getView("slot-notification-list");
}

void FacultyPanelView::updateUser() {
    response->view = Controller::getInstance().getView("slot-notification-list");
}

void FacultyPanelView::updateSlot() {
    response->view = Controller::getInstance().getView("update-slot");
}

void FacultyPanelView::deleteSlot() {
    cout << "Enter the slot id to be deleted:\n";
    int id = Input::getInt();
    Slot *slot = Slot::findById(id);
    if (!slot) {
        cout << "No slot with this id exists.\n";
    } else DeleteView<Slot>().call({Application::getInstance().getCurrentUser(), slot->getId()});
    response->view = Controller::getInstance().getView("faculty-panel");
}

void FacultyPanelView::listEmptyRooms() {
    response->view = Controller::getInstance().getView("empty-rooms-list");
}

void FacultyPanelView::callLogoutView() {
    response->view = Controller::getInstance().getView("logout");
}

vector<Slot> SlotNotificationListView::getQueryset() {
    vector<Slot> objects;
    for (auto &i : objectList) {
        if (i.second.getRequestedBy() == static_cast<Professor &>(*context.user)) objects.push_back(i.second);
    }
    return objects;
}

void SlotNotificationListView::display() {
    for (auto &slot : getQueryset()) {
        cout << slot.getId() << ". " << slot.getRoom().getRoomNumber() << " "<< slot.getStartTime().getTimestamp()<<" "<< slot.getEndTime().getTimestamp()<< "\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}

void EmptyRoomListView::display() {
    getParams();
    for (auto &room : getQueryset()) {
        cout << "Room #" << room.getRoomNumber() << ", ID: " << room.getId() << "\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}

vector<Room> EmptyRoomListView::getQueryset() {
    vector<Room> objects;
    map<int, bool> roomFlags;
    if (params.start < params.end) {
        for (auto &i :Room::all()) {
            roomFlags[i.second.getRoomNumber()] = true;
        }
        for (auto &i : Slot::all()) {
            if (!(i.second.getApproved() && roomFlags[i.second.getRoom().getRoomNumber()] &&
                  params.strength <= i.second.getRoom().getStrength() &&
                  ((params.audio && i.second.getRoom().hasAudio()) || !params.audio) &&
                  ((params.video && i.second.getRoom().hasVideo()) || !params.video)&&(i.second.getStartTime() >= params.end||i.second.getEndTime() <= params.start))) {
                roomFlags[i.second.getRoom().getRoomNumber()] = false;
            }
        }
        for (auto &i : roomFlags) {
            if (i.second) objects.push_back(*Room::findByRoomNumber(i.first));
        }
    }
    return objects;
}

void EmptyRoomListView::getParams() {
    cout << "Start time: ";
    params.start.inputValidate();
    cout << "End time: ";
    params.end.inputValidate();
    cout << "Enter the room strength:\n";
    params.strength = Input::getInt();
    cout << "Audio-Video required (enter y/n respectively)\n";
    char choice;
    cin >> choice;
    params.audio = (choice == 'y');
    cin >> choice;
    params.video = (choice == 'y');
}

void SlotCreateView::display() {
    cout << "To create a slot request fill in the details asked below: \n";
    Professor *requestedBy = &static_cast<Professor &> (*Application::getInstance().getCurrentUser());
    Room *room = nullptr;
    DateTime startTime;
    DateTime endTime;
    string reason;
    cout << "Enter room number for slot request.\n";
    room = Room::findByRoomNumber(Input::getInt());
    startTime.inputValidate();
    endTime.inputValidate();
    cout << "Enter reason: \n";
    cin.ignore();
    getline(cin, reason, '\n');
    if (requestedBy && room) {
        form = new SlotCreateUpdateForm(*requestedBy, *room, startTime, endTime, reason.c_str(), 0);
        if (form->isValid()) {
            Slot slot = form->save();
            cout << "Slot #" + to_string(slot.getId()) + " requested successfully.\n";
        } else {
            form->printErrors();
        }
    } else {
        cout << "Requested room doesn't exist. / invalid user\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}

void SlotUpdateView::display() {
    cout << "To update a slot request fill in the details asked below: \n";
    auto *requestedBy = dynamic_cast<Professor *>(Application::getInstance().getCurrentUser());
    Room *room = nullptr;
    DateTime startTime;
    DateTime endTime;
    string reason;
    cout << "Enter room number for slot request.\n";
    room = Room::findByRoomNumber(Input::getInt());
    startTime.inputValidate();
    endTime.inputValidate();
    cout << "Enter reason: \n";
    getline(cin, reason, '\n');
    if (requestedBy && room) {
        form = new SlotCreateUpdateForm(*requestedBy, *room, startTime, endTime, reason.c_str(), 0);
        if (form->isValid()) {
            Slot slot = form->save();
            cout << "Slot #" + to_string(slot.getId()) + " requested successfully.\n";
        } else {
            form->printErrors();
        }
    } else {
        cout << "Requested room doesn't exist.\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}