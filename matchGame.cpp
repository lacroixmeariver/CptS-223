#include "matchGame.hpp"
#include <fstream>
#include <string>
using std::ifstream;

void matchGame::displayMenu(void){
    cout << "Hello!" << endl << "Please select"
    " one of the following:\n";
    int choice = 0; 
    
    while(choice != 7){
    cout << "[1] Game Rules \n"
    "[2] Play New Game \n"
    "[3] Load Previous Game\n"
    "[4] Add Command\n"
    "[5] Remove Command\n"
    "[6] Display All Commands\n"
    "[7] Save and Exit\n";
    cin >> choice; 
    }
}


