//
// Created by ajatprabha on 1/4/18.
//

#include <base/utils/Input.h>
#include <booking/models/Room.h>
#include <booking/models/Slot.h>
#include <init/Application.h>
#include "AdminPanelView.h"
#include "users/views/UserDeleteView.h"

void AdminPanelView::display() {
    cout << "Admin: " << Application::getInstance().getCurrentUser()->getFullName() << endl;
    populateMenu();
    callView(Input::getInt() - 1);
}
