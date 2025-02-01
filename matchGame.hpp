#ifndef _MATCH
#define _MATCH

#include "header.hpp"
#include "node.hpp"
#include "list.hpp"
#include "data.hpp"
#include <string>
using std::string;


class matchGame{

public:
List<Data> gameList;
int listSize; 
string playerName; 
int playerPoints; 
int correctAnswers;
int incorrectAnswers;
const string keyBank[30] = {"ls", "cd", "mkdir", "rmdir", "rm", "cp", "mv", "ssh", "scp", "man", 
"g++", "gcc", "make", "ps", "kill", "top", "who", "chmod", "cat", "alias", "chown", "df"
, "grep", "echo", "find", "clear", "diff", "env", "free"};

void displayMenu(void);
void importQuestions(void);
void printList(void);
void printCommands(void);
bool checkDupes(string target);
bool askQuestion(void);
int generateRandomNumber(void);
void displayRules(void);
void askName(void);
void saveAndExit(void);
void loadGame(void);
void addCommand(void);
void removeCommand(void);

private:



};

#endif