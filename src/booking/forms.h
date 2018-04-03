//
// Created by ajatprabha on 3/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_BOOKING_FORMS_H
#define CLASSROOMBOOKINGSYSTEM_BOOKING_FORMS_H


#include <base/forms.h>
#include "models.h"

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
};


#endif //CLASSROOMBOOKINGSYSTEM_BOOKING_FORMS_H
