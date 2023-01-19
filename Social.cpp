//
// Created by idok on 1/6/23.
//

#include "Social.h"


void Social::print() const { // print the social

    cout << "Person:" << this->getFirstname() << " "
       << this->getLastname() << ", Id:" << this->getId()
       << ", Power:" << this->power << ", Type:"
       << 'S' << ", Chairman: " << (this->chairman ?
                                    this->chairman->getFirstname() :
                                    "None") << endl;

}

int Social::getPowerDuringPrimaries() { // get the power of the social during the primaries
    return this->power * 2; // the power of the social is double the power of the politician
}

