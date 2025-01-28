#ifndef _MATCH_GAME_
#define _MATCH_GAME_

#include "matchGame.hpp"
#include <fstream>
#include <string>
#include <time.h>
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

void matchGame::importQuestions(void){

    ifstream inputStream("commands.csv");
    //List<Data> importList;
    if (!inputStream){
        cout << "File not opened correctly!" << endl;
    }
    else {
        while(!inputStream.eof()){
            string key = "", value = "";
            getline(inputStream, key, ',');
            getline(inputStream, value);
            Data importData(key, value);
            gameList.insertAtFront(importData);
        }
    }
}

void matchGame::printList(void){
    Node<Data>* tempPointer = gameList.pHead;
    while(tempPointer != nullptr){
        //cout << tempPointer->data.key << endl;
        //cout << tempPointer->data.value << endl;
        cout << tempPointer->data;
        tempPointer = tempPointer->pNext;
    }

}

bool matchGame::checkDupes(string target)
{
    bool success = false;
    transform(target.begin(), target.end(), target.begin(), ::tolower); // weeding out edge cases
    Node<Data>* tempNode = gameList.pHead;
    while (tempNode != nullptr){
        if (tempNode->data.key == target || tempNode->data.value == target){
            success = true;
        }
        tempNode = tempNode->pNext;
    }

    return success; 
}

void matchGame::populateQuestion(void)
{
    if (gameList.pHead == nullptr){
        cout << "List is empty, no questions to display!" << endl;
    }
    srand(time(NULL));
    
}

#endif