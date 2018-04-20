//
// Created by saksham on 3/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_FACULTYPANELVIEW_H
#define CLASSROOMBOOKINGSYSTEM_FACULTYPANELVIEW_H

#include <base/views/View.h>

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


#endif //CLASSROOMBOOKINGSYSTEM_FACULTYPANELVIEW_H
