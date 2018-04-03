//
// Created by ajatprabha on 3/4/18.
//

#include "forms.h"

SlotCreateUpdateForm::SlotCreateUpdateForm(const Professor &requestedBy, const Room &room, const DateTime &startTime,
                                           const DateTime &endTime, const char *passedReason, int approved,
                                           Slot *passedInstance) : requestedBy(requestedBy), room(room),
                                                                   startTime(startTime), endTime(endTime),
                                                                   approved(approved) {
    strcpy(reason, passedReason);
    instance = passedInstance;
}

void SlotCreateUpdateForm::clean() {
    //TODO
}

Slot &SlotCreateUpdateForm::save() {
    Slot *temp;
    int id;
    temp = new Slot(requestedBy, room, startTime, endTime, reason, approved);
    if (instance) {
        id = instance->getId();
        instance->remove();
        temp->setId(id);
    }
    temp->save();
    return *temp;
}
