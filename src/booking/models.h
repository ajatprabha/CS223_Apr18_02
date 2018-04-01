//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_BOOKING_MODELS_H
#define CLASSROOMBOOKINGSYSTEM_BOOKING_MODELS_H

#include "../users/models.h"
#include "../base/models.h"

class Room : public Model<Room> {
private:
    int roomNumber;
    int strength;
    bool audio;
    bool video;
public:
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
    string startTime;
    string endTime;
    string reason;
    string date;
    int approved = 0;
public:
    Slot(const Professor &requestedBy, const Room &room, const string &startTime, const string &endTime,
         const string &reason, const string &date, int approved = 0);
};


#endif //CLASSROOMBOOKINGSYSTEM_BOOKING_MODELS_H
