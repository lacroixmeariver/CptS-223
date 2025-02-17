#ifndef _VECTOR
#define _VECTOR
#include <vector>
#include <fstream>
#include "destination.hpp"
using std::vector ;
using std::stack;
using std::ostream;
using std::ofstream;
using std::ifstream;

class VectorMyJosephus
{
    private:
    int M, N; // elimination interval, total destinations
    vector <Destination> destinationVector;
    vector<Destination> eliminationSequence;

    public:
    // constructor
    VectorMyJosephus(int eliminationInterval, int totalDestinations); // okay now your constructor has the Vector 
    // destructor 
    ~VectorMyJosephus();
    // getter 
    Destination& getVectorHead();
    vector<Destination>& returnEliminated();

    // misc functions 
    void clear();
    int currentSize();
    bool isEmpty();
    void eliminateDestination();



    
   
    
};

#endif