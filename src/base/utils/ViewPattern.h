//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_VIEWPATTERN_H
#define CLASSROOMBOOKINGSYSTEM_VIEWPATTERN_H

#include <base/views/View.h>

class ViewPattern {
private:
    string name;
    View *view;
public:
    ViewPattern(const string &name, View *view);

    const string &getName() const;

    void setName(const string &name);

    View *getView() const;

    void setView(View *view);
};


#endif //CLASSROOMBOOKINGSYSTEM_VIEWPATTERN_H
