//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_UNSEENSLOTREQUESTLISTVIEW_H
#define CLASSROOMBOOKINGSYSTEM_UNSEENSLOTREQUESTLISTVIEW_H

#include <booking/models/Slot.h>
#include <base/views/ListView.h>

class UnseenSlotRequestListView : public ListView<Slot> {
public:
    vector<Slot> getQueryset() override;

    void display() override;
};

#endif //CLASSROOMBOOKINGSYSTEM_UNSEENSLOTREQUESTLISTVIEW_H
