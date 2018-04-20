//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_CONTEXT_H
#define CLASSROOMBOOKINGSYSTEM_CONTEXT_H

#include <base/models/BaseUser.h>

struct Context {
    BaseUser *user = nullptr;
    int requestObjectId = -1;

    Context() = default;

    Context(BaseUser *passedUser, int passedRequestObjectId);
};


#endif //CLASSROOMBOOKINGSYSTEM_CONTEXT_H
