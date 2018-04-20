//
// Created by ajatprabha on 20/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SLOTDELETEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_SLOTDELETEVIEW_H

#include <base/views/DeleteView.h>
#include <booking/models/Slot.h>

class SlotDeleteView : public DeleteView<Slot> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_SLOTDELETEVIEW_H
