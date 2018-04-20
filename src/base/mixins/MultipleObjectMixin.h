//
// Created by ajatprabha on 31/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_MULTIPLEOBJECTMIXIN_H
#define CLASSROOMBOOKINGSYSTEM_MULTIPLEOBJECTMIXIN_H


#include <base/models/Model.h>
#include <vector>

using namespace std;

template<class T>
class MultipleObjectMixin : public Model<T> {
public:
    virtual vector<T> getQueryset() = 0;
};


#endif //CLASSROOMBOOKINGSYSTEM_MULTIPLEOBJECTMIXIN_H
