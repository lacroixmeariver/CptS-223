#ifndef _LIST
#define _LIST
#include <list>
#include "destination.hpp"
using std::list;
using std::ostream;
class ListMyJosephus
{
    private:
    int M, N; // elimination interval, total destinations
    list<Destination> destinationList;

    public:
    // constructor
    ListMyJosephus(int eliminationInterval, int totalDestinations, list<Destination> destList): M(eliminationInterval), N(totalDestinations), destinationList(destList){};
    // destructor 
    ~ListMyJosephus();

    // misc functions 
    void clear();
    int currentSize();
    bool isEmpty();
    list<Destination> eliminateDestination();

    
};

#endif