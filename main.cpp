//============================================================================
// Name        : politicalSystem.cpp
// Author      : ADP 23
// Version     : 0.0.0
// Copyright   : Your copyright notice
// Description : Assignment 5 in C++, Ansi-style
//============================================================================



#include "PoliticalSys.h"

int main(int argc, char* argv[]) {

    PoliticalSys* politicalSys = new PoliticalSys(argv[1]);
    char menuOption='1';
    while(menuOption!='0')
    {

        cout<< "1. Add Politician" << endl;
        cout<< "2. Add Party" << endl;
        cout<< "3. Remove Politician" << endl;
        cout<< "4. Remove Party" << endl;
        cout<< "5. Elections" << endl;
        cout<< "6. Print Politicians" << endl;
        cout<< "7. Print Parties" << endl;
        cout<< "8. Biggest Party" << endl;
        cout<< "0. Exit" << endl;
        cin >> menuOption;
        switch(menuOption){
            case '1':
                cout << "---Create Politician---" << endl;
                while(true) {
                    try {
                        politicalSys->addPolitician();
                        break;
                    } catch (Error &e) {
                        cout << e.what();
                    }
                }
                break;
            case '2':
                cout << "---Create Party---" << endl;
                while(true){
                    try{
                        politicalSys->addParty();
                        break;
                    }catch(Error& e){
                        cout << e.what();
                    }
                }
                break;
            case '3':
                cout << "---Remove Politician---" << endl;
                while(true){
                    try{
                        politicalSys->removePolitician();
                        break;
                    }catch(Error& e){
                        cout << e.what();
                    }
                }
                break;
            case '4':
                cout << "---Remove Party---" << endl;
                while(true){
                    try{
                        politicalSys->removeParty();
                        break;
                    }catch(Error& e){
                        cout << e.what();
                    }
                }
                break;
            case '5':
                politicalSys->elections();
                break;
            case '6':
                politicalSys->printPoliticians();
                break;
            case '7':
                politicalSys->printParties();
                break;
            case '8':
                politicalSys->BiggestParty();
                break;
            case '0':
                delete politicalSys;
                break;
        }
    }

    return 0;
}