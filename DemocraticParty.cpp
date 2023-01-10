//
// Created by idok on 1/8/23.
//

#include "DemocraticParty.h"

using namespace std;

//DemocraticParty::DemocraticParty(string& name) : Party(name) {
//    this->inner = new Party(name);
//}

void DemocraticParty::print() const {
    cout << "Democratic";
    Party::print();
}

DemocraticParty::~DemocraticParty() {
//    delete inner;
}
//ostream& operator<<(ostream& os, const DemocraticParty& party) {
//    os << "Democratic" << party.inner;
//    return os;
//}