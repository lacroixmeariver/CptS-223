#ifndef J_LIST
#define J_LIST
#include <string>
#include <iostream> // delete this before running
using std::string; 
using std::endl;
using std::cout;
using std::cin; 
using std::ostream;

class Destination
{
    private: 
    int position; 
    string name; 

    public:
    //constructor 
    Destination(int positionIndex, string destinationName) : position(positionIndex), name(destinationName){};
    //destructor
    ~Destination();
    //getter, setter
    int getPosition();
    string getName();

    //misc functions 
    void printPosition();
    void printDestinationName();
    
};

#endif