//
// Created by ajatprabha on 1/4/18.
//

#include <iostream>
#include <base/views.h>
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

Room *Room::findByRoomNumber(int id) {
    for (auto &item : Room::all()) {
        if (item.second.getRoomNumber() == id) return &(item.second);
    }
    return nullptr;
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

void DateTime::inputValidate() {
    cout<<"Enter the Time in dd mm yyyy hh mm format (24 hour clock format)"<<endl;
    int days[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};
    bool flag = false, invalid = false;
    while(!flag) {
        if(invalid)
            cout<<"Date and Time entered are invalid. Please enter again"<<endl;
        bool leap = false;
        date = Input::getInt();
        month = Input::getInt();
        year = Input::getInt();
        hour = Input::getInt();
        minute = Input::getInt();
        if (year % 400==0 || ((year % 100==0) ^ (year % 4==0))) {
            leap = true;
            //cout<<"leap"<<leap<<endl;
        }
        if ((month <= 12 && month >= 1) && (minute<60&&minute>=0) && (hour>=0&&hour<24)) {
            if (month != 2) {
                if (date <= days[month - 1] && date > 0)
                    flag = true;
            } else {
                if (leap && date <= days[12])
                    flag = true;
                if (!leap && date <= days[1])
                    flag = true;
            }
        }
        invalid = true;
    }

    value = year*10000000000+month*100000000+date*100000+hour*1000+minute;//timestamp hash
}

bool DateTime::operator<(const DateTime &rhs) const {
    return value < rhs.value;
}

bool DateTime::operator>(const DateTime &rhs) const {
    return rhs < *this;
}

bool DateTime::operator<=(const DateTime &rhs) const {
    return !(rhs < *this);
}

bool DateTime::operator>=(const DateTime &rhs) const {
    return !(*this < rhs);
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
