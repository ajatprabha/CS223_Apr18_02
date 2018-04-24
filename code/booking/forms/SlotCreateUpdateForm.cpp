//
// Created by ajatprabha on 3/4/18.
//

#include "SlotCreateUpdateForm.h"

SlotCreateUpdateForm::SlotCreateUpdateForm(const Professor &requestedBy, const Room &room, const DateTime &startTime,
                                           const DateTime &endTime, const char *passedReason, int approved,
                                           Slot *passedInstance) : requestedBy(requestedBy), room(room),
                                                                   startTime(startTime), endTime(endTime),
                                                                   approved(approved) {
    strcpy(reason, passedReason);
    instance = passedInstance;
}

void SlotCreateUpdateForm::clean() {
    bool roomFlag = true;
//    for (auto &i : Slot::all()) {
//        if (!(roomFlag &&
//              room.getStrength() <= i.second.getRoom().getStrength() &&
//              ((room.hasAudio() && i.second.getRoom().hasAudio()) || !room.hasAudio()) &&
//              ((room.hasVideo() && i.second.getRoom().hasVideo()) || !room.hasVideo()) &&
//              (i.second.getStartTime() >= endTime || i.second.getEndTime() <= startTime))) {
//            roomFlag = false;
//        }
//    }

    for(auto &i: Slot::all()) {
        if (roomFlag && i.second.getRoom().getRoomNumber() == room.getRoomNumber() &&
            clash(i.second.getStartTime(), i.second.getEndTime())) {
            roomFlag = false;
            addError("Some other Professor's slot is clashing with yours, please try again!");
        }
    }
    //if (!roomFlag) addError("Error: The following may be occuring");    //TODO
    if(room.getStrength()>Room::findById(room.getRoomNumber())->getStrength())
    {
        roomFlag = false;
        addError("Strength Exceeded");
    }
    if(room.hasAudio() && !Room::findById(room.getRoomNumber())->hasAudio())
    {
        roomFlag = false;
        addError("Audio not available");
    }
    if(room.hasVideo() && !Room::findById(room.getRoomNumber())->hasVideo())
    {
        roomFlag = false;
        addError("Video not available");
    }
    int length = sizeof(reason) / sizeof(char);
    if (length > 2048) addError("Reason size is limited to 2048 characters\n");
}

Slot &SlotCreateUpdateForm::save() {
    Slot *temp;
    temp = new Slot(requestedBy, room, startTime, endTime, reason, approved);
    if (instance) {
        int id = instance->getId();
        instance->remove();
        temp->setId(id);
    }
    temp->save();
    return *temp;
}

bool SlotCreateUpdateForm::clash(const DateTime &sTime, const DateTime &eTime) {
    return (startTime >= sTime && startTime <= eTime) || (endTime >= sTime && startTime <= sTime);
}
