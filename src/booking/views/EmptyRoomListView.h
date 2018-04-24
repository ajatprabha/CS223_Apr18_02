//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_EMPTYROOMLISTVIEW_H
#define CLASSROOMBOOKINGSYSTEM_EMPTYROOMLISTVIEW_H

#include <booking/models/Room.h>
#include <base/views/ListView.h>
#include <base/utils/DateTime.h>

class EmptyRoomListView : public ListView<Room> {
private:
    struct Parameters {
        DateTime start, end;
        bool audio = false, video = false;
        int strength = 0;
    } params;
public:
    vector<Room> &getQueryset() override;

    void display() override;

    void getParams();

    bool clash(const DateTime &startTime, const DateTime &endTime);
};


#endif //CLASSROOMBOOKINGSYSTEM_EMPTYROOMLISTVIEW_H
