//
// Created by idok on 1/7/23.
//

#ifndef EX5_OBSERVER_H
#define EX5_OBSERVER_H


class Observable;

// The Observer class defines an interface for receiving updates from the
// Observable.
class Observer { // Abstract Observer class
public:
    virtual void Update(Observer *observer) = 0; // update the observer
};


#endif //EX5_OBSERVER_H
