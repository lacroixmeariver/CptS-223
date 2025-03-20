#include "HeapPriorityQueue.h"
#include <iostream>

// TODO: Implement the constructor
HeapPriorityQueue::HeapPriorityQueue(int newSize) {
    // Initialize size to 0
    size = newSize; // new size set to 0 in .h file 
}

// TODO: Implement the destructor
HeapPriorityQueue::~HeapPriorityQueue() {
    // Cleanup if necessary
}

// TODO: Implement the copy constructor
HeapPriorityQueue::HeapPriorityQueue(const HeapPriorityQueue& other) {
    // Copy heap elements and size
    // not a deep copy 
    HeapPriorityQueue* tempValue = new HeapPriorityQueue(other); 
    tempValue->size = size;
}

// TODO: Implement the copy assignment operator
HeapPriorityQueue& HeapPriorityQueue::operator=(const HeapPriorityQueue& other) {
    // Assign heap elements and size properly
    int i = 0;
    HeapPriorityQueue* tempValue = new HeapPriorityQueue(other);
    tempValue->size = other.size; 
    // while loop to copy over all elements in source array -> destination array
    while(i < other.size)
    {
        tempValue->heap[0] = other.heap[i]; 
        i++;
    }
   return *tempValue;
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    // Insert new PrinterJob(str, priority) while maintaining heap order using percolateUp 
    insert(str, priority);
}



// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
    if (size == 0)
    {
        cout << "Empty queue!" << endl;
        return; 
    }
    while(size > 0)
    {
        // printing just the root and then percolating goes in priority order after root is removed 
        cout << "\"" << heap[0].printString << "\"" << "(Priority: " << heap[0].priority << ")" << endl;
        percolateDown(0); 
    }
    cout << "********** End of print queue **********" << endl; // helps see where the queue actually ends 
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
    int index = size - 1; // establishing this as a variable name to avoid confusing myself 
    heap[index] = *tempPJ; // adding the new print job at the end of the array 
    if (*tempPJ < heap[(index - 1) / 2]) // if the node being inserted is smaller than it's parent
    {
        percolateUp(index); // bring up the node that was just inserted
    }
}

void HeapPriorityQueue::swap(int index, int parentIndex)
{
    PrinterJob tempBuffer = heap[index]; // temporary node to hold variables for the swap
    heap[index] = heap[parentIndex]; 
    heap[parentIndex] = tempBuffer; 
}

// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) // while the index is not 0 and the child is smaller than the parent 
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
    size--; // removed the last index, adjust the size of the tree accordingly
    
    while(index * 2 + 1 < size) // while the left child exists 
    {
        int leftChildIndex = index * 2 + 1; 
        int smallerIndex = leftChildIndex; // keeping track of the smaller of the 2 children 
        int rightChildIndex = index * 2 + 2; 
        if (rightChildIndex < size && heap[rightChildIndex] < heap[leftChildIndex]) // if right child exists and is less than left child 
        {
            smallerIndex = rightChildIndex; // setting the smaller index as the right child, to be swapped with parent below 
        }
        if (heap[index] <= heap[smallerIndex]) // if the child is in it's rightful spot 
        {
            return; 
        }

        swap(smallerIndex, index);  // swapping the parent with the smaller of the two children 
        index = smallerIndex; // continuing down 
    }
}
