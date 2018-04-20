//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_USERCREATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_USERCREATEVIEW_H

#include <base/views/CreateView.h>

class UserCreateView : public CreateView<BaseUser> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_USERCREATEVIEW_H
