//
// Created by ajatprabha on 1/4/18.
//

#include <base/utils/Input.h>
#include <booking/models/Room.h>
#include <base/controller.h>
#include "RoomDetailView.h"

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
