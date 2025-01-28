#ifndef _NODE_
#define _NODE_


template <class T>
class Node{
public:
    T data; 
    Node <T>* pNext; 

    // constructor 
    Node(T newData, Node<T>* newNext = nullptr){
        data = newData;
        pNext = newNext;
    }

  
};

#endif 