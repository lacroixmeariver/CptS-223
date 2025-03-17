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
        cout << "Job: " << heap[i].printString << " Priority: " << heap[i].priority << endl;
        
    }
}

void HeapPriorityQueue::insertAtBack(const string& str, int priority)
{
    PrinterJob *tempJob = new PrinterJob(str, priority); 
    int i = 1;
    if (isEmpty()) // if the array is empty 
    {
        heap[0] = *tempJob; 
        size ++;  
        cout << "Priority of [0]: " << heap[0].priority << endl;
        return; 
    }

    while(heap[i].printString != "\0") // finds index available that does not presently have a string 
    {
        i++; // increments i to be able to find that index
    }
    heap[i] = *tempJob; 
    //cout << "Priority of [i]: " << heap[i].priority << endl; // [debug print]
    size++; 
   if (heap[i].priority < heap[i - 1].priority)
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

void HeapPriorityQueue::swap(int x, int y)
{
    PrinterJob tempBuffer = heap[x]; 
    heap[x] = heap[y];
    heap[y] = tempBuffer; 
}

int HeapPriorityQueue::getMax()
{
    int maxIndex = heap[0].priority;
    for (int i = 0; i < size; i++)
    {
        if (heap[i].priority > maxIndex)
        {
            maxIndex = i; 
        }
    }

    return maxIndex; 
}

// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob

    while (index > 0) 
    {
        PrinterJob tempBuffer = heap[index - 1];

        if (heap[index].priority >= tempBuffer.priority) // breaks out of loop
        {
            return; 
        }

        swap(index, index - 1);
        index = index - 1; 
    }

}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob
    PrinterJob tempValue = heap[getMax()]; 
    heap[0] = tempValue; 

    
}
