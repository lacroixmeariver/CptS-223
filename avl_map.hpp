#pragma once
#include "avl_node.hpp"
#include <queue>
#include <list>

template <class Key, class Value>
class avl_map
{
    private:
    avl_node<Key, Value>* root; // pointer to a node as the root of the tree 

    void insertHelper(avl_node<Key, Value>* &tree, Key keyValue, Value dataValue) // passing in the root pointer + data 
    {
        // tree->setHeight(1 + findMax(nodeHeight(tree->getLeft()), nodeHeight(tree->getRight())));  // moving this here instead of in else statements does the same thing
        // int balanceFactor = getBalanceFactor(tree);

        // if (tree == nullptr)
        // {
        //     tree = new avl_node<Key, Value>(keyValue, dataValue);
        //     return; 
        // }
        if (keyValue < tree->getNodeKey()) // left subtree 
        {
            if (tree->getLeft() == nullptr) // if that first left pointer happens to be empty 
            {
                tree->setLeft(new avl_node<Key, Value>(keyValue, dataValue)); // set it 
                return;
            }
            else 
            {
                insertHelper(tree->getLeft(), keyValue, dataValue); // pass in the left pointer and do it all over // modify getters for this to work 
            }
        }
        if (keyValue > tree->getNodeKey())
        {
            if (tree->getRight() == nullptr)
            {
                tree->setRight(new avl_node<Key, Value>(keyValue, dataValue));
                return;
            }
            else 
            {
                insertHelper(tree->getRight(), keyValue, dataValue);
            }

        }

      
        //cout << "Tree is: " << tree->getNodeKey()<< endl;
        tree->setHeight(1 + findMax(nodeHeight(tree->getLeft()), nodeHeight(tree->getRight())));  // moving this here instead of in else statements does the same thing
        int balanceFactor = getBalanceFactor(tree);
       
        // balancing act 
        // LL, RR, LR, RL
        if (balanceFactor < -1 && tree->getLeft() != nullptr) // LR and LL
        {
            if (keyValue < tree->getLeft()->getNodeKey())  // LL
            {
                rotate(tree, 1);
            }
            else // LR
            {   
                rotate(tree, 2);
            }
           
        
        }
        if (balanceFactor > 1 && tree->getRight() != nullptr) // RL and RR 
        {   
            if (keyValue > tree->getRight()->getNodeKey()) 
            {
                rotate(tree, 3); // RR 
            }
           else 
           {
                rotate(tree, 4); // RL
           }
        }



        return; 

    }
   
    public:
    avl_map(avl_node<Key, Value>* newRoot = nullptr): root(newRoot){} // constructor 


    void rotate(avl_node<Key, Value>* &parentNode, int flag)
    {
    

        switch(flag){
        case 1: //LL Case
        {
            avl_node<Key, Value>* childNode = parentNode->getLeft();
          
            parentNode->setLeft(childNode->getRight()); // parent's right -> child's left subtree 
            childNode->setRight(parentNode); // child's right -> parent node 

            parentNode = childNode; // making the swap 

            parentNode->setHeight(1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))); // updating the heights
            childNode->setHeight(1 + findMax(nodeHeight(childNode->getLeft()), nodeHeight(childNode->getRight())));

            if (parentNode == root) // if the parent is the root - root has to be updated 
            {
                root = childNode;
            }
            
            break; 
        }

