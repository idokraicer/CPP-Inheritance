//
// Created by idok on 1/9/23.
//

#include "PoliticalSys.h"

bool compareParties(Party *p1, Party *p2) { // for sorting the biggest party vector
    return p1->getSize() <= p2->getSize(); // If p1 is bigger than p2, return true
}

bool PoliticalSys::politicianInVector(vector<Politician *> politicians, Politician *politician) { // check if politician is in vector
    if(politician == nullptr || politicians.empty()) // if politician is null or vector is empty
        return false;
    for (auto p: politicians) { // for each politician in vector
        if (p == politician) return true; // if politician is in vector return true
    }
    return false;
}

void PoliticalSys::heapifyBiggestVector() { // heapify the biggest party vector
    make_heap(_biggestParty.begin(), _biggestParty.end(),
              [](Party *a, Party *b) { return compareParties(a, b); }); // make heap
}

ostream &operator<<(ostream &os, const PoliticalSys &politicalSys) { // print the political system operator
    os << "Parties:" << endl;
    for (auto party: politicalSys._parties) {
        party->print();
    }
    os << "Politicians:" << endl;
    for (auto politician: politicalSys._politicians) {
        politician->print();
    }
    return os;
}

void PoliticalSys::addParty() { // add party
    string name;
    cout << "Name: " << endl;
    cin >> name; // get name
    char type;
    cout << "Republican or Democratic party " << endl;
    cin >> type;
    if (cin.fail() || checkIfValidParty(name) || (type != 'R' && type != 'D')) { // if cin failed or party name is invalid or type is invalid
        throw InvalidDetails();
    }
    if (type == 'R') { // if type is republican
        addParty(name, type);
        for (auto r: _republicans) { // for each republican in republicans vector
            addRepublicanToParty(r, _republicanParties[_republicanParties.size() - 1]); // add republican to party if conditions are met
        }
    } else if (type == 'D') { // if type is democratic
        addParty(name, type);
        for (auto d: _democrats) { // for each democrat in democrats vector
            addDemocraticToParty(d, _democraticParties[_democraticParties.size() - 1]); // add democrat to party if conditions are met
        }
    }

}

void PoliticalSys::addPolitician() { // add politician
    string firstname;
    cout << "First name: " << endl;
    cin >> firstname; // get first name
    string lastname;
    cout << "Last name: " << endl;
    cin >> lastname; // get last name
    int id;
    cout << "ID: " << endl;
    cin >> id; // get id
    int power;
    cout << "Power: " << endl;
    cin >> power; // get power
    char RorD;
    cout << "Republican or Democratic person " << endl;
    cin >> RorD; // get republican or democratic
    char type;
    cout << "Leader or Social " << endl;
    cin >> type; // get type
    if (cin.fail() || (RorD != 'R' && RorD != 'D') || (type != 'L' && type != 'S')
        || (power < 0) || (id < 0) || (firstname.empty()) || (lastname.empty()) || (checkIfValidID(id))) {
        // if cin failed or type is invalid or power is invalid or id is invalid or first name is empty or last name is empty or id is already in use
        throw InvalidDetails(); // throw exception
    }
    Politician *politician;
    if (RorD == 'R') { // if republican
        politician = new Republican(firstname, lastname, id, power, type); // create republican
        _republicans.push_back((Republican *) politician); // add republican to republicans vector
        addRepublicanToParty(politician); // add republican to party if conditions are met
    } else if (RorD == 'D') { // if democratic
        politician = new Democratic(firstname, lastname, id, power, type); // create democratic
        _democrats.push_back((Democratic *) politician); // add democratic to democrats vector
        addDemocraticToParty(politician); // add democratic to party if conditions are met
    }
    _politicians.push_back(politician); // add politician to politicians vector
}

void PoliticalSys::addRepublican(Politician *republican) { // add republican
    _republicans.push_back(republican); // add republican to republicans vector
    _politicians.push_back(republican); // add republican to politicians vector
}

void PoliticalSys::addDemocratic(Politician *democratic) {
    _democrats.push_back(democratic); // add democratic to democrats vector
    _politicians.push_back(democratic); // add democratic to politicians vector
}

