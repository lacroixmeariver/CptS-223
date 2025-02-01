#ifndef _MATCH_GAME_
#define _MATCH_GAME_

#include "matchGame.hpp"
#include <fstream>
#include <string>
#include <ctime>
using std::ifstream;
using std::ofstream;



void matchGame::displayMenu(void){
    cout << "Hello!" << "\n" << "Please select"
    " one of the following:\n";
    int choice = -1; 
    do {
        cout << "[1] Game Rules \n"
        "[2] Play New Game \n"
        "[3] Load Previous Game\n"
        "[4] Add Command\n"
        "[5] Remove Command\n"
        "[6] Display All Commands\n"
        "[7] Save and Exit\n";
        cin >> choice; 
        system("clear");
        switch(choice)
        {
        case 1: 
        displayRules();
        break;

        case 2:
        int keepGoing; 
        askName();
        system("clear");
        cout << "Press any key..."<< endl;
        system("read");
        system("clear");
        while(askQuestion() == true)
        {   
            askQuestion();
        
        }
        break;

        case 3:
        loadGame();
        break;

        case 4: 
        addCommand();
        break; 

        case 7:
        saveAndExit();
        exit(0);
        break;
        }

    
    }while(choice != 7);

   
   
   

}

void matchGame::importQuestions(void){

    ifstream inputStream("commands.csv");
    //List<Data> importList;
    int counter = 0;
   

    if (!inputStream){
        cout << "File not opened correctly!" << endl;
    }
    else {
    string key = "", value = "", points = "";
    int pointValue = 0;
        while(getline(inputStream, key, ',') && getline(inputStream, value, ',') && getline(inputStream, points, '\n')){
            //cout << "Points output:" << points << endl;
            pointValue = std::stoi(points);
            Data importData(key, value, pointValue);
            gameList.insertAtFront(importData);
            ++counter;
        }
    }
    listSize = counter;
    inputStream.close();
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

void matchGame::printCommands(void)
{
     Node<Data>* tempPointer = gameList.pHead;
    while(tempPointer != nullptr){
        //cout << tempPointer->data.key << endl;
        //cout << tempPointer->data.value << endl;
        cout << tempPointer->data.key << endl;
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

bool matchGame::askQuestion(void)
{
    string choices[4] = {"", "", "", ""}; 
    Node<Data>* tempNode = gameList.pHead;
    if (gameList.pHead == nullptr){
        cout << "List is empty, no questions to display!" << endl;
    }
    
    int randomNumber = generateRandomNumber();
    for (int i = 0; i < randomNumber; ++i){
        tempNode = tempNode->pNext;
    }
    cout << "What command best fits this description?" << endl << tempNode->data.value << endl;
    int correctIndex = rand() % 4;
    choices[correctIndex] = tempNode->data.key;
    for(int i = 0; i < 4; i++){
        string distractor = keyBank[rand() % listSize];
        if (choices[i] == "")
        {   
            while(distractor == tempNode->data.key || distractor.empty()){
                distractor = keyBank[rand() % listSize];
            }

            choices[i] = distractor;
        }
    }
    for (int i = 0; i < 4; ++i){
        cout << "#" << i+1 << " " << choices[i] << endl; 
    }

    int answer = 0;
    cin >> answer;

    if (answer == 0){
        return false; 
    }

    if (choices[answer -1] == tempNode->data.key){
        // process correct answer
        playerPoints += tempNode->data.pointValue;
        cout << "Correct!" << endl;
        cout << "Total points for " << playerName << ":" << playerPoints << endl;
        correctAnswers++;
        cout << correctAnswers<<endl;
        incorrectAnswers = 0;
        tempNode->data.pointValue += playerPoints; 
        if (correctAnswers >= 3){
            cout << "Bonus points awarded!" << endl;
            playerPoints += (0.25 * tempNode->data.pointValue);
        }
    } 
    else {
        playerPoints -= tempNode->data.pointValue;
        cout << "Incorrect! :(" << endl; // am i going to let this go beyond 0?
        cout << "Total points for " << playerName << ":" << playerPoints << endl;
        incorrectAnswers--;
        correctAnswers = 0;
        tempNode->data.pointValue -= playerPoints; 
        if (incorrectAnswers >= 3){
            cout << "Bonus deduction!" << endl;
            playerPoints -= (0.15 * tempNode->data.pointValue);
        }
    }
    return true;
}

int matchGame::generateRandomNumber(void)
{
    return rand() % listSize;
}

void matchGame::displayRules(void)
{
    cout << "Rules:" << "\n" << "You are given the definition of a command, your "
    "job is to match it to the corresponding key out of the 4 options given."
    " If you're correct, you earn points! If you're incorrect, you are deducted points. Bonus points are awarded for 3+ streaks,"
    " as well as negative bonuses for 3+ incorrect streaks. \nHappy guessing!" << endl;
}

void matchGame::askName(void)
{
    cout << "Please enter name: " << endl;
    string name; 
    cin >> name; 
    playerName = name; 
}

void matchGame::saveAndExit(void)
{
    ofstream outputStream;
    outputStream.open("gameRecords.csv", std::ios::app);
    outputStream << "Player name" << "," << "Points" << endl; 
    outputStream << playerName << "," << playerPoints << endl;
    outputStream.close();
}

void matchGame::loadGame(void)
{
    
    ifstream inputFile("gameRecords.csv");
    string line, name, points;
    string answer = "q";
    getline(inputFile, line); // throwing away first line 
    getline(inputFile, name, ',');
    getline(inputFile, points);
    cout << "Is this you? [y/n]" << endl;
    cout << "Player name: " << name <<  endl;
    cin >> answer;
    
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower); // making it all lowercase 
    if (answer == "y"){
        playerName = name;
        playerPoints = stoi(points);
    }
    while (answer == "n"){
        getline(inputFile, line); // throwing away first line because it repeats every save game 
        getline(inputFile, name, ',');
        getline(inputFile, points);
        cout << "Is this you? [y/n]" << endl;
        cout << "Player name: " << name <<  endl;
        cin >> answer;
    }

}

void matchGame::addCommand(void)
{
    string newKey = "" , newKeyValue = "";
    int newPointValue;

    cout << "Please enter command key: " << endl;
    cin >> newKey;

    cout << "Please enter command key value: " << endl;
    cin >> newKeyValue;

    cout << "Please enter command point value: " << endl;
    cin >> newPointValue;

    Data newEntry(newKey, newKeyValue, newPointValue); 
    if (checkDupes(newKey)!= true) {
        gameList.insertAtFront(newEntry); 
    }
    else {
        char choice;
        cout << "Duplicate key value found, would you like to see the commands list? [y/n]" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){ //  too lazy to do that to upper stuff here 
            system("clear");
            printCommands();
        }
        else if (choice == 'n' || choice == 'N'){
            //cout << "back to main menu..." << endl;
            return;
        }
        else {
            cout << "Invalid input, did you want to see the list?" << endl;
            cin >> choice;
        }
        
        
    }

}

void matchGame::removeCommand(void)
{
    cout << "Remove command: " << "\n" << "[1] I know which command I want to delete\n[2] Show me the list of commands" << endl;
    int answer = -1;
    cin >> answer;
    if (answer == 1){
        string keyToErase;
        Node<Data>* tempNode = gameList.pHead;
        cout << "Enter command you'd like to remove: " << endl;
        cin >> keyToErase;
        transform(keyToErase.begin(), keyToErase.end(), keyToErase.begin(), ::tolower);
        while(tempNode->data.key != keyToErase){
            tempNode = tempNode->pNext;
        }
        
    }
    else if(answer == 2){
        printCommands();
    }
    else {
        cout << "Invalid option, please select one of the following: " << endl;
        cout << "Remove command: " << "\n" << "[1] I know which command I want to delete\n[2] Show me the list of commands" << endl;
        cin >> answer;
    }

}

#endif