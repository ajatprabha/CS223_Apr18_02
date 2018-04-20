//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ROOMUPDATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_ROOMUPDATEVIEW_H

#include <base/views/UpdateView.h>

class RoomUpdateView : public UpdateView<Room> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ROOMUPDATEVIEW_H
