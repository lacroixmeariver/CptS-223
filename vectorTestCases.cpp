#include "vectorTestCases.hpp"

void VectorTest::runSimulation()
{
    ofstream programLog("program.log"); 
    if (programLog.is_open())
    {
       
        for (int N = 1; N < MAX_N; N++)
        {
            
            int M = rand () % N + 1; 
            clock_t k = clock();
            clock_t start;
            do start = clock();
            while (start == k);
            VectorMyJosephus test(M,N);
            clock_t end = clock(); 
            double elapsedTime = static_cast<double>(end - start)/CLOCKS_PER_SEC; 
            cout << "Time: " << elapsedTime << endl; 
            test.eliminateDestination(); 
            programLog << "********** Elimination index: **********" << endl; 
            programLog << "Elapsed time in seconds: " << elapsedTime << endl  
            << M << ", Number of values: " << N << ", Final destination: " 
            << "[" << test.getVectorHead().getPosition() <<  "]" << ", [" << test.getVectorHead().getName() << "]" << endl; 
            programLog << "Elimination sequence:" << endl; 
            for (auto it = test.returnEliminated().begin(); it != test.returnEliminated().end(); it++)
            {
                programLog << "Index eliminated: " << it->getPosition() /*<< ", " << it->getName()*/ << endl;
            }
        }
    }
   
}