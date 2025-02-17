#include <iostream>
#include <ctime>
#include "listJosephus.hpp"
#include "vectorJosephus.hpp"
#include "listTestCases.hpp"
#include "vectorTestCases.hpp"


int main()
{
    srand(time(0));
  
    //ListTest newTestList; 
    //ListMyJosephus test(2, 10); 
    //test.eliminateDestination();
    //newTestList.listSimulation();
    //newTestList.readInN(20);
    //newTestList.printList();
    //ListTest test; 
    //test.runSimulation();
    VectorTest vtest; 
    vtest.runSimulation();
    
    return 0;
}