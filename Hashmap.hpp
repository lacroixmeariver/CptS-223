#ifndef _HASHMAP_
#define _HASHMAP_

#include <iostream>
#include "Array.hpp"
#include "List_.hpp"
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
        Node(K newKey, T newData) : nodeKey(newKey), nodeData(newData){};
        Node(){};
   };

   int capacity;
   int size; 
   //int loadFactor; 
   Array<Node*> mapContainer; // array of nodes
   
   public:

   Hashmap(int cap) : capacity(cap), mapContainer(cap)
   {   
       
   } 

   //Hashmap(): mapContainer(nullptr){}

   // destructor
   ~Hashmap()
   {
        cout << "Map destructor called!" << endl; 
   }

   size_t hashFunction(K keyVal)
   {
        
        return hash<K>()(keyVal) % capacity; 
   }




 

   double loadFactor()
   {
        return (static_cast<double>(size)/capacity);   
   }
   
   

   








    

}; 


#endif