void PoliticalSys::removePolitician() {
    int ID;
    cout << "Enter the ID: " << endl;
    cin >> ID; // get id
    if(_politicians.empty()) return; // if politicians vector is empty exit
    if (cin.fail() || !checkIfValidID(ID)) { // if cin failed or id is invalid
        cin.clear(); // clear cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin
        throw InvalidID(); // throw exception
    }
    for (auto politician: _politicians) { // for each politician in politicians vector
        if (politician->getId() == ID) { // if politician id is equal to id
            if (politician->getParty() != nullptr) { // if politician has party
                politician->getParty()->removePolitician(politician); // remove politician from party
            }
            _politicians.erase(remove(_politicians.begin(), _politicians.end(), politician), _politicians.end()); // remove politician from politicians vector
            this->heapifyBiggestVector(); // heapify the biggest party vector
            if (this->politicianInVector(_republicans, politician)) { // if politician is in republicans vector
                _republicans.erase(remove(_republicans.begin(), _republicans.end(), politician), _republicans.end()); // remove politician from republicans vector
            }
            if (this->politicianInVector(_democrats, politician)) { // if politician is in democrats vector
                _democrats.erase(remove(_democrats.begin(), _democrats.end(), politician), _democrats.end()); // remove politician from democrats vector
            }
            delete politician; // delete politician
            break; // break the loop
        }
    }

}


void PoliticalSys::removeParty() { // This function removes a party
    // The function removes every polititian from the party and then removes the party
    string name; //name of the party
    cout << "Enter party name: " << endl; //ask for the name of the party
    cin >> name; //get the name of the party
    if(_parties.empty()) return; //if there are no parties, return
    if (cin.fail() || !checkIfValidParty(name)) { //if the input is invalid, throw an exception
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidName();
    }
    for (auto party: _parties) { //for every party
        if (party->getName() == name) { //if the name of the party is the same as the name we got
            vector<Politician *> ps = party->getPoliticians(); //get the politicians in the party
            party->leader = nullptr; //set the leader to null
            party->NotifyObservers(); //notify the observers
            if(party->getSize() == 0 ) { //if the party is empty
                _parties.erase(remove(_parties.begin(), _parties.end(), party), _parties.end()); //remove the party from the vector
                for(auto p: _republicanParties){ // If the party is a republican party, remove it from the republican parties vector
                    if(p->getName() == name){
                        _republicanParties.erase(remove(_republicanParties.begin(), _republicanParties.end(), p), _republicanParties.end());
                        }
                }
                for(auto p: _democraticParties){ // If the party is a democratic party, remove it from the democratic parties vector
                    if(p->getName() == name){
                        _democraticParties.erase(remove(_democraticParties.begin(), _democraticParties.end(), p), _democraticParties.end());
                        }
                }
                _biggestParty.erase(remove(_biggestParty.begin(), _biggestParty.end(), party), _biggestParty.end()); //remove the party from the biggest party vector
                this->heapifyBiggestVector(); //heapify the biggest party vector
                delete party; //delete the party
                break; //break the loop
            }
            char type = politicianInVector(_republicans, ps.front()) ? 'R' : 'D'; //check if the party is republican or democratic
            for (auto politician: ps) { //for every politician in the party
                politician->setParty(nullptr); //set the politician's party to null
                if (type == 'R') { //if the party is republican, remove the politician from the republican vector
                    _republicanParties.erase(remove(_republicanParties.begin(), _republicanParties.end(), party),
                                             _republicanParties.end());

                    addRepublicanToParty(politician); //add the politician to a party
                } else { //if the party is democratic, remove the politician from the democratic vector
                    _democraticParties.erase(remove(_democraticParties.begin(), _democraticParties.end(), party),
                                             _democraticParties.end());

                    addDemocraticToParty(politician); //add the politician to a party
                }
            }
            _parties.erase(remove(_parties.begin(), _parties.end(), party), _parties.end()); //remove the party from the parties vector
            _biggestParty.erase(remove(_biggestParty.begin(), _biggestParty.end(), party), _biggestParty.end()); //remove the party from the biggest party vector
            this->heapifyBiggestVector(); //heapify the biggest party vector
            delete party; //delete the party
            break; //break the loop
        }
    }
}

