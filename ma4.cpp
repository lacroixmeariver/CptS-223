#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void insertionSort(vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

// utility function for array swaps
void swap(int array[], int leftIndex, int rightIndex)
{
    auto temp = array[leftIndex];
    array[leftIndex] = array[rightIndex];
    array[rightIndex] = temp;
}

// returns index at which array is roughly sorted
int partition(int array[], int low, int high)
{
    int left = low;
    int right = high;
    // pivot placed around the midpoint
    int pivot = array[low + (high - low) / 2];
    while (left <= right)
    {
        while (array[left] < pivot)
        {
            left++;
        }
        while (array[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            swap(array, left, right);
            left++;
            right--;
        }

    }
    return left;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high) // base case, indexes have crossed
    {
        return;
    }
    int pivotIndex = partition(arr.data(), low, high);
    quickSort(arr, low, pivotIndex - 1);// left half of array
    quickSort(arr, pivotIndex, high); // right half of array
}

void shellSort(vector<int> &arr, int arraySize, int interval)
{
    // using interval instead of fixed number to more easily change gap size
    for (int gap = arraySize / interval; gap > 0; gap /= interval)
    {
        for (int i = gap; i < arraySize; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j > 0 && arr[j - gap] > temp) // making sure all sub-lists are covered and swapping occurs if need be
            {
                swap(arr.data(), j, j-gap);
                j = j - gap;
            }
        }
    }
}

void percolateDown(vector<int> &arr, int index, int size)
{
    // size needs to be an input parameter so that the scope of this function doesn't reach the final sorted bit
    // that comes as a result of the initial swap in part II of heapsort function
    while (index * 2 + 1 < size) //  while the left child exists
    {
        int largerChild = index; // start at the root since that's supposed to be the largest element
        int left = (index * 2) + 1, right = (index * 2) + 2;
        // keeping track of the larger index, using size to keep within the bounds of array
        if (left < size && arr[left] > arr[largerChild])
        {
            largerChild = left;
        }
        if (right < size && arr[right] > arr[largerChild])
        {
            largerChild = right;
        }
        if (index != largerChild) // if it's not in the right location
        {
            swap(arr.data(), index, largerChild);
            index = largerChild;
        }
        else // if it is in the right location
        {
            return;
        }

    }

}

// builds max heap from existing array using percolate down
vector<int>& buildHeap(vector<int>& arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
    {
        percolateDown(arr, i, arr.size());
    }
    return arr;
}

void heapSort(vector<int> &arr)
{
    buildHeap(arr); // input array -> valid max heap
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr.data(), 0, i);
        percolateDown(arr, 0, i);
    }
}

void printStatistics(const vector<double> &durations)
{
    double minTime = *min_element(durations.begin(), durations.end());
    double maxTime = *max_element(durations.begin(), durations.end());
    double avgTime = accumulate(durations.begin(), durations.end(), 0.0) / durations.size();

    double variance = 0.0;
    for (double t : durations)
    {
        variance += (t - avgTime) * (t - avgTime);
    }
    double stdDev = sqrt(variance / durations.size());

    cout << "\n=== Statistics ===\n";
    cout << "Min Time: " << minTime << " ms\n";
    cout << "Max Time: " << maxTime << " ms\n";
    cout << "Average Time: " << avgTime << " ms\n";
    cout << "Standard Deviation: " << stdDev << " ms\n";
}

int main()
{
    // Size of the collection
    const int N = 10000; // TODO: Change this back to 10,000 when ready to submit
    // Max limit for the random generation
    const int MAX_VAL = 100000;
    // Total trial (use the same for other sorting algorithms)
    const int TRIALS = 10;

    srand(static_cast<unsigned>(time(nullptr)));
    vector<double> durations;

    cout << "******************* START OF INSERTION SORT *******************" << endl;
    for (int trial = 0; trial < TRIALS; ++trial)
    {
        vector<int> data(N);
        // Generate 10,000 random numbers and populate data
        for (int i = 0; i < N; ++i)
        {
            data[i] = rand() % (MAX_VAL + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        insertionSort(data);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        durations.push_back(elapsed.count());
        cout << "Trial " << trial + 1 << " duration: " << elapsed.count() << " ms\n";
    }
    printStatistics(durations);
    cout << "******************* END OF INSERTION SORT *******************" << endl << endl;
    durations.clear();

    cout << "******************* START OF QUICK SORT *******************" << endl;
    for (int trial = 0; trial < TRIALS; ++trial)
    {
        vector<int> data(N);
        // Generate 10,000 random numbers and populate data
        for (int i = 0; i < N; ++i)
        {
            data[i] = rand() % (MAX_VAL + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        quickSort(data, 0, data.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        durations.push_back(elapsed.count());
        cout << "Trial " << trial + 1 << " duration: " << elapsed.count() << " ms\n";
    }
    printStatistics(durations);
    cout << "******************* END OF QUICK SORT *******************" << endl << endl;
    durations.clear();

    cout << "******************* START OF SHELL SORT *******************" << endl;
    for (int trial = 0; trial < TRIALS; ++trial)
    {
        vector<int> data(N);
        // Generate 10,000 random numbers and populate data
        for (int i = 0; i < N; ++i)
        {
            data[i] = rand() % (MAX_VAL + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        shellSort(data, data.size(), 3);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        durations.push_back(elapsed.count());
        cout << "Trial " << trial + 1 << " duration: " << elapsed.count() << " ms\n";
    }
    printStatistics(durations);
    cout << "******************* END OF SHELL SORT *******************" << endl << endl;
    durations.clear();

    cout << "******************* START OF HEAP SORT *******************" << endl;
    for (int trial = 0; trial < TRIALS; ++trial)
    {
        vector<int> data(N);
        // Generate 10,000 random numbers and populate data
        for (int i = 0; i < N; ++i)
        {
            data[i] = rand() % (MAX_VAL + 1);
        }
        auto start = chrono::high_resolution_clock::now();
        heapSort(data);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        durations.push_back(elapsed.count());
        cout << "Trial " << trial + 1 << " duration: " << elapsed.count() << " ms\n";
    }
    printStatistics(durations);
    durations.clear();
    cout << "******************* END OF HEAP SORT *******************" << endl << endl;

    return 0;
}
