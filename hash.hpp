#ifndef _HASH
#define _HASH

#include "Vector_.hpp"

template <class K, class T>
class Hashmap
{
    private: 

    struct Pair
    {
        K mKey;
        T dataValue;

        Pair(K keyVal, T newData) : mKey(keyVal), dataValue(newData){}
        Pair() : mKey(), dataValue () {};
    }; 

    Vector_<Pair> mMap; // vector containing pairs at each index
    int size;
    int capacity; 
    

    public:
    // constructor 
    Hashmap(int cap) : capacity(cap)
    {
        
    }

    // destructor
    ~Hashmap(){};

    
}; 

#endif