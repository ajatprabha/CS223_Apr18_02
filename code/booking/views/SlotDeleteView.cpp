//
// Created by ajatprabha on 20/4/18.
//

#include <base/controller.h>
#include "SlotDeleteView.h"

void SlotDeleteView::display() {
    cout << "Enter the slot id to be deleted: ";
    Slot *slot = Slot::findById(Input::getInt());
    if (!slot) {
        cout << "No slot with this id exists.\n";
    } else {
        context.requestObjectId = slot->getId();
        DeleteView::display();
    };
    response->view = Controller::getInstance().getView("faculty-panel");
}
