//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SLOTUPDATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_SLOTUPDATEVIEW_H

#include <booking/models/Slot.h>
#include <base/views/UpdateView.h>

class SlotUpdateView : public UpdateView<Slot> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_SLOTUPDATEVIEW_H
