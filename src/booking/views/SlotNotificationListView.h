//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SLOTNOTIFICATIONLISTVIEW_H
#define CLASSROOMBOOKINGSYSTEM_SLOTNOTIFICATIONLISTVIEW_H

#include <booking/models/Slot.h>
#include <base/views/ListView.h>

class SlotNotificationListView : public ListView<Slot> {
public:
    vector<Slot> &getQueryset() override;

    void display() override;
};

#endif //CLASSROOMBOOKINGSYSTEM_SLOTNOTIFICATIONLISTVIEW_H
