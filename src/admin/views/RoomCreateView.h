//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ROOMCREATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_ROOMCREATEVIEW_H

#include <booking/models/Room.h>
#include <base/views/CreateView.h>

class RoomCreateView : public CreateView<Room> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ROOMCREATEVIEW_H
