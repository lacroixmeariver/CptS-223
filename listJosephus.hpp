#ifndef _LIST
#define _LIST
#include <list>
#include <fstream>
#include "destination.hpp"
using std::list;
using std::stack;
using std::ostream;
using std::ofstream;
using std::ifstream;

class ListMyJosephus
{
    private:
    int M, N; // elimination interval, total destinations
    list<Destination> destinationList;
    list<Destination> eliminationSequence;

    public:
    // constructor
    ListMyJosephus(int eliminationInterval, int totalDestinations); // okay now your constructor has the list 
    // destructor 
    ~ListMyJosephus();
    // getter 
    Destination& getListHead();
    list<Destination>& returnEliminated();

    // misc functions 
    void clear();
    int currentSize();
    bool isEmpty();
    void eliminateDestination();



    
   
    
};

#endif