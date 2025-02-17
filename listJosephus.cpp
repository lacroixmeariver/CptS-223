#include "listJosephus.hpp"

ListMyJosephus::ListMyJosephus(int eliminationInterval, int totalDestinations) : M(eliminationInterval), N(totalDestinations) 
{
    ifstream file("destinations.csv");
    string fileLine;
    //auto it = destinationList.begin();
    for (int i = 0; i < N; i++) // change this number when you're done!1
    {
        getline(file, fileLine, ';');
        destinationList.push_back(Destination(i + 1, fileLine)); 
    }
    file.close();   
}


ListMyJosephus::~ListMyJosephus()
{
    destinationList.clear();
    eliminationSequence.clear();
    
}

Destination& ListMyJosephus::getListHead()
{
    return destinationList.front();
}

list<Destination> &ListMyJosephus::returnEliminated()
{
    return eliminationSequence;
}

void ListMyJosephus::clear()
{
    destinationList.clear();
}

int ListMyJosephus::currentSize()
{
    return destinationList.size();
}

bool ListMyJosephus::isEmpty()
{
    return destinationList.empty();
}

void ListMyJosephus::eliminateDestination()
{
    auto it = destinationList.begin();
    int count  = 1; 
    while (currentSize() > 1)
    {
        if (count % M == 0)
        {
            eliminationSequence.push_back(Destination(it->getPosition(), it->getName()));
            it = destinationList.erase(it); 
            if (it == destinationList.end())
            {
                it = destinationList.begin();
            }
        }
        else
        {
            it++;
        }

        if (it == destinationList.end())
        {
            it = destinationList.begin();
        }

        count++; 
    }
}