
#ifndef _SCRATCH_VECTOR_
#define _SCRATCH_VECTOR_
using namespace std; 

/*        !!TODO!!

- still need copy assignment assignment operator and copy contructor 
- double check cppreference for any functions that might be integral to this 
- does this even work idk

*/


template <class T>
class Vector_
{
    private:
    int capacity; // total amount this vector can hold 
    int size; // the number of elements present 
    T* data; // pointer to the first block of contiguous memory 

    // resizing function returns the address to the new vector
    T* resizeVector()
    {
        // it's my first time implementing a try-catch block, I haven't gotten comfortable with it but now is a good a time as any
        // some advice when reading about how they work was to pass a reference to the error in so it could be read in
        // the exception handler
        try
        {
            //cout << "Resizing..." << endl; // debug print
            int newCapacity = capacity * 2 + 1; 
            T* tempContainer = new T[newCapacity];
            for (int i = 0; i < capacity; i++)
            {
                tempContainer[i] = data[i];
            }
            delete[] data;
            data = tempContainer; 
            capacity = newCapacity;
            //cout << "Resizing successful, new capacity is: " << capacity << " items." << endl;
            return tempContainer; 
        }
        catch(std::bad_alloc& error)
        {
            cout << "Memory allocation unsuccessful!" << error.what() << endl; 
        }
       
     
    }; 


    public:

    //constructor
    Vector_(int cap) : capacity(cap) 
    {
        size = 0;
        data = new T[capacity]; // allocating space for T objects 
        // only allocating enough memory for the capacity upon creation
    }
    Vector_()
    {
        capacity = 11; 
        size = 0;
        data = new T[capacity];
    }

    ~Vector_()
    {
        //cout << "Inside destructor for vector!" << endl; // debug print
        //delete[] data; // subscript operator in this case makes sure destructor is called for every T object 
    }

    void insertAtBack(T& newData)
    { 
        if (isEmpty()) // empty vector 
        {
            
            size++; 
            data[0] = newData;
            //cout << "First element inserted" << endl;
            return; 
        }

        if (size < capacity)
        {
            data[size] = newData; 
            size++; 
            return; 
        }
        else if (size > capacity * .8) // once it's 80% full 
        {
            resizeVector();
            insertAtBack(newData); 
        }
       
    }

    void deleteAtBack()
    {
        if (isEmpty())
        {
            cout << "Vector is empty, nothing to delete!" << endl;
            return; 
        } 
        size--; 
    }

    // overloaded subscript operator for being able to access indexes (or is it indices?)
    T &operator[](int index) 
    {
        return data[index]; 
    }

    T* clear()
    {
        cout << "Clearing data... " << endl; // debug print 
        size = 0; 
        delete[] data; 
        data = new T[capacity]; 
        return data;
    
    }
    
    // returns the number of elements stored in this vector 
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

    

};

#endif