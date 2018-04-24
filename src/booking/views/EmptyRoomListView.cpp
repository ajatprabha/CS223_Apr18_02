//
// Created by ajatprabha on 1/4/18.
//

#include "EmptyRoomListView.h"
#include <booking/models/Slot.h>
#include <base/controller.h>

void EmptyRoomListView::display() {
    getParams();
    for (auto &room : getQueryset()) {
        cout << "Room #" << room.getRoomNumber() << ", ID: " << room.getId() << "\n";
    }
    response->view = Controller::getInstance().getView("faculty-panel");
}

vector<Room> &EmptyRoomListView::getQueryset() {
    objects.clear();
    map<int, bool> roomFlags;
    if (params.start < params.end) {
        for (auto &i :Room::all()) {
            roomFlags[i.second.getRoomNumber()] = true;
        }

        for (auto &i : Slot::all()) {
            if (i.second.getApproved()==1 && roomFlags[i.second.getRoom().getRoomNumber()] &&
                clash(i.second.getStartTime(), i.second.getEndTime())) {
                roomFlags[i.second.getRoom().getRoomNumber()] = false;
            }
        }
        for(auto &i: Room::all()){
            if(params.strength>i.second.getStrength())
                roomFlags[i.second.getRoomNumber()]=false;
            if(params.audio && !i.second.hasAudio())
                roomFlags[i.second.getRoomNumber()] = false;
            if(params.video && !i.second.hasVideo())
                roomFlags[i.second.getRoomNumber()] = false;
        }

        for (auto &i : roomFlags) {
            if (i.second) objects.push_back(*Room::findByRoomNumber(i.first));
        }
    }
    return objects;
}

void EmptyRoomListView::getParams() {
    cout << "Fill in the following details:\n"
         << "Start time -> ";
    params.start.inputValidate();
    cout << "End time -> ";
    params.end.inputValidate();
    cout << "Enter strength: ";
    params.strength = Input::getInt();
    cout << "Audio required? (y/n): ";
    params.audio = (Input::getChar() == 'y');
    cout << "Video required? (y/n): ";
    params.video = (Input::getChar() == 'y');
}

bool EmptyRoomListView::clash(const DateTime &startTime, const DateTime &endTime) {
    return (params.start >= startTime && params.start <= endTime) || (params.end >= startTime && params.start <= startTime);
}
