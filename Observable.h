//
// Created by idok on 1/7/23.
//

#ifndef EX5_OBSERVABLE_H
#define EX5_OBSERVABLE_H


#include <vector>

#include "Observer.h"

class Observable { // Observable class
public:
    void AddObserver(Observer* observer); // add an observer to the list of observers
    void RemoveObserver(Observer* observer); // remove an observer from the list of observers
    virtual void NotifyObservers()=0; // notify the observers

protected:
    std::vector<Observer*> observers_; // list of observers
};



#endif //EX5_OBSERVABLE_H
