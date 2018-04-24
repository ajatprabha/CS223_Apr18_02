//
// Created by ajatprabha on 1/4/18.
//

#include <base/utils/Input.h>
#include <base/controller.h>
#include "UnseenSlotRequestListView.h"

vector<Slot> &UnseenSlotRequestListView::getQueryset() {
    for (auto &i : objectList) {
        if (i.second.getApproved() == 0) objects.push_back(i.second);
    }
    return objects;
}

void UnseenSlotRequestListView::display() {
    vector<Slot> temp = getQueryset();
    if (!temp.empty()) {
        cout << "Following are the unseen slot requests.\nSelect slot ID to approve/deny\n";
        for (auto &slot: temp) {
            cout << slot.getId() << ". " << slot.getRequestedBy().getFullName() << " Time: "
                 << slot.getStartTime().getTimestamp();
        }
        Slot *slot = Slot::findById(Input::getInt());
        if (slot) {
            cout << "Enter 1 to approve, 2 to deny: ";
            slot->setApproved(Input::getInt());
            slot->save();
        } else cout << "Invalid slot selection\n";
    } else cout << "No slot requests!\n";
    response->view = Controller::getInstance().getView("admin-panel");
}