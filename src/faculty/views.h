//
// Created by saksham on 3/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_FACULTY_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_FACULTY_VIEWS_H

#include "../base/views.h"

class FacultyPanelView : public View
{
public:
    FacultyPanelView():View("Faculty panel\nYou can perform the following actions.\n",
                            { "Update profile","List empty rooms for a given time slot", "Book Slot", "Check Status of slots", "Update slot", "delete slot", "Exit"},
                            {updateUser, listEmptyRooms, bookSlot, listSlotStatus, updateSlot, deleteSlot, exit }) {}
    void display() override;

    static void bookSlot();

    static void listEmptyRooms();

    static void listSlotStatus();

    static void updateUser();

    static void updateSlot();

    static void deleteSlot();

};


class ListEmptySlots : public
#endif
