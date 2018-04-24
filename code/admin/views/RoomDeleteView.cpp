//
// Created by ajatprabha on 20/4/18.
//

#include <base/utils/Input.h>
#include <booking/models/Slot.h>
#include <init/Application.h>
#include "RoomDeleteView.h"

void RoomDeleteView::display() {
    cout << "Enter the Room number to be deleted:\n. "
            "Note that all slots with the room number entered will also be deleted so be careful.\n";
    Room *room = Room::findByRoomNumber(Input::getInt());
    if (room) {
        context.requestObjectId = room->getId();
        DeleteView::display();
        for (auto &it :Slot::all()) {
            if (it.second.getRoom().getRoomNumber() == room->getRoomNumber())
                it.second.remove();
        }
        cout << "Room #" + to_string(room->getRoomNumber()) + " successfuly deleted.\n";
    } else {
        cout << "No room with this number exists.\n";
    }
    response->view = Controller::getInstance().getView("admin-panel");
}
