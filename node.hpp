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

    friend ostream& operator<<(ostream& lhs, Node<T>& rhs){ // friend so the data can be read
    lhs << rhs.data << endl;
    return lhs;
    }
};

#endif 