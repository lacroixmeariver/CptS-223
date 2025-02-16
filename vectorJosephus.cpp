#include "vectorJosephus.hpp"

VectorMyJosephus::~VectorMyJosephus()
{

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

vector<Destination> VectorMyJosephus::eliminateDestination()
{
    int count = 1;
    auto it = destinationVector.begin(); // start at the beginning of the destination list 
    while(currentSize() > 1)
    {
        if (currentSize() == 1) // if the list size gets down to 1 - "base case"
        {
            return destinationVector;  
        }
        if (count % M == 0) // stops at every m-th node
        {
            if (it != destinationVector.end()) 
            // if the iterator does NOT land on the last node
            {
                cout << "Node: " << it->getName() << " erased!" << endl;
                it = destinationVector.erase(it); 
            }
            else 
            // if it DOES land on the last node, deletes it and circles back
            {
                cout << "Node: " << it->getName() << " erased!" << endl;
                destinationVector.erase(it); 
                it = destinationVector.begin(); 
            }
        }
        else 
        {
            it++; // moves the iterator forward if not on m-th node  
        }
        if (it == destinationVector.end())
        // check to see if the end of the list has been reached, circles back
        {
            it = destinationVector.begin();
        }
        count++; 
    }
    cout << "Final destination is: " << destinationVector.begin()->getName() << endl;
    return destinationVector;
}
