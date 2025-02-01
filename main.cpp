#include "header.hpp"
#include "data.hpp"
#include "node.hpp"
#include "list.hpp"
#include "matchGame.hpp"



int main(void){
    srand(time(NULL));
    matchGame testGame;
    testGame.importQuestions();
    testGame.displayMenu();
    //testGame.printList();
    //testGame.askQuestion();


    return 0; 
}
