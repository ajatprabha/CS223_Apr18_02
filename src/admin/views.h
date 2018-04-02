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
                            {"Create new user", "Update existing user", "Delete admin/professor", "View slot requests", "Exit"},
                            {createUser, updateUser, deleteUser, listUnseenSlots, exit}) {}

    void display() override;

    static void deleteUser();

    static void createUser();

    static void updateUser();

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


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
