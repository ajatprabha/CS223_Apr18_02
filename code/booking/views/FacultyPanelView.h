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
                              {Controller::getInstance().getView("update-user"),
                               Controller::getInstance().getView("empty-rooms-list"),
                               Controller::getInstance().getView("create-slot"),
                               Controller::getInstance().getView("slot-notification-list"),
                               Controller::getInstance().getView("update-slot"),
                               Controller::getInstance().getView("delete-slot"),
                               Controller::getInstance().getView("logout"),
                               Controller::getInstance().getView("exit")}) {}

    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_FACULTYPANELVIEW_H
