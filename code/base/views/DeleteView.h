//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_DELETEVIEW_H
#define CLASSROOMBOOKINGSYSTEM_DELETEVIEW_H


#include <base/mixins/SingleObjectMixin.h>
#include "View.h"

template<class T>
class DeleteView : public SingleObjectMixin<T>, public View {
public:
    void display() override;
};

template<class T>
void DeleteView<T>::display() {
    T *object = SingleObjectMixin<T>::getObject(context.requestObjectId);
    if (object) {
        object->remove();
        cout << "Successfully deleted.\n";
    } else cout << "Not found.\n";
}


#endif //CLASSROOMBOOKINGSYSTEM_DELETEVIEW_H
