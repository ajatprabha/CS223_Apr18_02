//
// Created by ajatprabha on 1/4/18.
//

#include <base/controller.h>
#include "SlotNotificationListView.h"

vector<Slot> &SlotNotificationListView::getQueryset() {
    objects.clear();
    for (auto &i : objectList) {
        if (i.second.getRequestedBy() == static_cast<Professor &>(*context.user)) objects.push_back(i.second);
    }
    return objects;
}

void SlotNotificationListView::display() {
    vector<Slot> temp = getQueryset();
    if (!temp.empty()) {
        cout << "Here is the list of slot requests that you've made: \n";
        for (auto &slot : temp) {
            cout << slot.getId() << ". " << slot.getRoom().getRoomNumber() << " " << slot.getStartTime().getTimestamp()
                 << " " << slot.getEndTime().getTimestamp() << "\n";
            cout << "\tApproved status: ";
            if (slot.getApproved() == 1) cout << "Approved\n";
            else if (slot.getApproved() == 2) cout << "Denied\n";
            else cout << "Pending\n";
        }
    } else cout << "No slot requests to show!\n";
    response->view = Controller::getInstance().getView("faculty-panel");
}