void PoliticalSys::elections() { // This function runs the elections
    if (_politicians.size() == 0 || _parties.size() == 0) return; // If there are no politicians or parties, exit
    // _parties are sorted by time in the system, so if there is a tie, the oldest one will win.
    cout << "----Primaries----" << endl;
    for (auto party: _parties) { // For each party
        party->preformPrimaries(); // Run primaries
        cout << (party->getLeader() == nullptr ? "None" : party->getLeader()->getFirstname()) << " is the chairman of " << party->getName() << endl;
        // Print the leader of the party, if there is no leader, print "None"
    }
    cout << "----Elections----" << endl;
    int maxPower = -1; // Set max power to -1 so the first party will be the biggest
    Party *maxPowerParty = nullptr; // Set max power party to null
    for (auto party: _parties) { // For each party
        if (party->power() > maxPower) { // If the party's power is bigger than the max power
            maxPower = party->power(); // Set the max power to the party's power
            maxPowerParty = party; // Set the max power party to the party

        }
        cout << "Party: " << party->getName() << ",Power: " << party->power() << endl; // Print the party's name and power
    }
    cout << "----Elections Results----" << endl;
    cout << maxPowerParty->getName() << " party won the elections and " << (maxPowerParty->getLeader() == nullptr ? "None" : maxPowerParty->getLeader()->getFirstname())
         << " is the prime minister" << endl; // Print the party that won the elections and the leader of the party,
         // if there is no leader, print "None"
}

void PoliticalSys::BiggestParty() { // This function prints the biggest party
    if (_biggestParty.size() == 0) return; // If there are no parties, exit
    cout << "----Biggest Party----" << endl;
    Party *front = _biggestParty.front(); // Get the biggest party
    cout << "[" << front->getName() << "," << front->getSize() << "]" << endl; // Print the biggest party's name and size
}

PoliticalSys::PoliticalSys(char *filename) { // This function loads the data from the file
    ifstream file(filename); // Open the file
    if (!file.is_open()) { // If the file is not open, exit the configuration function
        cout << "File not found" << endl;
        return;
    }
    string line; // Create a string to hold the line
    getline(file, line); // Get the first line
    if (line[line.size() - 1] == '\r') line.erase(line.size() - 1); // If the last character is '\r', erase it
    while (getline(file, line)) { // read politicians
        if (line[line.size() - 1] == '\r') line.erase(line.size() - 1); // If the last character is '\r', erase it
        if (line.rfind("Parties:", 0) == 0) break; // If the line starts with "Parties:", break the loop
        string firstname;
        string lastname;
        int id;
        int power;
        char RorD;
        char type;
        istringstream ss(line); // Create a string stream from the line
        ss >> firstname >> lastname >> id >> power >> RorD >> type; // Read the data from the line
        Politician *politician; // Create a politician pointer
        if (RorD == 'R') { // If the politician is republican
            politician = new Republican(firstname, lastname, id, power, type);
            _republicans.push_back(politician); // Add the politician to the republican vector
        } else if (RorD == 'D') { // If the politician is democratic
            politician = new Democratic(firstname, lastname, id, power, type);
            _democrats.push_back(politician); // Add the politician to the democratic vector
        }
        _politicians.push_back(politician); // Add the politician to the politicians vector
    }
    while (getline(file, line)) { // Read parties
        if (line[line.size() - 1] == '\r') line.erase(line.size() - 1); // If the last character is '\r', erase it
        string name;
        char RorD;
        istringstream ss(line); // Create a string stream from the line
        ss >> name >> RorD; // Read the data from the line
        addParty(name, RorD); // Add the party to the parties and assign the right type of party
    }
    this->heapifyBiggestVector(); // Heapify the biggest party vector
}

void PoliticalSys::printPoliticians() {
    cout << "----Politicians----" << endl;
    for (auto politician: _politicians) { // For each politician
        politician->print(); // Print the politician
    }
}

void PoliticalSys::printParties() {
    cout << "----Parties----" << endl;
    for (auto party: _parties) { // For each party
        party->print(); // Print the party
    }
}

void PoliticalSys::addParty(string name, char t) {

    if (t == 'R') { // If the party is republican
        RepublicanParty *party = new RepublicanParty(name); // Create a republican party
        _parties.push_back(party); // Add the party to the parties vector
        _biggestParty.push_back(party); // Add the party to the biggest party vector
        _republicanParties.push_back(party); // Add the party to the republican parties vector
        for (auto r: _republicans) { // For each republican
            addRepublicanToParty(r, party); // Add the republican to the party if conditions are met
        }
    } else if (t == 'D') { // If the party is democratic
        DemocraticParty *party = new DemocraticParty(name); // Create a democratic party
        _parties.push_back(party); // Add the party to the parties vector
        _biggestParty.push_back(party); // Add the party to the biggest party vector
        _democraticParties.push_back(party); // Add the party to the democratic parties vector
        for (auto d: _democrats) { // For each democratic
            addDemocraticToParty(d, party); // Add the democratic to the party if conditions are met
        }
    }

}

