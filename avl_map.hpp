#pragma once
#include "avl_node.hpp"
#include <queue>
#include <list>

template <class Key, class Value>
class avl_map
{
    private:
    avl_node<Key, Value>* mpRoot; // pointer to a node as the root of the tree 
    
    public:
    avl_map(avl_node<Key, Value>* newRoot = nullptr): mpRoot(newRoot){} // constructor 

    void insert(Key newKeyValue, Value newDataValue)
    {
        insertHelper(mpRoot, newKeyValue, newDataValue);
    }

    avl_node<Key, Value>* getRoot()
    {
        return mpRoot; 
    }


    avl_node<Key, Value>* insertHelper(avl_node<Key, Value>*& root, Key newKeyValue, Value newDataValue)
    {
        // recursive insert portion, finds available node to insert to
        if (root == nullptr)
        { 
            root = new avl_node<Key, Value>(newKeyValue, newDataValue);
            return root; 
        }

        if (newKeyValue < root->getNodeKey()) // left subtree 
        {
            insertHelper(root->getLeft(), newKeyValue, newDataValue);
        }
        else if (newKeyValue > root->getNodeKey()) // right subtree
        {
            insertHelper(root->getRight(), newKeyValue, newDataValue);
        }
        else // if it's not less or more than it's probably a duplicate 
        {
            return root; 
        }

        // updating the height of the grandparent node 
        root->setHeight(1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))); 
        int balanceFactor = (root == nullptr) ? 0 : nodeHeight(root->getLeft()) - nodeHeight(root->getRight()); // 0 if null ptr, evaluated otherwise 
        //cout << "Balance factor is: " << balanceFactor << endl;

        // balancing cases LL, RR, LR, RL
        
        if (balanceFactor < -1) // RR and RL cases 
        {
            if (newKeyValue < root->getRight()->getNodeKey() && root->getRight() != nullptr) // RL case 
            {
                root->setRight(rightRotation(root->getRight()));
                root = leftRotation(root);
                return root;
            }
            else 
            {
                // RR case 
                // rotate left 
                root = leftRotation(root);
                return root;
            }

        }
        else if (balanceFactor > 1) // 
        {
            if (newKeyValue > root->getLeft()->getNodeKey() && root->getLeft() != nullptr) // LR case 
            {
                // performing left rotation first so LR >> LL
                root->setLeft(leftRotation(root->getLeft()));
                // LL case >> rotate right 
                root = rightRotation(root); 
                return root;
            }
            else
            {
                // LL case 
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

    avl_node<Key, Value>* leftRotation(avl_node<Key, Value>*& root) // making this process a separate helper function helps reduce bogged down code 
    {
        avl_node<Key, Value>* parentNode = root->getRight(), *childNode = parentNode->getLeft(); // rotating left so parent is the root->right child, child is inner left pointer
        parentNode->setLeft(root); // parent node's left -> root
        root->setRight(childNode);
        
        root->setHeight((1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))));
        parentNode->setHeight((1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))));
        //root = childNode;
        if (parentNode == mpRoot)
        {
            mpRoot = root; 
        }

    
        return parentNode;  
    }

    avl_node<Key, Value>* rightRotation(avl_node<Key, Value>*& root) 
    {
        avl_node<Key, Value>* parentNode = root->getLeft(), *childNode = parentNode->getRight();
        parentNode->setRight(root);
        root->setLeft(childNode);
        

        root->setHeight((1 + findMax(nodeHeight(root->getLeft()), nodeHeight(root->getRight()))));
        parentNode->setHeight((1 + findMax(nodeHeight(parentNode->getLeft()), nodeHeight(parentNode->getRight()))));
        //root = childNode;
        if (parentNode == mpRoot)
        {
            mpRoot = root; 
        }

        return parentNode;

    }

    void eraseNode(const Key& key)
    {
        if (mpRoot == nullptr)
        {
            return mpRoot;
        }

        if (key < mpRoot->getNodeKey()) // left subtree 
        {

        }

        else 
    }

    void printTree()
    {
        printTreeHelper(mpRoot);
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


    // Subu taught us its RT - LT but this way makes more sense to me 
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
 
 
  class Iterator
  {
    private:
    std::stack<avl_node<Key, Value>*> nodeStack; 
    avl_node<Key, Value>* currentNode;

    void nodePush(avl_node<Key, Value>* node) 
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

        currentNode = nodeStack.top();
        nodeStack.pop();

        if (currentNode->getRight() != nullptr)
        {
            nodePush(currentNode->getRight()); // right traversal 
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
    avl_node<Key, Value>* currentNode = mpRoot; 
    while (currentNode != nullptr)
    {
        if (key == currentNode->getNodeKey())
        {
            cout << "Found!" << endl;
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
            cout << "Not found!" << endl;
            return Iterator(nullptr); // not found 
        }
    }
    cout << "Not found!" << endl;
    return Iterator(nullptr); // not found; 
  }

};


