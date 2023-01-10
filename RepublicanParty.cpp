//
// Created by idok on 1/8/23.
//

#include "RepublicanParty.h"

//ostream& operator<<(ostream& os, const RepublicanParty& party) {
//    os << "Republican" << party.inner;
//    return os;
//}

//RepublicanParty::RepublicanParty(string name) : Party(name) {
//    this->name = name;
//}

void RepublicanParty::print() const {
    cout << "Republican";
    Party::print();
}
