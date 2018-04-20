//
// Created by ajatprabha on 1/4/18.
//

#include "Slot.h"

Slot::Slot(const Professor &requestedBy, const Room &room, const DateTime &startTime, const DateTime &endTime,
           char *passedReason, int approved) : requestedBy(requestedBy), room(room), startTime(startTime),
                                               endTime(endTime), approved(approved) {
    strcpy(reason, passedReason);
}

const Professor &Slot::getRequestedBy() const {
    return requestedBy;
}

const Room &Slot::getRoom() const {
    return room;
}

const DateTime &Slot::getStartTime() const {
    return startTime;
}

const DateTime &Slot::getEndTime() const {
    return endTime;
}

const char *Slot::getReason() const {
    return reason;
}

int Slot::getApproved() const {
    return approved;
}

void Slot::setApproved(int approved) {
    Slot::approved = approved;
}
