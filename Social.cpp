//
// Created by idok on 1/6/23.
//

#include "Social.h"


void Social::print() const {

    cout << "Person:" << this->getFirstname() << " "
       << this->getLastname() << ", Id:" << this->getId()
       << ", Power:" << this->power << ", Type:"
       << 'S' << ", Chairman: " << (this->chairman ?
                                    this->chairman->getFirstname() :
                                    "None") << endl;

}

int Social::getPowerDuringPrimaries() {
    return this->power * 2;
}

//ostream &operator<<(ostream &os, const Social &social) {
//    cout<<"Leader print."<<endl;
//    return social.print(os);
//}