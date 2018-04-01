//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
#define CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H

#include "../init.h"
#include "../base/views.h"
#include "forms.h"

class AdminDetailView : public DetailView<BaseUser> {
public:
    AdminDetailView() = default;

    void display() override;
};

class AdminCreateView : public CreateView<BaseUser> {
public:
    AdminCreateView() = default;

    void display() override;
};

class AdminPanelView : public View {
public:
    AdminPanelView() : View("\tAdmin panel\n\tHere you can perform the following actions.\n",
                            {"Create new admin", "Delete admin/professor", "Exit"},
                            {createAdmin, deleteUser, exit}) {}

    void display() override;

    static void deleteUser();

    static void createAdmin();
};

class AdminDeleteView : public DeleteView<BaseUser> {
public:
    void display() final;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMIN_VIEWS_H
