//
// Created by ajatprabha on 1/4/18.
//

#include "RoomCreateUpdateForm.h"

RoomCreateUpdateForm::RoomCreateUpdateForm(int roomNumber, int strength, bool audio, bool video, Room *passedInstance)
        : roomNumber(roomNumber), strength(strength), audio(audio), video(video) {
    instance = passedInstance;
}

void RoomCreateUpdateForm::clean() {
    if (!instance) {
        for (auto &i : Room::all()) {
            if (i.second.getRoomNumber() == roomNumber) addError("A room with this room number already exists.");
        }
    }
}

Room &RoomCreateUpdateForm::save() {
    Room *temp;
    int id;
    temp = new Room(roomNumber, strength, audio, video);
    if (instance) {
        id = instance->getId();
        instance->remove();
        temp->setId(id);
    }
    temp->save();
    return *temp;
}
