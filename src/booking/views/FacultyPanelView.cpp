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
    callView(Input::getInt() - 1);
}
