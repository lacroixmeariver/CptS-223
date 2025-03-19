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
    delete heap; 
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
        i++;
    }
   return tempValue;
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    // Insert new PrinterJob(str, priority) while maintaining heap order using percolateUp 
    insert(str, priority);
}



// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
    //cout << "This is working" << endl;
    //int i = 0; 
    if (size == 0)
    {
        cout << "Empty queue!" << endl;
        return; 
    }
    while(size > 0)
    {
        // printing just the root and then percolating goes in priority order 
        cout << "\"" << heap[0].printString << "\"" << "(Priority: " << heap[0].priority << ")" << endl;
        percolateDown(0); 
    }
    cout << "********** End of print queue **********" << endl;
   return; 
    
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
    if (isEmpty()) // if it's an empty array
    {
        heap[0] = *tempPJ; 
        size++;
        return;
    }
    size++;
    int index = size - 1;
    heap[index] = *tempPJ; 
    if (*tempPJ < heap[(index - 1) / 2]) // if the node being inserted is smaller than it's parent
    {
        percolateUp(index); // bring up the node that was just inserted
    }
}

void HeapPriorityQueue::swap(int index, int parentIndex)
{
    PrinterJob tempBuffer = heap[index]; 
    heap[index] = heap[parentIndex];
    heap[parentIndex] = tempBuffer; 
}



// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) 
    // while the index is not 0 and the child is smaller than the parent 
   {
        swap(index, (index - 1) / 2);  // helper function that swaps the child and parent indices 
        index = ((index - 1) / 2); // moves the index up to the next parent 
   }
}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob
    // remove the largest index and replace the root with it 
    heap[index] = heap[size - 1];
    size--;
    
    while(index * 2 + 1 < size) // while the left child exists 
    {
        int leftChildIndex = index * 2 + 1; 
        int smallerIndex = leftChildIndex; // keeping track of the smaller of the 2 children 
        int rightChildIndex = index * 2 + 2; 
        if (rightChildIndex < size && heap[rightChildIndex] < heap[leftChildIndex]) // if right child exists and is less than left child 
        {
            smallerIndex = rightChildIndex;
        }
        if (heap[index] <= heap[smallerIndex]) 
        {
            return; 
        }

        swap(smallerIndex, index);  
        index = smallerIndex; 
    }
  return; 
}
