
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
  bool (*comparator)(const T&, const T&)){ // lambda function pointer
    // comparator function pointer -> function that compares 2 T type values
    Array<typename Hashmap<K, T>::Node*> listArray = arrayify(listHead);
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

  // helper function that takes a list and turns it into an array for easier swapping
  static auto arrayify(typename Hashmap<K, T>::Node * listHead) {
    Array<typename Hashmap<K, T>::Node *> listArray(50);
    int i = 0;
    for (auto it = listHead; it != nullptr; it = it->mpNext) {
      listArray.insertAtBack(it);
      i++;
    }
    return listArray;
  }

  static auto mergeSort(Array<typename Hashmap<K, T>::Node *> listArray, bool (*comparator)(const T&, const T&)) {
    if (listArray.getSize() <= 1) {
      return listArray;
    }
    int mid = listArray.getSize() / 2;
    auto leftArray = listArray.subArray(0, mid);
    auto rightArray = listArray.subArray(mid, listArray.getSize());
    return merge(mergeSort(leftArray, comparator), mergeSort(rightArray, comparator), comparator);
  }


  static auto merge(Array<typename Hashmap<K, T>::Node *> leftArray, Array<typename Hashmap<K, T>::Node *> rightArray, bool (*comparator)(const T&, const T&)) {
    Array<typename Hashmap<K, T>::Node *> sortedArray(50);
    int i = 0, j = 0;
    while (i < leftArray.getSize() && j < rightArray.getSize()) {
      if (comparator(leftArray[i]->nodeData, rightArray[j]->nodeData)) {
        sortedArray.insertAtBack(rightArray[j]);
        j++;

      }
      else {
        sortedArray.insertAtBack(leftArray[i]);
        //rightArray.deleteAtFront();
        i++;
      }
    }
   if (i > j && leftArray[i] != nullptr) {
     for (int k = i; k < leftArray.getSize(); k++) {
       sortedArray.insertAtBack(leftArray[k]);
     }
   }
   else {
     for (int k = j; k < rightArray.getSize(); k++) {
       sortedArray.insertAtBack(rightArray[k]);
      }
    }

    return sortedArray;
  }
  

};

// one of the functions below is chosen depending on the one called in app class
template<class T>
bool descendingCompare(const T& x, const T& y) {
  return x < y;
}

template<class T>
bool ascendingCompare(const T& x, const T& y) {
  return x > y;
}



#endif // SORTS_HPP
