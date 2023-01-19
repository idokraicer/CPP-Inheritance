//
// Created by idok on 1/7/23.
//

#include "Observable.h"

void Observable::AddObserver(Observer* observer) { // add an observer to the list of observers
    observers_.push_back(observer); // add the observer to the list
}

void Observable::RemoveObserver(Observer* observer) {
    // Find the observer in the list and remove it.
    for (auto it = observers_.begin(); it != observers_.end(); ++it) { // iterate over the observers
        if (*it == observer) { // if the observer is found
            observers_.erase(it); // remove the observer from the list
            break;
        }
    }
}