PoliticalSys::~PoliticalSys() { // This function deletes all the data
    for (auto politician: _politicians) { // For each politician
        delete politician; // Delete the politician
    }
    for (auto party: _parties) { // For each party
        delete party; // Delete the party
    }
    _biggestParty.clear(); // Clear the biggest party vector
    _democrats.clear(); // Clear the democratic vector
    _democraticParties.clear(); // Clear the democratic parties vector
    _parties.clear(); // Clear the parties vector
    _politicians.clear(); // Clear the politicians vector
    _republicans.clear(); // Clear the republican vector


}

void PoliticalSys::addRepublicanToParty(Politician *r) { // This function adds a republican to a party
    if (_republicanParties.empty() || r == nullptr) { // If there are no republican parties or the republican is null, exit
        return;
    }
    Party *currParty = r->getParty(); // Get the republican's party
    for (auto p: _republicanParties) { // For each republican party
        if (currParty == nullptr) { // If the republican is not in a party
            p->addPolitician(r); // Add the republican to the party
            r->setParty(p); // Set the republican's party to the party
            currParty = p; // Set the current party to the party
            continue; // Continue to the next party
        } else if (p->getSize() < currParty->getSize()) { // If the party is smaller than the current party
            currParty->removePolitician(r); // Remove the republican from the current party
            p->addPolitician(r); // Add the republican to the party
            r->setParty(p); // Set the republican's party to the party
            currParty = p; // Set the current party to the party
        }
    }
    this->heapifyBiggestVector(); // Heapify the biggest party vector
}

void PoliticalSys::addRepublicanToParty(Politician *r, Party *p) { // This function adds a republican to a party if conditions are met
    if (p == nullptr || r == nullptr) return; // If the party or the republican is null, exit
    if (r->getParty() == nullptr) { // If the republican is not in a party
        p->addPolitician(r); // Add the republican to the party
        r->setParty(p); // Set the republican's party to the party
    } else if (p->getSize() < r->getParty()->getSize()) { // If the party is smaller than the republican's party and the republican is in a party

        r->getParty()->removePolitician(r); // Remove the republican from the republican's party
        p->addPolitician(r); // Add the republican to the party
        r->setParty(p); // Set the republican's party to the party
    }
    this->heapifyBiggestVector(); // Heapify the biggest party vector
}

void PoliticalSys::addDemocraticToParty(Politician *d) { // This function adds a democratic to a party
    if (_democraticParties.empty() || d == nullptr) { // If there are no democratic parties or the democratic is null, exit
        return;
    }
    Party *currParty = d->getParty(); // Get the democratic's party
    for (auto p: _democraticParties) { // For each democratic party
        if (currParty == nullptr) { // If the democratic is not in a party
            p->addPolitician(d); // Add the democratic to the party
            d->setParty(p); // Set the democratic's party to the party
            currParty = p; // Set the current party to the party
            continue; // Continue to the next party
        } else if (p->getSize() < currParty->getSize()) { // If the party is smaller than the current party
            currParty->removePolitician(d); // Remove the democratic from the current party
            p->addPolitician(d); // Add the democratic to the party
            d->setParty(p); // Set the democratic's party to the party
            currParty = p; // Set the current party to the party
        }
    }
    this->heapifyBiggestVector(); // Heapify the biggest party vector
}

void PoliticalSys::addDemocraticToParty(Politician *d, Party *p) { // This function adds a democratic to a party if conditions are met
    if (p == nullptr || d == nullptr) return; // If the party or the democratic is null, exit
    if (d->getParty() == nullptr) { // If the democratic is not in a party
        p->addPolitician(d); // Add the democratic to the party
        d->setParty(p); // Set the democratic's party to the party
    } else if (p->getSize() < d->getParty()->getSize()) { // If the party is smaller than the democratic's party and the democratic is in a party
        d->getParty()->removePolitician(d); // Remove the democratic from the democratic's party
        p->addPolitician(d); // Add the democratic to the party
        d->setParty(p); // Set the democratic's party to the party
    }
    this->heapifyBiggestVector(); // Heapify the biggest party vector
}


bool PoliticalSys::checkIfValidID(int id) { // This function checks if an id is valid
    for (auto politician: _politicians) { // For each politician
        if (politician->getId() == id) { // If the id is the same as the politician's id
            return true; // Return true
        }
    }
    return false; // Return false if the id is not found
}

bool PoliticalSys::checkIfValidParty(string basicString) { // This function checks if a party is valid
    for (auto party: _parties) { // For each party
        if (party->getName() == basicString) { // If the name is the same as the party's name
            return true; // Return true
        }
    }
    return false; // Return false if the name is not found
}
