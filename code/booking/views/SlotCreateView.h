//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SLOTCREATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_SLOTCREATEVIEW_H

#include <booking/models/Slot.h>
#include <base/views/CreateView.h>

class SlotCreateView : public CreateView<Slot> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_SLOTCREATEVIEW_H
