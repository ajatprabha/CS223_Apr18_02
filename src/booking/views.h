//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_BOOKING_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_BOOKING_VIEWS_H

#include <init.h>
#include <base/views.h>

class FacultyPanelView : public View {
public:
    FacultyPanelView() : View("Faculty panel\nYou can perform the following actions.\n",
                              {"Update profile", "List empty rooms for a given time slot", "Book Slot",
                               "Check Status of slots", "Update slot", "Delete slot", "Logout", "Exit"},
                              {updateUser, listEmptyRooms, bookSlot, listSlotStatus, updateSlot, deleteSlot,
                               callLogoutView, exit}) {}

    void display() override;

    static void bookSlot();

    static void listEmptyRooms();

    static void listSlotStatus();

    static void updateUser();

    static void updateSlot();

    static void deleteSlot();

    static void callLogoutView();

};

class SlotCreateView : public CreateView<Slot> {
public:
    void display() override;
};

class SlotUpdateView : public UpdateView<Slot> {
public:
    void display() override;
};

class SlotNotificationListView : public ListView<Slot> {
public:
    vector<Slot> getQueryset() override;

    void display() override;
};

class EmptyRoomListView : public ListView<Room> {
private:
    struct Parameters {
        DateTime start, end;
        bool audio = false, video = false;
        int strength = 0;
    } params;
public:
    vector<Room> getQueryset() override;

    void display() override;

    void getParams();
};


#endif //CLASSROOMBOOKINGSYSTEM_BOOKING_VIEWS_H
