//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMINPANELVIEW_H
#define CLASSROOMBOOKINGSYSTEM_ADMINPANELVIEW_H

#include <base/views/DeleteView.h>

class AdminPanelView : public View {
public:
    AdminPanelView() : View("Admin panel\nYou can perform the following actions.\n",
                            {"View slot requests", "Create new user", "Update existing user", "Delete admin/professor",
                             "Create new room", "Update existing room", "Delete room", "View room details",
                             "Logout", "Exit"},
                            {listUnseenSlots, createUser, updateUser, deleteUser, createRoom, updateRoom, deleteRoom,
                             roomDetails, callLogoutView, exit}) {}

    void display() override;

    static void deleteUser();

    static void createUser();

    static void updateUser();

    static void createRoom();

    static void updateRoom();

    static void deleteRoom();

    static void roomDetails();

    static void listUnseenSlots();

    static void callLogoutView();
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMINPANELVIEW_H
