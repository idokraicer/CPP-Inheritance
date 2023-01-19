//
// Created by idok on 1/6/23.
//

#include "Leader.h"
#include <iostream>

Leader::Leader(const string &firstname, const string &lastname, int id,
               int power) : Politician(firstname, lastname, id, power){ // constructor
}


void Leader::print() const { // print the politician

    cout << "Person:" << this->getFirstname() << " "
       << this->getLastname() << ", Id:" << this->getId()
       << ", Power:" << this->power << ", Type:"
       << 'L' << ", Chairman: " << (this->chairman ?
                                                    this->chairman->getFirstname() :
                                                    "None") << endl;

}

int Leader::getPowerDuringPrimaries() {
    return this->power; // the power of the leader is the same during primaries
}



