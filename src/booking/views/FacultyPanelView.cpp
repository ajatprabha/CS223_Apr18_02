//
// Created by saksham on 3/4/18.
//

#include <base/utils/Input.h>
#include <booking/models/Slot.h>
#include <base/views/DeleteView.h>
#include <init/Application.h>
#include "FacultyPanelView.h"

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
    response->view = Controller::getInstance().getView("faculty-profile-update");
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
