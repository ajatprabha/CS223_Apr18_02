//
// Created by ajatprabha on 1/4/18.
//

#include <iostream>
#include "models.h"

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

DateTime::DateTime(int date, int month, int year, int hour, int minute, int second, char meridy) : date(date),
                                                                                                   month(month),
                                                                                                   year(year),
                                                                                                   hour(hour),
                                                                                                   minute(minute),
                                                                                                   second(second),
                                                                                                   meridy(meridy) {}

string DateTime::getTimestamp() const {
    string str = to_string(date) + "/" + to_string(month) + "/" + to_string(year) + " " + to_string(hour) + ":" +
                 to_string(minute) + ":" + to_string(second);
    string mer;
    if (meridy == 'A') mer = "AM";
    else mer = "PM";
    return str + " " + mer;
}

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
