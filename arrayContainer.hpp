
#ifndef _CONTAINER_ARRAY_
#define _CONTAINER_ARRAY_
using namespace std; 

template <class T>
class Array
{
    protected:

    int capacity; // total amount this array can hold 
    int size; // the number of elements present 
    T* data; // pointer to the first block of contiguous memory 

    // ******************************************* Public data functions start here *******************************************
    public:

    //constructor
    Array(int cap) 
    {
        capacity = cap;
        size = 0;
        // try-catch block to catch any memory allocation errors 
        try
        {
            data = new T[capacity]; // allocating space for T objects 
        }
        catch(bad_alloc& error) 
        {
            cout << "Memory failed to allocate for arrayContainer" << error.what() << endl;
        }
    }

    // constructor 
    Array()
    {
        size = 0;
        capacity = 0; 
        data = nullptr; 
    } 

    // default constructor 
    ~Array(){}

    void insertAtBack(T& newData)
    { 
       data[size] = newData; 
       size++;   
    }

    // overloaded subscript operator for being able to access indexes (or is it indices?)
    T &operator[](int index) 
    {
        return this->data[index]; 
    }

    T* clear()
    {
        //cout << "Clearing data... " << endl; // debug print 
        size = 0; 
        delete[] data; 
        data = new T[capacity]; 
        return data;
    }

    // returns the number of elements stored in this array 
    int getSize()
    {
        return size; 
    }
   
    bool isEmpty()
    {
        return (!size); 
    }

    void setCapacity(int cap)
    {
        data = new T[cap];
    }

};

#endif