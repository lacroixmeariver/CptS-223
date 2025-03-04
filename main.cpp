#include <iostream>
#include "avl_map.hpp"
#include "testingClass.hpp"
using namespace std;
#include <list>
#include <map>
#include <ctime>

int main()
{
    srand(time(NULL));

    
    testingClass test; 
    test.run();
    test.randomValues();
    test.testAvlFind();
    test.testMapFind();

    return 0;
}