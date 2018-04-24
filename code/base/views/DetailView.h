//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_DETAILVIEW_H
#define CLASSROOMBOOKINGSYSTEM_DETAILVIEW_H


#include <base/mixins/SingleObjectMixin.h>
#include "View.h"

template<class T>
class DetailView : public SingleObjectMixin<T>, public View {
public:
    DetailView() = default;
};


#endif //CLASSROOMBOOKINGSYSTEM_DETAILVIEW_H
