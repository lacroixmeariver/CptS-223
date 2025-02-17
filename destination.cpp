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

ostream& operator<<(ostream& lhs, const Destination& rhs)
{
    lhs << "Position: " << rhs.position << ", " << "Destination: " << rhs.name << ", ";
    return lhs;
}
