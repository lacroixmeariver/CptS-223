#ifndef _LIST
#define _LIST

#include "node.hpp"
#include <iostream> 
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <class T>
class List{

public:
    Node <T>* pHead; 

    // constructor 
    List(Node <T>* newHead = nullptr){
        pHead = newHead;
    }
    
    // getter for the beginning of the list
    Node <T>* getHead(void){
        return pHead;
    }

    bool insertAtFront(Node<T> newData){
        bool success = false;
        Node<T>* tempData = new  Node<T>(newData);
        // check if list is empty first 
        if (pHead == nullptr){
            pHead = tempData;
            success = true; 
        }
        else if (pHead != nullptr){ // if this list is not empty, meaning replace the head and tie it to the old head 
            tempData->pNext = pHead;
            pHead = tempData;
            success = true;
        }
        return success;
    }

    bool deleteAtFront(){
        bool success = false;
        if (pHead == nullptr){ // if list is empty 
            cout << "List is already empty, nothing to delete!" << endl;
        }
        else {
            Node<T>* temp = pHead;
            pHead = pHead->pNext;
            delete temp; 
            success = true;
        }
        return success;
    }

   
  




};

#endif 