
#ifndef SORTS_HPP
#define SORTS_HPP
#include "arrayContainer.hpp"
#include "hashmapContainer.hpp"

/* Hash map has an array of node pointers
 * TODO:
 *  - external comparator for the insertion sort
 * 	- need to be able to compare prices for Product class
 * 	- need to change selling price type to int in product class and
 *subsequently in the app class
 *	- need to add subarray function to array container class
 * 	- destructor needs to do some deallocation
 * 	- insert method needs to insert key/val pair
 * 		- call insert again after line 97
 * 	- find should not be doing i/o
 *  - array destructor needs to delete array
 * 	- only create the hashmap once
 *  - product IDs do not match
 * 	- some categories don't print
 *
 * */

template <class K, class T> // node class
class Sorts {

public:
  static auto insertionSort(typename Hashmap<K, T>::Node *listHead,
  bool (*comparator)(T&, T&)){ // lambda function pointer
    // comparator function pointer -> function that compares 2 T type values
    Array<typename Hashmap<K, T>::Node*> listArray = insertionSortHelper(listHead);
    for (int j = 1; j < listArray.getSize(); j++) {
      int k = j;
      while (k > 0 && comparator(listArray[k - 1]->nodeData, listArray[k]->nodeData)) {
        auto temp = listArray[k - 1];
        listArray[k - 1] = listArray[k];
        listArray[k] = temp;
        k--;
      }
    }
    return listArray;
  }

  static Array<typename Hashmap<K, T>::Node *> insertionSortHelper(typename Hashmap<K, T>::Node * listHead) {
    Array<typename Hashmap<K, T>::Node *> listArray(50);
    int i = 0;
    for (auto it = listHead; it != nullptr; it = it->mpNext) {
      listArray.insertAtBack(it);
      i++;
    }
    return listArray;
  }

};

// one of the functions below is chosen depending on the one called in app class
template<class T>
bool descendingCompare(T& x, T& y) {
  return x < y;
}

template<class T>
bool ascendingCompare(T& x, T& y) {
  return x > y;
}



#endif // SORTS_HPP
