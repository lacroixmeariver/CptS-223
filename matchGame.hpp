#ifndef _MATCH
#define _MATCH

#include "header.hpp"
#include "node.hpp"
#include "list.hpp"
#include "data.hpp"


class matchGame{

public:
List<Data> gameList; 

void displayMenu(void);
void importQuestions(void);
void printList(void);
bool checkDupes(string target);
void populateQuestion(void);

private:



};

#endif