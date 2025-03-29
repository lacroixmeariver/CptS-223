
#include <iostream>
#include "arrayContainer.hpp"
#include "hashmapContainer.hpp"
#include "Product.hpp"
#include "app.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    string line;

    App application; 
    
    application.bootStrap();
    while (getline(cin, line) && line != ":quit") 
    {
        if (application.validCommand(line))
        {
            application.evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}

