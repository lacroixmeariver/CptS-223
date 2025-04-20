
#ifndef _CONTAINER_ARRAY_
#define _CONTAINER_ARRAY_
//#include "hashmapContainer.hpp"
using namespace std;

template <class T> class Array {
protected:
  int capacity; // total amount this array can hold
  int size;     // the number of elements present
  T *data;      // pointer to the first block of contiguous memory

  // ******************************************* Public data functions start
  // here *******************************************
public:
  // constructor
  Array(int cap) {
    capacity = cap;
    size = 0;
    // try-catch block to catch any memory allocation errors
    try {
      data = new T[capacity]; // allocating space for T objects
    } catch (bad_alloc &error) {
      cout << "Memory failed to allocate for arrayContainer" << error.what()
           << endl;
    }
  }

  // constructor
  Array() {
    size = 0;
    capacity = 0;
    data = nullptr;
  }

  // default constructor
  ~Array() {}

  void insertAtBack(const T &newData) {
    data[size] = newData;
    size++;
  }

  // overloaded subscript operator for being able to access indexes (or is it
  // indices?)
  T &operator[](int index) { return this->data[index]; }

  T *clear() {
    // cout << "Clearing data... " << endl; // debug print
    size = 0;
    delete[] data;
    data = new T[capacity];
    return data;
  }

  void deleteAtFront() {
    for (int i = 1; i < size; i++) {
      data[i - 1] = data[i];
    }
    size -= 1;
  }

  // returns the number of elements stored in this array
  int getSize() { return size; }

  bool isEmpty() { return (!size); }

  void setCapacity(int cap) { data = new T[cap]; }

  //returns new array


  auto subArray(int start, int end) {
    Array result(end - start);
    for (int i = start; i < end; i++) {
      result[i-start] = data[i];
      result.size += 1;
    }
    return result;
  }
  //template <class K, class T>
  // auto& operator=(const Array<T> &rhs) {
  //   if (this != &rhs) {
  //     delete[] data;
  //     data = new T[rhs.capacity];
  //     size = rhs.size;
  //     capacity = rhs.capacity;
  //     for (int i = 0; i < size; i++) {
  //       data[i] = rhs.data[i];
  //     }
  //   }
  //   return *this;
  // }

};

#endif