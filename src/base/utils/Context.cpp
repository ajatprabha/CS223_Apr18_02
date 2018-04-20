//
// Created by ajatprabha on 12/3/18.
//

#include "Context.h"

Context::Context(BaseUser *passedUser, int passedRequestObjectId) {
    user = passedUser;
    requestObjectId = passedRequestObjectId;
}