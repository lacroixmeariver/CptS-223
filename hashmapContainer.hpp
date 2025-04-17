#ifndef _HASHMAP_
#define _HASHMAP_
#include "arrayContainer.hpp"
#include <iostream>

// using namespace std;

template <class K, class T> class Hashmap {
public:
  // makes a node within the map class to use with separate chaining
  struct Node {
    K nodeKey;
    T nodeData;
    Node *mpNext;
    Node(K newKey, T newData)
        : nodeKey(newKey), nodeData(newData), mpNext(nullptr) {};
    Node() {};
  };

  int capacity;
  int size;
  Array<Node *> mapContainer; // all values stored in here

  double loadFactor() {
    // cast so integer division doesn't ruin anyone's day
    return (static_cast<double>(size) / capacity);
  }

  void rehash() {
    capacity = capacity * 2; // double the capacity
    Array<Node *> tempContainer =
        mapContainer;     // saving the contents of the old container
    mapContainer.clear(); // clearing main container out
    mapContainer =
        Array<Node *>(capacity); // in with the new one double the size

    // repopulating values with new indexes
    for (int i = 0; i < tempContainer.getSize(); i++) {
      Node *tempNode = tempContainer[i];
      while (tempNode != nullptr) {
        insert(tempNode->nodeKey, tempNode->nodeData);
        tempNode = tempNode->mpNext;
      }
    }
  }

  // ******************************************* Public data functions start
  // here *******************************************
public:
  // constructor
  Hashmap(int initialCapacity) {
    capacity = initialCapacity;
    mapContainer = Array<Node *>(capacity);
    size = 0;
  }

  // default constructor
  Hashmap() {}

  // destructor
  ~Hashmap() {
    // cout << "Map destructor called!" << endl;
  }

  void insert(K keyVal, T dataVal) {
    size_t index = hashFunction(keyVal);
    Node *current = mapContainer[index]; // keeping track of current node for
                                         // separate chaining
    if (current == nullptr)              // empty
    {
      mapContainer[index] = new Node(keyVal, dataVal);
      size++;
      return;
    }
    if (current != nullptr &&
        loadFactor() < 0.5) // if there's something in the same index but
                            // there's room for it in the map
    {
      while (current != nullptr) {
        if (current->mpNext == nullptr) // if the next node is available
        {
          current->mpNext = new Node(keyVal, dataVal);
          size++;
          return;
        }
        current = current->mpNext; // traversing
      }

    } else if (loadFactor() > 0.5) {
      rehash();
    }
  }

  size_t hashFunction(K keyVal) { return hash<K>()(keyVal) % capacity; }

  Node *findByIndex(const K &key) // returns pointer to the node (I hope)
  {
    size_t index = hashFunction(key);
    Node *tempNode = mapContainer[index];

    if (tempNode != nullptr) // if something does exist at this index
    {
      return tempNode;
    } else {
      // cout << "No existing entries for: " << key << endl;
      return tempNode;
    }
    return tempNode;
  }

  Node *find(const K key) {
    size_t index = hashFunction(key);
    Node *searchField = mapContainer[index];

    while (searchField != nullptr) {
      if (searchField->nodeKey == key) {
        // cout << "Found!" << endl;
        return searchField;
      }
      searchField = searchField->mpNext;
    }
    // cout << "Not found!" << endl;
    return searchField;
  }

  int getSize() { return size; }
};

#endif