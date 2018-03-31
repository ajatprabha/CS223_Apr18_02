//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H

#include "../init.h"
#include "../base/views.h"
#include "forms.h"

class AdminPanelView : public View {
public:
    AdminPanelView() : View("Admin panel\nYou can perform the following actions.\n",
                            {"Create new admin", "Delete admin/professor", "Exit"},
                            {createAdmin, deleteUser, exit}) {}

    void display() override;

    static void deleteUser();

    static void createAdmin();
};

class AdminCreateView : public CreateView<BaseUser> {
public:
    void display() override;
};

class AdminDetailView : public DetailView<BaseUser> {
public:
    void display() override;
};

class AdminDeleteView : public DeleteView<BaseUser> {
public:
    void display() final;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
