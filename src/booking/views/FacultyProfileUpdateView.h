//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_FACULTYPROFILEUPDATEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_FACULTYPROFILEUPDATEVIEW_H

#include <base/views/UpdateView.h>

class FacultyProfileUpdateView : public UpdateView<BaseUser> {
public:
    void display() override;
};


#endif //CLASSROOMBOOKINGSYSTEM_FACULTYPROFILEUPDATEVIEW_H
