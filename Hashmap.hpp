#ifndef _HASHMAP_
#define _HASHMAP_

#include <iostream>
#include "Vector_.hpp"
#include "List_.hpp"
using namespace std; 

template<class K, class T>
class Hashmap
{
    private:
    struct Pair
    {
        K key;
        T value; 
        Pair(K newKey, T newValue) : key(newKey), value(newValue) {}; 

        // so Pairs can print 
       friend ostream& operator<<(ostream& lhs, const Pair& rhs) 
       {
            lhs << "{" << rhs.key << ", " << rhs.value << "}";
            return lhs;
        }
        
    }; 

    Vector_< List<Pair>* > mMap; 
    int capacity;
    int size; 

    public:

    // constructor 
    Hashmap(int cap) : capacity(cap)
    {
        size = 0; 
        for (int i = 0; i < capacity; i++)
        {
            List<Pair>* newList = new List<Pair>(); 
            mMap.insertAtBack(newList);
        }
         
    }

    // destructor 
    ~Hashmap(){}; 

    void insert(K keyVal, T data)
    {
        size_t index = hash<K>()(keyVal) % mMap.getSize(); 
        cout << "Index: " << index << endl; 
        mMap[index]->insertFront(Pair(keyVal, data)); 
    }

    void printIndexList(K keyVal)
    {
        size_t index = hash<K>()(keyVal) % mMap.getSize();
        mMap[index]->printList(); 
    }


    

}; 


#endif