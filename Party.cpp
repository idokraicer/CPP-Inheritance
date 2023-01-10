//
// Created by idok on 1/6/23.
//

#include "Party.h"

Party::Party(const string &name) {
    this->name = name;
    leader = nullptr;
    size = 0;
}

void Party::NotifyObservers() {
    for (auto observer : this->observers_) {
        observer->Update(this->leader);
    }
}


void Party::addPolitician(Politician *politician) {
    politicians.push_back(politician);
    politician->setParty(this);
    size++;
    this->AddObserver(politician);
}

void Party::removePolitician(Politician *politician) {
    for (auto it = politicians.begin(); it != politicians.end(); ++it) {
        if (*it == politician) {
            if(leader == nullptr){;}
            else if(*it == leader){
                leader = nullptr;
                NotifyObservers();
            }
            this->RemoveObserver(politician);
            politicians.erase(it);
            size--;
            break;
        }
    }
}

void Party::print() const {
    cout << " party: " << this->name << ", chairman:"
         << (this->leader ? this->leader->getFirstname() : "None")
         << ", Size: " << this->size << endl;
    for (auto politician: this->politicians) {
        cout << "\t";
        politician->print();
    }
}

void Party::preformPrimaries() {
    int maxPower = 0;
    Politician *maxPowerPolitician = nullptr;
    for (auto politician: this->politicians) {
        if (politician->ableToRunForPresident() && politician->getPowerDuringPrimaries() > maxPower) {
            maxPower = politician->getPowerDuringPrimaries();
            maxPowerPolitician = politician;
        }
    }
    if (maxPowerPolitician != nullptr) {this->leader = maxPowerPolitician;}
    this->NotifyObservers();
}

int Party::getSize() const {
    return politicians.size();
}

bool Party::operator>(const Party &other) const {
    return this->size > other.size;
}

Politician* Party::getLeader() {
    return leader;
}

int Party::power() const {
    int sum=0;
    for(auto politician : politicians){
        sum+=politician->getPowerDuringPrimaries();
    }
    return sum;
}

bool Party::containsPolitician(Politician *politician) const {
    for(auto politician : politicians){
        if(politician == politician) return true;
    }
    return false;
}

vector<Politician*> Party::getPoliticians() {
    return politicians;
}


