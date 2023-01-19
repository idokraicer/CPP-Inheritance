//
// Created by idok on 1/9/23.
//

#ifndef EX5_POLITICALSYS_H
#define EX5_POLITICALSYS_H
#include "Politician.h"
#include "Party.h"
#include "DemocraticParty.h"
#include "RepublicanParty.h"
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <bits/stdc++.h>
#include "Error.h"


class PoliticalSys {
private:
    vector<Party*> _parties;
    vector<Politician*> _politicians;
    vector<Politician*> _democrats;
    vector<Politician*> _republicans;
    vector<RepublicanParty*> _republicanParties;
    vector<DemocraticParty*> _democraticParties;
    vector<Party*> _biggestParty;
public:
    PoliticalSys(char *string1); // Constructor, gets a file name
    void addParty(); // Add a party to the system
    void addParty(string, char); // Add a party to the system
    void addPolitician(); // Add a politician to the system
    void addRepublican(Politician* republican); // Add a politician to the system
    void addDemocratic(Politician* democratic); // Add a politician to the system
    void addRepublicanParty(RepublicanParty* republicanParty); // Add a politician to the system
    void addDemocraticParty(DemocraticParty* democraticParty); // Add a politician to the system
    void printParties(); // Print all parties in the system
    void printPoliticians(); // Print all politicians in the system
    friend ostream& operator<<(ostream& os, const PoliticalSys& politicalSys);
    void removePolitician(); // Remove a politician from the system
    void removeParty(); // Remove a party from the system

    void elections(); // Run elections

    void BiggestParty(); // Print the biggest party in the system

    virtual ~PoliticalSys(); // Destructor
    bool checkIfValidID(int id); // Check if a given ID is valid


    bool politicianInVector(vector<Politician *> politicians, Politician *politician); // Check if a given politician is in a given vector

    bool checkIfValidParty(string basicString); // Check if a given party is valid

    void heapifyBiggestVector(); // Heapify the biggest party vector

    void addRepublicanToParty(Politician* r); // Add a republican to a party
    void addDemocraticToParty(Politician* d); // Add a democratic to a party

    void addRepublicanToParty(Politician *r, Party *p); // Add a republican to a party
    void addDemocraticToParty(Politician *d, Party *p); // Add a democratic to a party
};


#endif //EX5_POLITICALSYS_H
