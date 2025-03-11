#include "HeapPriorityQueue.h"
#include <iostream>

// TODO: Implement the constructor
HeapPriorityQueue::HeapPriorityQueue(int newSize = 0) {
    // Initialize size to 0
    size = newSize;
}

// TODO: Implement the destructor
HeapPriorityQueue::~HeapPriorityQueue() {
    // Cleanup if necessary
}

// TODO: Implement the copy constructor
HeapPriorityQueue::HeapPriorityQueue(const HeapPriorityQueue& other) {
    // Copy heap elements and size
    HeapPriorityQueue* tempValue = new HeapPriorityQueue(other); 
    tempValue->size = size;
}

// TODO: Implement the copy assignment operator
HeapPriorityQueue& HeapPriorityQueue::operator=(const HeapPriorityQueue& other) {
    // Assign heap elements and size properly
    int i = 0;
    size = other.size; 
    while(i < other.size)
    {
        heap[i] = other.heap[i];
        size = other.size; 
        i++;
    }
   
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    // Insert new PrinterJob(str, priority) while maintaining heap order using percolateUp
    // minimum value is always the root 
    if (size == 0) // size being zero = empty heap
    {
        // insert function?
        heap[0] = new PrinterJob(str, priority);
    }
}



// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
}


// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob
}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob
}
