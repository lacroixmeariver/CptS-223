#ifndef _VECTOR
#define _VECTOR
#include <vector>
#include "destination.hpp"
using std::vector;
using std::ostream;
class VectorMyJosephus
{
    private:
    int M, N; // elimination interval, total destinations
    vector<Destination> destinationVector;

    public:
    // constructor
    VectorMyJosephus(int eliminationInterval, int totalDestinations, vector<Destination> destVec): M(eliminationInterval), N(totalDestinations), destinationVector(destVec){};
    // destructor 
    ~VectorMyJosephus();

    // misc functions 
    void clear();
    int currentSize();
    bool isEmpty();
    vector<Destination> eliminateDestination();

    
};

#endif