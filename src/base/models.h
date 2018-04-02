//
// Created by ajatprabha on 12/3/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_MODELS_H
#define CLASSROOMBOOKINGSYSTEM_MODELS_H

#include <map>
#include <fstream>
#include "exceptions.h"

using namespace std;


template<class T>
class Model {
protected:
    int id;
    static map<int, T> objectList;
public:
    Model();

    static map<int, T> &all();

    virtual T &save();

    virtual bool remove();

    static T *findById(int id);

    bool operator==(const Model &rhs) const;

    bool operator!=(const Model &rhs) const;

    int getId() const;

    static void writeToFile(const string &filename);

    static void readFromFile(const string &filename);

    void setId(int id);
};

template<class T>
map<int, T> Model<T>::objectList = {};

template<class T>
Model<T>::Model() {
    auto it = objectList.end();
    if (objectList.size() > 0) {
        id = (--it)->second.id + 1;
    } else {
        id = 1;
    }
}

template<class T>
map<int, T> &Model<T>::all() {
    return Model<T>::objectList;
}

template<class T>
T &Model<T>::save() {
    Model<T>::objectList.insert(pair<int, T>(this->id, dynamic_cast<T &> (*this)));
    return dynamic_cast<T &> (*this);
}

template<class T>
bool Model<T>::remove() {
    Model<T>::objectList.erase(this->id);
    return true;
}

template<class T>
T *Model<T>::findById(int id) {
    auto it = objectList.find(id);
    if (it != objectList.end()) {
        return &(dynamic_cast<T &> (it->second));
    }
    return nullptr;
}

template<class T>
bool Model<T>::operator==(const Model &rhs) const {
    return id == rhs.id;
}

template<class T>
bool Model<T>::operator!=(const Model &rhs) const {
    return !(rhs == *this);
}

template<class T>
void Model<T>::writeToFile(const string &filename) {
    fstream file;
    file.open(filename, ios::out | ios::trunc | ios::binary);
    if (!file) {
        cout << "Error in creating file '" + filename + "'" + "\n";
    }
    for (auto &i : Model<T>::objectList) {
        file.write((char *) &(i.second), sizeof(i.second));
    }
    file.close();
}

template<class T>
void Model<T>::readFromFile(const string &filename) {
    fstream file;
    file.open(filename, ios::in | ios::out | ios::binary);
//    if (!file) {
//        cout << "Error in opening file '" + filename + "'" + "\n";
//    }
    T object;
    while (file.read((char *) &object, sizeof(object))) {
        Model<T>::objectList.insert(pair<int, T>(object.id, object));
    }
    file.close();
}

template<class T>
int Model<T>::getId() const {
    return id;
}

template<class T>
void Model<T>::setId(int id) {
    Model::id = id;
}


#endif //CLASSROOMBOOKINGSYSTEM_MODELS_H
