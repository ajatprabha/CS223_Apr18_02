//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ROOM_H
#define CLASSROOMBOOKINGSYSTEM_ROOM_H

#include <base/models/Model.h>

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

    static Room *findByRoomNumber(int id);
};


#endif //CLASSROOMBOOKINGSYSTEM_ROOM_H
