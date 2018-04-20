//
// Created by ajatprabha on 1/4/18.
//

#include "Room.h"

Room::Room(int roomNumber, int strength, bool audio, bool video) : roomNumber(roomNumber), strength(strength),
                                                                   audio(audio), video(video) {}

int Room::getRoomNumber() const {
    return roomNumber;
}

int Room::getStrength() const {
    return strength;
}

bool Room::hasAudio() const {
    return audio;
}

bool Room::hasVideo() const {
    return video;
}

void Room::setStrength(int strength) {
    Room::strength = strength;
}

void Room::setAudio(bool audio) {
    Room::audio = audio;
}

void Room::setVideo(bool video) {
    Room::video = video;
}

Room *Room::findByRoomNumber(int id) {
    for (auto &item : Room::all()) {
        if (item.second.getRoomNumber() == id) return &(item.second);
    }
    return nullptr;
}
