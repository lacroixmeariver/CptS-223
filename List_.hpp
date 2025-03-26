
#ifndef _LIST_
#define _LIST_

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std; 

/*        !!TODO!!

- still need copy assignment assignment operator and copy constructor 
- front and back 
- iterator??
- empty
- size
- push 
- pop
- swap?
- make node helper 


*/


template <class T>
class List
{
    private:

    struct Node
    {
        T data;
        Node* mpNext; 
        Node(T newData) : data(newData), mpNext(nullptr) {}
    };
    
    Node* mList; // pointer node to head of list
    int size; 

    void insertFrontHelper(Node* list, T newData)
    {
        if (list == nullptr) // if it's empty 
        {
            Node* tempBuffer = mList; 
            mList = new Node(newData); 
            mList->mpNext = tempBuffer;
            delete tempBuffer; 
            size++; 
            //cout << "Data inserted: " << mList->data << endl;
            return; 
        }

        insertFrontHelper(list->mpNext, newData); 

    }

    void printListHelper(Node* list)
    {
        if (list == nullptr)
        {
            cout << "End of list" << endl; 
            return;
        }

       cout << list->data << endl; 
       printListHelper(list->mpNext);
    }

    void deleteFrontHelper(Node* list)
    {
        Node* tempBuffer = mList;
        mList = mList->mpNext; 
        delete tempBuffer; 
        return; 
    }

    public:
    
    // constructor 
    List() : mList(nullptr) {}

    // destructor 
    ~List() {} 


    bool isEmpty()
    {
        return mList == nullptr; 
    }

    void insertFront(T newData)
    {
        insertFrontHelper(mList, newData);
    }

    void deleteFront()
    {
        deleteFrontHelper(mList);
    }

    Node* front()
    {
        return mList; 
    }

    void printList()
    {
        printListHelper(mList);
    }




};

#endif