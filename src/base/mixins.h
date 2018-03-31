//
// Created by ajatprabha on 31/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_MIXINS_H
#define CLASSROOMBOOKINGSYSTEM_MIXINS_H

#include "models.h"

template<class T>
class SingleObjectMixin : public Model<T> {
protected:
    T *object = nullptr;
public:
    static T *getObject(int passedId);
};

template<class T>
T *SingleObjectMixin<T>::getObject(int passedId) {
    T *objectPointer = nullptr;
    auto it = T::all().find(passedId);
    if (it != T::all().end()) {
        objectPointer = dynamic_cast<T *> (&it->second);
    }
    return objectPointer;
}

#endif //CLASSROOMBOOKINGSYSTEM_MIXINS_H
