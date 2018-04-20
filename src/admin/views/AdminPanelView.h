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
                            {Controller::getInstance().getView("admin-unseen-slot-list"),
                             Controller::getInstance().getView("create-user"),
                             Controller::getInstance().getView("update-user"),
                             Controller::getInstance().getView("delete-user"),
                             Controller::getInstance().getView("create-room"),
                             Controller::getInstance().getView("update-room"),
                             Controller::getInstance().getView("delete-room"),
                             Controller::getInstance().getView("room-details"),
                             Controller::getInstance().getView("logout"),
                             Controller::getInstance().getView("exit")}) {}

    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMINPANELVIEW_H
