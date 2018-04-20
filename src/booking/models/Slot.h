//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_SLOT_H
#define CLASSROOMBOOKINGSYSTEM_SLOT_H

#include <base/models/Model.h>
#include <users/models/Professor.h>
#include <base/utils/DateTime.h>
#include "Room.h"

class Slot : public Model<Slot> {
private:
    Professor requestedBy;
    Room room;
    DateTime startTime;
    DateTime endTime;
    char reason[2048]{};
    int approved = 0;
public:
    Slot() = default;

    Slot(const Professor &requestedBy, const Room &room, const DateTime &startTime, const DateTime &endTime,
         char *reason, int approved);

    const Professor &getRequestedBy() const;

    const Room &getRoom() const;

    const DateTime &getStartTime() const;

    const DateTime &getEndTime() const;

    const char *getReason() const;

    int getApproved() const;

    void setApproved(int approved);
};


#endif //CLASSROOMBOOKINGSYSTEM_SLOT_H
