//
// Created by idok on 1/7/23.
//

#ifndef EX5_OBSERVABLE_H
#define EX5_OBSERVABLE_H


#include <vector>

#include "Observer.h"

class Observable {
public:
    void AddObserver(Observer* observer);
    void RemoveObserver(Observer* observer);
    virtual void NotifyObservers()=0;

protected:
    std::vector<Observer*> observers_;
};



#endif //EX5_OBSERVABLE_H
