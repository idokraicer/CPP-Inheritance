//
// Created by idok on 1/8/23.
//

#include "DemocraticParty.h"

using namespace std;


void DemocraticParty::print() const { // A print function for DemocraticParty
    cout << "Democrat";
    Party::print(); // print the party using the print function of the Party class
}

