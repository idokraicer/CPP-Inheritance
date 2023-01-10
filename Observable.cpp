//
// Created by idok on 1/7/23.
//

#include "Observable.h"

void Observable::AddObserver(Observer* observer) {
    observers_.push_back(observer);
}

void Observable::RemoveObserver(Observer* observer) {
    // Find the observer in the list and remove it.
    for (auto it = observers_.begin(); it != observers_.end(); ++it) {
        if (*it == observer) {
            observers_.erase(it);
            break;
        }
    }
}

//void Observable::NotifyObservers() {
//    for (auto observer : observers_) {
//        observer->Update(this);
//    }
//}
