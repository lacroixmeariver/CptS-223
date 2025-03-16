#include "HeapPriorityQueue.h"
#include <iostream>

// TODO: Implement the constructor
HeapPriorityQueue::HeapPriorityQueue(int newSize) {
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
    HeapPriorityQueue tempValue; 
    tempValue.size = other.size; 
    while(i < other.size)
    {
        tempValue.heap[i] = other.heap[i];
        //size = other.size; 
        i++;
    }
   return tempValue;
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    // Insert new PrinterJob(str, priority) while maintaining heap order using percolateUp
    // minimum value is always the root 
  
    insertAtBack(str, priority);



    bool success = false;
    int i = 0; 
    
}



// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
    //cout << "This is working" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Job: " << heap[i].printString << endl; 
    }
}

void HeapPriorityQueue::insertAtBack(const string& str, int priority)
{
    PrinterJob *tempJob = new PrinterJob(str, priority); 
    int i = 0;
    if (isEmpty()) // if the array is empty 
    {
        heap[0] = *tempJob; 
        size ++;  
        return; 
    }

    while(heap[i].printString != "\0")
    {
        i++; 
    }
    heap[i] = *tempJob; 
    //cout << "i - 1 space entered: " << heap[i].printString << endl;
    size++; 
   if (priority < heap[i].priority)
   {
        // percolate up
        percolateUp(i); 
   }

}

bool HeapPriorityQueue::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false; 
}

// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob

    
    int i = index; 
    while(index <= heap[i - 1].priority) // continue to bubble up while index is lower than the ones before
    {
        i--; 
    }    // when this breaks i should equal the index that should be swapped 
    PrinterJob temp = heap[i]; 
    heap[i] = heap[index]; // the index being input gets its rightful place 
    heap[index] = temp; // swap 

}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob
}
