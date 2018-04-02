//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H

#include <booking/models.h>
#include "../init.h"
#include "../base/views.h"
#include "forms.h"

class AdminPanelView : public View {
public:
    AdminPanelView() : View("Admin panel\nYou can perform the following actions.\n",
                            {"View slot requests", "Create new user", "Update existing user", "Delete admin/professor",
                             "Create new room", "Update existing room", "Delete room", "View room details",
                             "Exit"},
                            {listUnseenSlots, createUser, updateUser, deleteUser, createRoom, updateRoom, deleteRoom,
                             roomDetails, exit}) {}

    void display() override;

    static void deleteUser();

    static void createUser();

    static void updateUser();

    static void createRoom();

    static void updateRoom();

    static void deleteRoom();

    static void roomDetails();

    static void listUnseenSlots();
};

class AdminDetailView : public DetailView<BaseUser> {
public:
    void display() override;
};

class UnseenSlotRequestListView : public ListView<Slot> {
public:
    vector<Slot> getQueryset() override;

    void display() override;
};

class DeleteUserView : public DeleteView<BaseUser> {
public:
    void display() final;
};

class RoomCreateView : public CreateView<Room> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
