#include "listJosephus.hpp"

ListMyJosephus::~ListMyJosephus()
{

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

list<Destination> ListMyJosephus::eliminateDestination()
{
    int count = 1;
    auto it = destinationList.begin(); // start at the beginning of the destination list 
    while(currentSize() > 1)
    {
        if (currentSize() == 1) // if the list size gets down to 1 - "base case"
        {
            return destinationList;  
        }
        if (count % M == 0) // stops at every m-th node
        {
            if (it != destinationList.end()) 
            // if the iterator does NOT land on the last node
            {
                cout << "Node: " << it->getName() << " erased!" << endl;
                it = destinationList.erase(it); 
            }
            else 
            // if it DOES land on the last node, deletes it and circles back
            {
                cout << "Node: " << it->getName() << " erased!" << endl;
                destinationList.erase(it); 
                it = destinationList.begin(); 
            }
        }
        else 
        {
            it++; // moves the iterator forward if not on m-th node  
        }
        if (it == destinationList.end())
        // check to see if the end of the list has been reached, circles back
        {
            it = destinationList.begin();
        }
        count++; 
    }
    cout << "Final destination is: " << destinationList.begin()->getName() << endl;
    return destinationList;
}

