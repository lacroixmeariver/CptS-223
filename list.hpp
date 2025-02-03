#ifndef _LIST
#define _LIST

#include "node.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <class T>
class List
{

public:
    Node<T> *pHead;

    // constructor
    List(Node<T> *newHead = nullptr)
    {
        pHead = newHead;
    }
    ~List(){ cout << "In destructor!" << endl;};

    // getter for the beginning of the list
    Node<T> *getHead(void)
    {
        return pHead;
    }

    Node<T> *listHead(void)
    {
        if (!isEmpty())
        {
            return pHead;
        }
        else
        {
            cout << "Empty list!" << endl;
        }
    }

    bool insertAtFront(Node<T> newData)
    {
        bool success = false;
        Node<T> *tempData = new Node<T>(newData);
        // check if list is empty first
        if (pHead == nullptr)
        {
            pHead = tempData;
            success = true;
        }
        else if (pHead != nullptr)
        { // if this list is not empty
            
            tempData->pNext = pHead;
            pHead = tempData;
            success = true;
            
        }
        return success;
    }

    bool deleteNode(Node<T> *nodeToDelete)
    {
        bool success = false;
        if (pHead == nullptr)
        { // if list is empty
            cout << "List is already empty, nothing to delete!" << endl;
            return success;
        }
        
        Node<T> *tempPointer = pHead; // 
        Node<T> *prevPointer = nullptr;
        
        if (tempPointer->data == pHead->data)
        { 
            pHead = tempPointer->pNext;

            delete(tempPointer);
            cout << "Element deleted" << endl;
            success = true; 
            return success;
        }
        while (tempPointer != nullptr && prevPointer->data != nodeToDelete->data)
        {
            prevPointer = tempPointer;
            tempPointer = tempPointer->pNext;
        }
        if (tempPointer->pNext == nullptr)
        {
            if (tempPointer->data == nodeToDelete->data)
            {
                if (prevPointer != nullptr)
                {
                    prevPointer->pNext = nullptr;
                }
               
                delete (tempPointer);
                
                success = true;
                return success;
            }
            cout << "Command not found!" << endl;
            success = false;
            return success;
        }

        prevPointer->pNext = tempPointer->pNext;
        delete (tempPointer);
        success = true;
        cout << "Command deleted successfully!" << endl;

        return success;
    }

    void printList(void)
    {
        Node<T> *tempPointer = pHead;
        if (tempPointer == nullptr)
        {
            cout << "List is empty, nothing to print!" << endl;
            return;
        }
        while (tempPointer != nullptr)
        {
            cout << tempPointer->data << endl;
            tempPointer = tempPointer->pNext;
        }
    }

    bool isEmpty(void)
    {
        return pHead == nullptr;
    }
};

#endif