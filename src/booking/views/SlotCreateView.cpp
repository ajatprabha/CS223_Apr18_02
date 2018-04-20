//
// Created by ajatprabha on 1/4/18.
//

#include <booking/forms/SlotCreateUpdateForm.h>
#include <init/Application.h>
#include "SlotCreateView.h"

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
