
#include <iostream>
using namespace std;
#include "scratchVector.hpp"

int main()
{

    ScratchVector<string> testVector(2);

    testVector.insertAtBack("First"); 
    testVector.insertAtBack("Second"); 
    cout << "Inside the first index: " << testVector[0] << endl; 
    cout << "Inside the second index: " << testVector[1] << endl; 
    testVector.insertAtBack("Third");
    cout << "Inside the third index: " << testVector[2] << endl; 
    testVector.deleteAtBack(); 
    cout << "Size: " << testVector.getSize() << endl; 
    testVector.clear();
    cout << testVector.isEmpty() << endl; 
    cout << "Inside the first index after clear(): " << testVector[0] << endl; 
    testVector.insertAtBack("New entry"); 
    cout << "Inside the first index after clear() + insert: " << testVector[0] << endl; 
    cout << "Size: " << testVector.getSize() << endl;




    return 0; 
}