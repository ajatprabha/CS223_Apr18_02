//
// Created by ajatprabha on 3/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SLOTCREATEUPDATEFORM_H
#define CLASSROOMBOOKINGSYSTEM_SLOTCREATEUPDATEFORM_H

#include <booking/models/Slot.h>
#include <base/forms/ModelForm.h>

class SlotCreateUpdateForm : public ModelForm<Slot> {
private:
    Professor requestedBy;
    Room room;
    DateTime startTime;
    DateTime endTime;
    char reason[2048]{};
    int approved = 0;
public:

    SlotCreateUpdateForm(const Professor &requestedBy, const Room &room, const DateTime &startTime,
                         const DateTime &endTime, const char *reason, int approved, Slot *passedInstance = nullptr);

    void clean() override;

    Slot &save() override;

    bool clash(const DateTime &time, const DateTime &dateTime);
};


#endif //CLASSROOMBOOKINGSYSTEM_SLOTCREATEUPDATEFORM_H