        case 2: // LR case 
        {
            avl_node<Key, Value>* childNode = parentNode->getLeft(), *newParent = childNode->getRight(); // new parent for the left rotation first 

            if(childNode == nullptr || childNode->getLeft() == nullptr)
            {
                return; 
            }
            
            childNode->setRight(newParent->getLeft());  // child's right -> new parent's left 
            newParent->setLeft(childNode); // new parent's left -> child

            childNode->setHeight(1 + findMax(nodeHeight(childNode->getLeft()), nodeHeight(childNode->getRight()))); // update the heights for a right rotation now 
            newParent->setHeight(1 + findMax(nodeHeight(newParent->getLeft()), nodeHeight(newParent->getRight())));

            parentNode->setLeft(childNode->getRight()); // right rotation 
            newParent->setRight(parentNode); 

            parentNode->setHeight(1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))); 
            newParent->setHeight(1 + findMax(nodeHeight(newParent->getLeft()), nodeHeight(newParent->getRight())));

            if (parentNode == root) 
            {
                root = newParent;
            }
            
            parentNode = newParent;
            break; 
        }
             
        case 3: 
        {
            // RR case
            avl_node<Key, Value>* childNode = parentNode->getRight();

            parentNode->setRight(childNode->getLeft()); // parent's right pointer points to child's left subtree
            childNode->setLeft(parentNode); // child's left points to parent

            parentNode = childNode;  

            parentNode->setHeight(1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))); // updating the heights
            childNode->setHeight(1 + findMax(nodeHeight(childNode->getLeft()), nodeHeight(childNode->getRight())));

            if (parentNode == root) // if the parent is the root - root has to be updated 
            {
                root = childNode;
            }
           
            break; 
        }
        case 4: // RL case 
        {
            avl_node<Key, Value>* childNode = parentNode->getRight(), *newParent = childNode->getLeft();

            childNode->setLeft(newParent->getRight());
            if(childNode == nullptr || childNode->getLeft() == nullptr)
            {
                return; 
            }
            newParent->setRight(childNode);

            childNode->setHeight(1 + findMax(nodeHeight(childNode->getLeft()), nodeHeight(childNode->getRight()))); 
            newParent->setHeight(1 + findMax(nodeHeight(newParent->getLeft()), nodeHeight(newParent->getRight())));

            parentNode->setRight(newParent->getLeft());
            newParent->setLeft(parentNode);

            parentNode->setHeight(1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))); 
            newParent->setHeight(1 + findMax(nodeHeight(newParent->getLeft()), nodeHeight(newParent->getRight())));

            if (parentNode == root) 
            {
                root = newParent;
            }
            
            parentNode = newParent;
            break; 

        }

        }
    }

    ~avl_map()
    {
        delete root; 
    }

    avl_node<Key, Value>* getRoot()
    {
        return root;
    }    

    void insertNode(Key keyValue, Value dataValue)
    {
        if (root != nullptr) // if the tree is not empty 
        {
            insertHelper(root, keyValue, dataValue); 
        }
        else // otherwise just set the root now 
        {
            root = new avl_node<Key, Value>(keyValue, dataValue);
        }
    }

    void printTree(avl_node<Key, Value>* tree)
    {
        queue<avl_node<Key, Value>*> treeQueue; 
        if (tree == nullptr)
        {
            return;
        }
        treeQueue.push(tree);
        while(!treeQueue.empty())
        {
            avl_node<Key, Value>* tempNode = treeQueue.front();
            cout << tempNode->getNodeKey() << " ";
            treeQueue.pop();
            if (tempNode->getLeft() != nullptr)
            {
                treeQueue.push(tempNode->getLeft());
            }       
            if (tempNode->getRight() != nullptr)
            {
                treeQueue.push(tempNode->getRight());
            }

        }

        // if (tree == nullptr)
        // {
        //     return;
        // }
        // printTree(tree->getLeft());
        // cout << tree->getNodeKey() << " ";
        // printTree(tree->getRight());

        return; 
    }


    int nodeHeight(avl_node<Key, Value>* node)
    {
        if (node == nullptr) 
        {
            return 0; 
        }

        return node->getNodeHeight();
    }

  
    int findMax(int x, int y)
    {
        if (x < y)
        {
            return y;
        }
        else
        {
            return x; 
        }
    }


    int getBalanceFactor(avl_node<Key, Value>* tree)
    {
        if (tree == nullptr)
        {
            return 0;
        }
        else
        {
            return nodeHeight(tree->getRight()) - nodeHeight(tree->getLeft());  // right subtree - left

        }
        
    }   

  class Iterator
  {
    private:
    avl_map<Key, Value> &nodeRef; 
    public:
    Iterator(avl_map<Key, Value> &map) : nodeRef(map){}

    bool hasNext()
    {
        if (nodeRef.getRoot() != nullptr)
        {
            return true; 
        }
        else
        {
            return false;
        }
    }
    avl_node<Key, Value> next()
    {
        return nodeRef.getRoot();
    }
  }; 

  Iterator getIterator()
  {
    return Iterator(*this);
  }


};


