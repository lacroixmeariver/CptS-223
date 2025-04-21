#ifndef SORTS_HPP
#define SORTS_HPP
#include "arrayContainer.hpp"
#include "hashmapContainer.hpp"

template <class K, class T> // node class
class Sorts {
public:
  // static functions so that I don't need an object instance to run these
  static auto insertionSort(typename Hashmap<K, T>::Node *listHead, bool (*comparator)(const T &, const T &)) { // lambda function pointer
    // comparator function pointer -> function that compares 2 T type values and returns based on which comparator is called
    Array<typename Hashmap<K, T>::Node *> listArray = arrayify(listHead); // turn the list passed in into an array for easier indexing
    for (int j = 1; j < listArray.getSize(); j++) { // starting at 1, nothing to compare on the left at [0]
      int k = j;
      while (k > 0 && comparator(listArray[k - 1]->nodeData, listArray[k]->nodeData)) {
        swap(listArray, k - 1, k);  // performing swap
        k--;
      }
    }
    return listArray; // returns sorted list
  }

  static auto swap(Array<typename Hashmap<K, T>::Node *> listArray, int x, int y) {
    auto temp = listArray[x]; // performing a swap
    listArray[x] = listArray[y];
    listArray[y] = temp;
    return listArray;
  }

  // helper function that takes a list and turns it into an array for easier swapping
  static auto arrayify(typename Hashmap<K, T>::Node *listHead) {
    Array<typename Hashmap<K, T>::Node *> listArray(1000);
    for (auto it = listHead; it != nullptr; it = it->mpNext) {
      listArray.insertAtBack(it);
    }
    return listArray;
  }

  static auto mergeSort(Array<typename Hashmap<K, T>::Node *> listArray, bool (*comparator)(const T &, const T &)) {
    if (listArray.getSize() <= 1) {
      return listArray;
    }
    int mid = listArray.getSize() / 2;
    auto leftArray = listArray.subArray(0, mid);
    auto rightArray = listArray.subArray(mid, listArray.getSize());
    return merge(mergeSort(leftArray, comparator),mergeSort(rightArray, comparator), comparator);
  }

  static auto merge(Array<typename Hashmap<K, T>::Node *> leftArray, Array<typename Hashmap<K, T>::Node *> rightArray, bool (*comparator)(const T &, const T &)) {
    Array<typename Hashmap<K, T>::Node *> sortedArray(1000);
    int i = 0, j = 0;
    while (i < leftArray.getSize() && j < rightArray.getSize()) { // comparing and adding until one of the arrays is completely parsed through
      if (comparator(leftArray[i]->nodeData, rightArray[j]->nodeData)) {
        sortedArray.insertAtBack(rightArray[j]);
        j++;
      }
      else {
        sortedArray.insertAtBack(leftArray[i]);
        i++;
      }
    }
    // adding the remaining elements from whichever array still has elements
    while (i < leftArray.getSize() && leftArray[i] != nullptr) {
      sortedArray.insertAtBack(leftArray[i]);
      i++;
    }
    while (j < rightArray.getSize() && rightArray[j] != nullptr) {
     sortedArray.insertAtBack(rightArray[j]);
      j++;
    }
    return sortedArray;
  }
};

// one of the functions below is chosen depending on the one called in app class
// hinges on the overloaded operators in the Product class
template <class T> bool descendingCompare(const T &x, const T &y) {
  return x < y;
}

template <class T> bool ascendingCompare(const T &x, const T &y) {
  return x > y;
}

#endif // SORTS_HPP
