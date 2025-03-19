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
    
    insert(str, priority);
    
}



// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
    //cout << "This is working" << endl;
    //int i = 0; 
    for (int i = 0; i < size; i++)
    {
        cout << "Job: " << heap[i].printString << " Priority: " << heap[i].priority << endl;
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

void HeapPriorityQueue::insert(const string& str, int priority)
{
    PrinterJob *tempPJ = new PrinterJob(str, priority); 
    if (isEmpty())
    {
        heap[0] = *tempPJ; 
        size++;
        return;
    }
    size++;
    int index = size - 1;
    heap[index] = *tempPJ; 
    //cout << "Insert pre - compare: " << index << " & " << (index - 1) / 2 << endl; 
    if (*tempPJ < heap[(index - 1) / 2]) // if the node being inserted is smaller than it's parent
    {
        //cout << "Insert compare: " << size << " & " << (size - 2) / 2 << endl; 
        // percolate up
        percolateUp(index);
    }

    //size++;

    
    
}

void HeapPriorityQueue::swap(int index, int parentIndex)
{

    PrinterJob tempBuffer = heap[index]; 
    //cout << "Swapping: " << heap[index].printString << " & " << heap[(index - 1) / 2].printString << endl; 
    heap[index] = heap[parentIndex];
    heap[parentIndex] = tempBuffer; 
    //cout << "Swapped: " << heap[index].printString << " & " << heap[(index - 1) / 2].printString << endl; 

}



// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob
    // index passed in is the one of the child that was just inserted 
    //cout << "Index passed into percolate is: " << "'" << heap[index].printString << "'" << " with priority: " << heap[index].priority << endl;  
    while (index > 0 && heap[index] < heap[(index - 1) / 2])
   {
        //cout << "Index is: " << "'" << heap[index].printString << "'" << " with priority: " << heap[index].priority << endl;
        //cout << "Index - 1 div 2 is: " << "'" << heap[(index - 1) / 2].printString << "'" << " with priority: " << heap[(index - 1)/ 2].priority << endl;
        //cout << "Percolate up!" << endl; 
        //cout << "Trying to swap: " << heap[index].priority << " & " << heap[(index - 1) / 2].priority << endl;  
      
        swap(index, (index - 1) / 2); 
        index = ((index - 1) / 2); 
        //cout << "Index after [-1] is: " << "'" << heap[index].printString << "'" << " with priority: " << heap[index].priority << endl;
   }
//    if (heap[(index - 1) / 2] <= heap[index]) // when the the child is in it's rightful spot
//    { 
//        return; 
//    }


}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob

  
}
