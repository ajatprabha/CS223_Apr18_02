//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_ADMINDETAILVIEW_H
#define CLASSROOMBOOKINGSYSTEM_ADMINDETAILVIEW_H

#include <base/views/DetailView.h>

class AdminDetailView : public DetailView<BaseUser> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_ADMINDETAILVIEW_H
