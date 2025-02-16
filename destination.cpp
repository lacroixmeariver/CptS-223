#include "destination.hpp"

Destination::~Destination()
{
    //cout << "Destructor for destination activated!" << endl;
}

int Destination::getPosition()
{
    return position; 
}

string Destination::getName()
{
    return name;
}

void Destination::printPosition()
{
    cout << "Position: " << position << endl;
}

void Destination::printDestinationName()
{
    cout << "Destination: " << name << endl;
}

