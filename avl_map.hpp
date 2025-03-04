#pragma once
#include "avl_node.hpp"
#include <queue>
using namespace std; 

template <class Key, class Value>
class avl_map
{
    private:
    avl_node<Key, Value>* mpRoot; // pointer to a node as the root of the tree 

    // private version of the insert function, public facing call does not have access to the root 
    avl_node<Key, Value>* insertHelper(avl_node<Key, Value>*& root, Key newKeyValue, Value newDataValue) // passing by reference retains changes outside of this scope 
    {
        // recursive insert portion, finds available node to insert to
        if (root == nullptr)
        { 
            root = new avl_node<Key, Value>(newKeyValue, newDataValue);
            return root; 
        }

        if (newKeyValue < root->getNodeKey()) //  traverses left subtree 
        {
            insertHelper(root->getLeft(), newKeyValue, newDataValue);
        }
        else if (newKeyValue > root->getNodeKey()) // traverses right subtree
        {
            insertHelper(root->getRight(), newKeyValue, newDataValue);
        }
        else // if it's not less or more than 
        {
            return root; 
        }

        // updating the height of the grandparent node 
        root->setHeight(1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))); 
        int balanceFactor = (root == nullptr) ? 0 : nodeHeight(root->getLeft()) - nodeHeight(root->getRight()); // 0 if null ptr, evaluated otherwise 
        //cout << "Balance factor is: " << balanceFactor << endl; // [debug print]

        // balancing cases LL, RR, LR, RL
        if (balanceFactor < -1) // RR and RL cases 
        {
            if (newKeyValue < root->getRight()->getNodeKey() && root->getRight() != nullptr) // RL case 
            {
                // right rotation first RL -> RR
                root->setRight(rightRotation(root->getRight()));
                // then left 
                root = leftRotation(root);
                return root;
            }
            else // RR case 
            {
                // rotate left 
                root = leftRotation(root);
                return root;
            }

        }
        else if (balanceFactor > 1) // LL and LR cases 
        {
            if (newKeyValue > root->getLeft()->getNodeKey() && root->getLeft() != nullptr) // LR case 
            {
                // performing left rotation first so LR -> LL
                root->setLeft(leftRotation(root->getLeft()));
                // LL case -> rotate right 
                root = rightRotation(root); 
                return root;
            }
            else // LL case
            {
                // rotating right
                root = rightRotation(root); 
                return root;   
            }

        }

        if (root == mpRoot) // updating the root if that ever needs to happen 
        {
            mpRoot = root; 
        }

        return root; 
    }

    // rotations, moved these into private, don't think they need to be in the public facing side
    // making these helper functions reduces confusion when handling LR and RL cases 
    avl_node<Key, Value>* rightRotation(avl_node<Key, Value>*& root) 
    {
        avl_node<Key, Value>* parentNode = root->getLeft(), *childNode = parentNode->getRight();
        parentNode->setRight(root); // parent's right -> root, this is the node that floats up
        root->setLeft(childNode); // root's left -> child 

        // re-calculating node heights 
        root->setHeight((1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))));
        parentNode->setHeight((1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))));

        if (parentNode == mpRoot) // adjusting if we're handling the actual root 
        {
            mpRoot = root; 
        }

        return parentNode;
    }

    avl_node<Key, Value>* leftRotation(avl_node<Key, Value>*& root)  
    {
        avl_node<Key, Value>* parentNode = root->getRight(), *childNode = parentNode->getLeft(); // rotating left so parent is the root->right child, child is inner left pointer
        parentNode->setLeft(root); // parent node's left -> root
        root->setRight(childNode);
        
        root->setHeight((1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))));
        parentNode->setHeight((1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))));

        if (parentNode == mpRoot)
        {
            mpRoot = root; 
        }
    
        return parentNode;  
    }

    // private side erase node function 
    avl_node<Key, Value>* eraseNodeHelper(avl_node<Key, Value>*& root, const Key& key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->getNodeKey()) // left subtree 
        {
            eraseNodeHelper(root->getLeft(), key);
        }
        if (key > root->getNodeKey()) // right subtree 
        {
            eraseNodeHelper(root->getRight(), key);
        }

        // node that we want to delete is found at this point,  determining what kind of node it might be

        if (root->getLeft() == nullptr || root->getRight() == nullptr) // possible leaves 
        {
            if (root->getLeft() == nullptr && root->getRight() == nullptr) // leaf node, safe to just get rid of 
            {
                delete root; 
                root = nullptr;
            }
            else if (root->getLeft() == nullptr && root->getRight() != nullptr) // if node has right child but not left 
            {
                avl_node<Key, Value>* tempNode = root->getRight();
                *root = *tempNode; // replacing it with it's child 
                delete tempNode;
            }
            else if (root->getRight() == nullptr && root->getLeft() != nullptr) // if node has left child but not right 
            {
                avl_node<Key, Value>* tempNode = root->getLeft();
                *root = *tempNode; // replacing it with it's child 
                delete tempNode;
            }

        }
        else // a node with children on both sides
        {
            avl_node<Key, Value>* tempNode = root->getRight(); // node to take over, smallest node in right ST
            while (tempNode->getLeft() != nullptr) // finding the leftmost node in right ST
            {
                tempNode = tempNode->getLeft();
            }
            
            // handing the information over 
            root->setKey(tempNode->getNodeKey());
            root->setData(tempNode->getData());

            delete root->getRight(); 

        }
    
        if (root == nullptr)
        {
            return root;
        }

        // updating heights + balance factor 
        root->setHeight(1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))); 
        int balanceFactor = (root == nullptr) ? 0 : nodeHeight(root->getLeft()) - nodeHeight(root->getRight());


        // now to do the rotations if need be 
        if (balanceFactor < -1) // RR and RL cases 
        {
            if (key < root->getRight()->getNodeKey() && root->getRight() != nullptr) // RL case 
            {
                root->setRight(rightRotation(root->getRight()));
                root = leftRotation(root);
                return root;
            }
            else 
            {
                // rotate left 
                root = leftRotation(root);
                return root;
            }

        }
        else if (balanceFactor > 1) // LL and LR
        {
            if (key > root->getLeft()->getNodeKey() && root->getLeft() != nullptr) // LR case 
            {
                // performing left rotation first so LR >> LL
                root->setLeft(leftRotation(root->getLeft()));
                // LL case >> rotate right 
                root = rightRotation(root); 
                return root;
            }
            else
            {
                // rotating right
                root = rightRotation(root); 
                return root;
                
            }

        }

        if (root == mpRoot) 
        {
            mpRoot = root; 
        }

        return root; 

    }

    void printTreeHelper(avl_node<Key, Value>* tree)
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

    // **************************** Public access stuff starts here ****************************
    public: 

    // constructor, new root set to nullptr
    avl_map(avl_node<Key, Value>* newRoot = nullptr): mpRoot(newRoot){} 

    ~avl_map()
    {
        delete mpRoot; 
    }

    // getter
    avl_node<Key, Value>* getRoot()
    {
        return mpRoot; 
    }

    // some public calls for private functions ***********************

    // public facing insert call, access to the root 
    void insert(Key newKeyValue, Value newDataValue)  
    {
        insertHelper(mpRoot, newKeyValue, newDataValue);
    }

    void eraseNode(const Key& key)
    {
        eraseNodeHelper(mpRoot, key);
    }

    void printTree()
    {
        printTreeHelper(mpRoot);
    }

    // utility functions ****************************
    int nodeHeight(avl_node<Key, Value>* node)
    {
        if (node == nullptr) 
        {
            return -1; 
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
            return nodeHeight(tree->getLeft()) - nodeHeight(tree->getRight());  // left subtree - right 
        }
    }   
 
 // **************************** iterator ****************************
  class Iterator
  {
    private:
    std::stack<avl_node<Key, Value>*> nodeStack;
    avl_node<Key, Value>* currentNode;

    void nodePush(avl_node<Key, Value>* node) // adding to the stack via leftmost traversal for in-order traversal down the line 
    {
        while (node != nullptr)
        {
            nodeStack.push(node); 
            node = node->getLeft();  // left traversal 
        }

    }

    public:
    Iterator(avl_node<Key, Value>* node) : currentNode(nullptr)
    {
        nodePush(node);
    }

    bool hasNext()
    {
       return !nodeStack.empty();
    }

    avl_node<Key, Value>* next() 
    {
        if (!hasNext()) // if there is no next
        {
            return nullptr;
        }

        currentNode = nodeStack.top(); // processing node 
        nodeStack.pop();

        if (currentNode->getRight() != nullptr)
        {
            nodePush(currentNode->getRight()); // right traversal now 
        }

        return currentNode;
    }

  }; 

  Iterator getIterator()
  {
    return Iterator(mpRoot); // returns node
  }


  Iterator find(const Key& key)  
  {
    avl_node<Key, Value>* currentNode = mpRoot; // starting at the top 
    while (currentNode != nullptr)
    {
        if (key == currentNode->getNodeKey())
        {
            //cout << "Found!" << endl; // [debug print]
            return Iterator(currentNode);
        }
        else if (key < currentNode->getNodeKey()) // go down left subtree 
        {
            currentNode = currentNode->getLeft();
        }
        else if (key > currentNode->getNodeKey()) // go down right 
        {
            currentNode = currentNode->getRight();
        }

        else // if not left or right or the target value, it's not in there
        {
            //cout << "Not found!" << endl; // [debug print]
            return Iterator(nullptr); // not found 
        }
    }
    //cout << "Not found!" << endl; [debug print]
    return Iterator(nullptr); // not found; 
  }

};


