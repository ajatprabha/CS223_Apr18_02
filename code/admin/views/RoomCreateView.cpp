//
// Created by ajatprabha on 1/4/18.
//

#include <base/utils/Input.h>
#include <admin/forms/RoomCreateUpdateForm.h>
#include <base/controller.h>
#include "RoomCreateView.h"

void RoomCreateView::display() {
    cout << "To create a room fill in the details asked below: \n";
    int roomNumber, strength;
    bool audio, video;
    cout << "Enter room number: ";
    roomNumber = Input::getInt();
    cout << "Enter strength: ";
    strength = Input::getInt();
    cout << "Audio required? (y/n): ";
    audio = (Input::getChar() == 'y');
    cout << "Video required? (y/n): ";
    video = (Input::getChar() == 'y');
    form = new RoomCreateUpdateForm(roomNumber, strength, audio, video);
    if (form->isValid()) {
        Room room = form->save();
        cout << "Room #" + to_string(room.getRoomNumber()) + " created successfully.\n";
    } else {
        form->printErrors();
    }
    response->view = Controller::getInstance().getView("admin-panel");
}