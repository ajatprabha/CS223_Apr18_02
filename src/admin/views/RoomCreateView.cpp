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