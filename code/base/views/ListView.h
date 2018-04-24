//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_LISTVIEW_H
#define CLASSROOMBOOKINGSYSTEM_LISTVIEW_H


#include <base/mixins/MultipleObjectMixin.h>
#include "View.h"

template<class T>
class ListView : public MultipleObjectMixin<T>, public View {
public:
    ListView() = default;
};


#endif //CLASSROOMBOOKINGSYSTEM_LISTVIEW_H
