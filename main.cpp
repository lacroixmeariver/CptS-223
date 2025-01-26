#include "header.hpp"
#include "data.hpp"
#include "node.hpp"
#include "list.hpp"



int main(void){

    Data testData("key value", "description");
    Data testData2("other key value", "other description");
    List<Data> testList;
    testList.insertAtFront(testData);
    testList.insertAtFront(testData2);




    

    return 0; 
}
