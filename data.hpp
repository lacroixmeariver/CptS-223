#ifndef _DATA
#define _DATA

#include "header.hpp"
#include <string> 
using std::string;

class Data{
public:
    string key;
    string value;

    // constructor 
    Data(string keyCommand = "", string valueDescription = ""){
    key = keyCommand;
    value = valueDescription;
    }; 
};

#endif 