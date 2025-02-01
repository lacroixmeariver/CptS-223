#ifndef _DATA
#define _DATA

#include "header.hpp"
#include <string> 
using std::string;

class Data{
public:
    string key;
    string value;
    int pointValue;

    // constructor 
    Data(string keyCommand = "", string valueDescription = "", int points = 0){
    key = keyCommand;
    value = valueDescription;
    pointValue = points;
    }; 

    friend ostream& operator<<(ostream& lhs, Data rhs){
        lhs << "Key: " << rhs.key << endl;
        lhs << "Value: " <<rhs.value << endl;
        lhs << "Point value: " << rhs.pointValue << endl;
        cout << endl;
        return lhs;
    }
};

#endif 