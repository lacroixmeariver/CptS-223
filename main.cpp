
#include <iostream>
using namespace std;
#include "scratchVector.hpp"

int main()
{

    ScratchVector<int> testVector(2);
    testVector.insertAtBack(1); 
    testVector.insertAtBack(2); 
    cout << "Inside the first index: " << testVector[0] << endl; 
    cout << "Inside the second index: " << testVector[1] << endl; 
    testVector.insertAtBack(3);
    cout << "Inside the third index: " << testVector[2] << endl; 
    cout << "Size: " << testVector.getSize() << endl; 
    testVector.clear();
    cout << "Inside the first index after clear(): " << testVector[0] << endl; 
    testVector.insertAtBack(5); 
    cout << "Inside the first index after clear() + insert: " << testVector[0] << endl; 
    cout << "Size: " << testVector.getSize() << endl;



    return 0; 
}