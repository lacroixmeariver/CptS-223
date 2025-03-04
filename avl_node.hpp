#pragma once
#include "us_cities.hpp"

template <class Key, class Value> // specifying a different kind of class that'll be included in this that is not class T
class avl_node
{
    private:
    Key key;
    Value data;
    int nodeHeight; 
    avl_node<Key, Value>* left;
    avl_node<Key, Value>* right;

    public: 
    
    // constructor 
    avl_node(Key newKey, Value newData): key(newKey), data(newData), nodeHeight(1), left(nullptr), right(nullptr){}; // setting the left and right pointers to nullptr

    // destructor
    ~avl_node()
    {

    }

    // getters 
    Key getNodeKey()
    {
        return key; 
    }

    avl_node<Key, Value>*& getLeft() // returning references allows for direct modification 
    {
        return left;
    }
    avl_node<Key, Value>*& getRight()
    {
        return right;
    }

    int getNodeHeight()
    {
        return nodeHeight; 
    }

    // setters 
    void setLeft(avl_node<Key, Value>* newLeft)
    {
        left = newLeft; 
    }

    void setRight(avl_node<Key, Value>* newRight)
    {
        right = newRight; 
    }

    void setHeight(int newVal)
    {
        nodeHeight = newVal; 
    }
   


    



};
