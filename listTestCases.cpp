 #ifndef _LIST_TEST
 #define _LIST_TEST
 #include "listJosephus.hpp"
 #include <fstream>
 using std::ifstream; 
 using std::stringstream; 

 void multipleN()
 {
    srand(time(NULL));
    int randomNumber = rand() % 25, N = rand() % 1025, index = 0, containerCount = 0;
    // get <random number> line from commands.csv
    ifstream inputStream("commands.csv");
    string chosenLine, value; 

    for (int i = 0; i < randomNumber; i++)
    {
        getline(inputStream, chosenLine);
        if  (i == randomNumber)
        {
           
        }
    } // at the end of this the random line has been chosen
    
    for (int n = 1; n < 1025; n++)
    {
        
    }   
 }


 #endif