//
// Created by idok on 1/6/23.
//

#include "Party.h"

Party::Party(const string &name) : name(name) {
    leader = nullptr;
    size = 0;
}

void Party::NotifyObservers() { // Notify observers using NotifyObservers()
    for (auto observer : this->observers_) { // for each observer in the observers vector
        observer->Update(this->leader); // update the observer with the leader of the party
    }
}


void Party::addPolitician(Politician *politician) { // AddObserver
    politicians.push_back(politician); // add the politician to the politicians vector
    politician->setParty(this); // set the party of the politician to this party
    size++; // increase the size of the party
    this->AddObserver(politician); // add the politician to the observers vector
}

void Party::removePolitician(Politician *politician) { // RemoveObserver
    for (auto it = politicians.begin(); it != politicians.end(); ++it) { // for each politician in the politicians vector
        if (*it == politician) { // if the politician is the politician we want to remove
            if(leader == nullptr){;} // if the leader is null, do nothing
            else if(*it == leader){ // if the politician is the leader
                leader = nullptr; // set the leader to null
                NotifyObservers(); // notify the observers
            }
            this->RemoveObserver(politician); // remove the politician from the observers vector
            politicians.erase(it); // erase the politician from the politicians vector
            size--; // decrease the size of the party
            break; // break the loop
        }
    }
}

void Party::print() const { // print the party
    cout << " Party: " << this->name << ", chairman:"
         << (this->leader ? this->leader->getFirstname() : "None")
         << ", Size:" << this->size << endl;
    for (auto politician: this->politicians) { // for each politician in the politicians vector
        cout << "\t"; // print a tab
        politician->print(); // print the politician
    }
}

void Party::preformPrimaries() { // preform primaries
    int maxPower = 0; // max power
    if(this->politicians.empty()) return; // if the politicians vector is empty, return
    Politician *maxPowerPolitician = nullptr; // max power politician, set default to nullptr
    for (auto politician: this->politicians) { // for each politician in the politicians vector
        if (politician->ableToRunForPresident() && politician->getPowerDuringPrimaries() > maxPower) { // if the politician is able to run for president and his power is bigger than the max power
            maxPower = politician->getPowerDuringPrimaries(); // set the max power to the power of the current politician
            maxPowerPolitician = politician; // set the max power politician to the current politician
        }
    }
    if (maxPowerPolitician != nullptr) {this->leader = maxPowerPolitician;}  // if the max power politician is not null, set the leader to the max power politician
    this->NotifyObservers(); // notify the observers
}

int Party::getSize() const { // get the size of the party
    return politicians.size(); // return the size of the politicians vector
}

bool Party::operator>(const Party &other) const { // operator overloading for comparing parties
    return this->size > other.size; // return true if the size of this party is bigger than the size of the other party
}

Politician* Party::getLeader() { // get the leader of the party
    return leader;
}

int Party::power() const { // get the power of the party
    int sum=0; // sum of the power of the politicians in the party
    for(auto politician : politicians){ // for each politician in the politicians vector
        sum+=politician->getPowerDuringPrimaries(); // add the power of the politician to the sum
    }
    return sum; // return the sum
}



vector<Politician*> Party::getPoliticians() { // get the politicians in the party
    return politicians; // return the politicians vector
}


