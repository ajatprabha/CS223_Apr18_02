//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_BOOKING_MODELS_H
#define CLASSROOMBOOKINGSYSTEM_BOOKING_MODELS_H

#include <cstring>
#include "../users/models.h"
#include "../base/models.h"

struct DateTime {
    DateTime() = default;

    DateTime(int date, int month, int year, int hour, int minute, int second, char meridy);

    int date{};
    int month{};
    int year{};
    int hour{};
    int minute{};
    int second{};
    char meridy = 'A';
    long long value{};

    string getTimestamp() const;

    void inputValidate();

    bool operator<(DateTime obj);

    bool operator>(DateTime obj);

    bool operator>=(DateTime obj);

    bool operator<=(DateTime obj);
};

class Room : public Model<Room> {
private:
    int roomNumber = 0;
    int strength = 0;
    bool audio = false;
    bool video = false;
public:
    Room() = default;

    Room(int roomNumber, int strength, bool audio, bool video);

    int getRoomNumber() const;

    int getStrength() const;

    bool hasAudio() const;

    bool hasVideo() const;

    void setStrength(int strength);

    void setAudio(bool audio);

    void setVideo(bool video);
};


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


#endif //CLASSROOMBOOKINGSYSTEM_BOOKING_MODELS_H
