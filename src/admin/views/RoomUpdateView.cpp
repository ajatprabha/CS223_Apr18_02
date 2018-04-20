//
// Created by ajatprabha on 1/4/18.
//

#include <admin/forms/RoomCreateUpdateForm.h>
#include <base/utils/Input.h>
#include <base/controller.h>
#include "RoomUpdateView.h"

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
