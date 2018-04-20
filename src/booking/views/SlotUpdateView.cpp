//
// Created by ajatprabha on 1/4/18.
//

#include <booking/forms/SlotCreateUpdateForm.h>
#include <init/Application.h>
#include "SlotUpdateView.h"

void SlotUpdateView::display() {
    cout << "To update a slot request fill in the details asked below: \n";
    auto *requestedBy = &static_cast<Professor &>(*Application::getInstance().getCurrentUser());
    Room *room = nullptr;
    DateTime startTime;
    DateTime endTime;
    string reason;
    cout << "Enter the slot id you want to update.\n";
    Slot *instance = Slot::findById(Input::getInt());
    if (instance) {
        cout << "Enter new room number for slot request.\n";
        room = Room::findByRoomNumber(Input::getInt());
        startTime.inputValidate();
        endTime.inputValidate();
        cout << "Enter reason: \n";
        cin.ignore();
        getline(cin, reason, '\n');
        if (requestedBy && room) {
            form = new SlotCreateUpdateForm(*requestedBy, *room, startTime, endTime, reason.c_str(), 0, instance);
            if (form->isValid()) {
                Slot slot = form->save();
                cout << "Slot #" + to_string(slot.getId()) + " updated successfully.\n";
            } else {
                form->printErrors();
            }
        } else {
            cout << "Requested room doesn't exist.\n";
        }
    } else {
        cout << "Slot doesn't exist.\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}
