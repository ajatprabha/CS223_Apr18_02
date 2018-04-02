//
// Created by ajatprabha on 1/4/18.
//

#include "views.h"

void FacultyPanelView::display() {
    cout << "Professor: " << Application::getInstance().getCurrentUser()->getFullName() << endl;
    populateMenu();
    callAction(Input::getInt() - 1);
}

void FacultyPanelView::bookSlot() {
    cout<<"To Book a slot, enter the following details correctly"<<endl;


    response->view = Controller::getInstance().getView("faculty-panel");
}

void FacultyPanelView::listSlotStatus() {





}

void FacultyPanelView::updateUser() {


}

void FacultyPanelView::updateSlot() {

    response->view = Controller::getInstance().getView("faculty-panel");

}

void FacultyPanelView::deleteSlot() {

    cout << "Enter the slot id to be deleted:\n";
    int id;
    cin >> id;
    Slot *slot = Slot::findById(id);
    if (!slot) {
        cout << "No slot with this id exists.\n";
    }
    else
        DeleteView<Slot>().call({Application::getInstance().getCurrentUser(), slot->getId()});
    response->view = Controller::getInstance().getView("faculty-panel");
}

void FacultyPanelView::listEmptyRooms() {

    cout<<"Enter the time slot (start and finish times) you want to check empty classrooms for"<<endl;
    DateTime start,finish;
    start.inputValidate();
    finish.inputValidate();
    if(start<finish)
    {

    }

}
