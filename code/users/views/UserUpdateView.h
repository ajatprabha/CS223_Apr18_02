//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_USERUPDATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_USERUPDATEVIEW_H

#include <base/views/UpdateView.h>

class UserUpdateView : public UpdateView<BaseUser> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_USERUPDATEVIEW_H
