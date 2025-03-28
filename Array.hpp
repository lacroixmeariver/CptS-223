
#ifndef _CONTAINER_ARRAY_
#define _CONTAINER_ARRAY_
using namespace std; 

/*        !!TODO!!

- still need copy assignment assignment operator and copy constructor 
- double check cppreference for any functions that might be integral to this 
- does this even work idk
- turn this into an array otherwise it just gets too complicated 

*/

template <class T>
class Array
{
    protected:

    int capacity; // total amount this array can hold 
    int size; // the number of elements present 
    T* data; // pointer to the first block of contiguous memory 

    public:

    //constructor
    Array(int cap) 
    {
        capacity = cap;
        size = 0;
        try
        {
            data = new T[capacity]; // allocating space for T objects 
        }
        catch(std::bad_alloc& error)
        {
            cout << "Memory failed to allocate for Array" << endl;
        }
    }
    Array() : size(0), capacity(0), data(nullptr) {}

    ~Array() {}

    void insertAtBack(T& newData)
    { 
       data[size] = newData; 
       size++;   
    }

    void deleteAtBack()
    {
        if (isEmpty())
        {
            cout << "Array is empty, nothing to delete!" << endl;
            return; 
        } 
        size--; 
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

    T* begin()
    {
        return *data[0];
    }

    T* end()
    {
        return *data[size - 1]; 
    }

    void setCapacity(int cap)
    {
        data = new T[cap];
    }

    Array& operator=(const Array& other)
    {
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        } 

        return *this;
    }

};

#endif