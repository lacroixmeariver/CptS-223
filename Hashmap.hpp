#ifndef _HASHMAP_
#define _HASHMAP_

#include <iostream>
#include "Array.hpp"
using namespace std; 

/*        !!TODO!!

- still need copy assignment assignment operator and copy contructor 
- double check cppreference for any functions that might be integral to this 
- need rehashing function
    -- all elements of the hashmap are iterated and their new bucket positions are calculated 
    using the new hash function that corresponds to the new size of the hashmap 
    

*/

template<class K, class T>
class Hashmap
{
    protected:

    struct Node
    {
            K nodeKey; 
            T nodeData; 
            Node* mpNext; 
            Node(K newKey, T newData) : nodeKey(newKey), nodeData(newData), mpNext(nullptr){};
            Node(){};

        
    };

    int capacity;
    int size; 
    //int loadFactor; 
    Array<Node*> mapContainer; // array of nodes, pointers in the nodes allow for linked lists within array
   
    public:

    // constructor !TODO!
    Hashmap(int initialCapacity) 
    {
        capacity = initialCapacity; 
        mapContainer = Array<Node*>(capacity);
        size = 0; 
    }

    Hashmap(){}

    // destructor
    ~Hashmap()
    {
            cout << "Map destructor called!" << endl; 
    }

    void insert(K keyVal, T dataVal)
    {
            size_t index = hashFunction(keyVal); 
            Node* current = mapContainer[index];
            if(current == nullptr) // empty 
            {
                mapContainer[index] = new Node(keyVal, dataVal);  
                size++;
                return;
            }
            if(current != nullptr && loadFactor() < 0.5) // if there's something in there and can fit
            {
                while (current != nullptr)
                {
                    if(current->mpNext == nullptr)
                    {
                        current->mpNext = new Node(keyVal, dataVal); 
                        //cout << "Link attached! " << endl; 
                        size++;
                        return; 
                    }
                    current = current->mpNext; 
                }

            }
            else if (loadFactor() > 0.5)
            {
                //cout << "Gotta hash!" << endl;
                rehash();
            }
    }

    size_t hashFunction(K keyVal)
    {
        return hash<K>()(keyVal) % capacity; 
    }

    double loadFactor()
    {
        return (static_cast<double>(size)/capacity);   
    }
    
 
    void printIndexList(const K& key)
    {
        size_t index = hashFunction(key);
        Node* tempNode = mapContainer[index];
        cout << "Index: " << index << endl;
        if (tempNode != nullptr)
        {
            while(tempNode->mpNext != nullptr)
            {
                cout << tempNode->nodeData << endl; 
                tempNode = tempNode->mpNext; 
            }

        }

        else 
        {
            cout << "No existing entries for: " << key << endl;  
        }

      
    }

    void rehash()
    {
        capacity = capacity * 2; 
        
        
        Array<Node*> tempContainer = mapContainer; 
        mapContainer.clear();
        mapContainer = Array<Node*>(capacity); 

        for (int i = 0; i < tempContainer.getSize(); i++)
        {
            Node* tempNode = tempContainer[i];
            while(tempNode != nullptr)
            {
                insert(tempNode->nodeKey, tempNode->nodeData); 
                tempNode = tempNode->mpNext; 
            }
            
        }
       
    }


    friend ostream& operator<<(ostream& lhs, const Node& rhs)
    {
        lhs << "{" << rhs.nodeKey << ", " << rhs.nodeData << "}" << endl; 
        return lhs; 
    }

    bool find(K key)
    {
        size_t index = hashFunction(key);
        Node* searchField = mapContainer[index];
    
        while (searchField != nullptr)
        {
            if (searchField->nodeKey == key)
            {
                cout << "Found!" << endl; 
                cout << searchField->nodeData; 
                return true;
            }

            searchField = searchField->mpNext; 
        }

        cout << "Not found!" << endl; 
        return false; 
        
    }

 

}; 


#endif