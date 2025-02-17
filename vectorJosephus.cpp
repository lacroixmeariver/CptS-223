#include "vectorJosephus.hpp"

VectorMyJosephus::VectorMyJosephus(int eliminationInterval, int totalDestinations) : M(eliminationInterval), N(totalDestinations) 
{
    ifstream file("destinations.csv");
    string fileLine;
    //auto it = destinationVector.begin();
    for (int i = 0; i < N; i++) // change this number when you're done!1
    {
        getline(file, fileLine, ';');
        destinationVector.push_back(Destination(i + 1, fileLine)); 
    }
    file.close();   
}


VectorMyJosephus::~VectorMyJosephus()
{
    destinationVector.clear();
    eliminationSequence.clear();
    
}

Destination& VectorMyJosephus::getVectorHead()
{
    return destinationVector.front();
}

vector<Destination> &VectorMyJosephus::returnEliminated()
{
    return eliminationSequence;
}

void VectorMyJosephus::clear()
{
    destinationVector.clear();
}

int VectorMyJosephus::currentSize()
{
    return destinationVector.size();
}

bool VectorMyJosephus::isEmpty()
{
    return destinationVector.empty();
}

void VectorMyJosephus::eliminateDestination()
{
    auto it = destinationVector.begin();
    int count  = 1; 
    while (currentSize() > 1)
    {
        if (count % M == 0)
        {
            eliminationSequence.push_back(Destination(it->getPosition(), it->getName()));
            it = destinationVector.erase(it); 
            if (it == destinationVector.end())
            {
                it = destinationVector.begin();
            }
        }
        else
        {
            it++;
        }

        if (it == destinationVector.end())
        {
            it = destinationVector.begin();
        }

        count++; 
    }
}