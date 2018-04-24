//
// Created by ajatprabha on 20/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ROOMDELETEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_ROOMDELETEVIEW_H

#include <base/views/DeleteView.h>
#include <booking/models/Room.h>

class RoomDeleteView : public DeleteView<Room> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ROOMDELETEVIEW_H
