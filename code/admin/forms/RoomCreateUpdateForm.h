//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ROOMCREATEUPDATEFORM_H
#define CLASSROOMBOOKINGSYSTEM_ROOMCREATEUPDATEFORM_H

#include <base/forms/ModelForm.h>
#include <booking/models/Room.h>

class RoomCreateUpdateForm : public ModelForm<Room> {
    int roomNumber, strength;
    bool audio, video;
public:

    RoomCreateUpdateForm(int roomNumber, int strength, bool audio, bool video, Room *passedInstance = nullptr);

    void clean() override;

    Room &save() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ROOMCREATEUPDATEFORM_H
