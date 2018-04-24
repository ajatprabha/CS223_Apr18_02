//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ROOMDETAILVIEW_H
#define CLASSROOMBOOKINGSYSTEM_ROOMDETAILVIEW_H

#include <base/views/DetailView.h>

class RoomDetailView : public DetailView<Room> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ROOMDETAILVIEW_H
