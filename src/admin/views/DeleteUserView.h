//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_DELETEUSERVIEW_H
#define CLASSROOMBOOKINGSYSTEM_DELETEUSERVIEW_H

#include <base/views/DeleteView.h>

class DeleteUserView : public DeleteView<BaseUser> {
public:
    void display() final;
};

#endif //CLASSROOMBOOKINGSYSTEM_DELETEUSERVIEW_H
