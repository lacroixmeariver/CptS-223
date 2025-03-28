
#include <iostream>
using namespace std;
#include "Array.hpp"
#include "Hashmap.hpp"
#include "Product.hpp"
#include "app.hpp"

int main(int argc, char const *argv[])
{
    string line;

    App application; 
    application.sortData();
    //application.extractCategories();
    application.populateCategories();
    application.populateIds();
    application.findByCategory("Arts & Crafts"); 
    application.findByID(18); 
    
    // application.bootStrap();
    // while (getline(cin, line) && line != ":quit")
    // {
    //     if (application.validCommand(line))
    //     {
    //         application.evalCommand(line);
    //     }
    //     else
    //     {
    //         cout << "Command not supported. Enter :help for list of supported commands" << endl;
    //     }
    //     cout << "> ";
    // }
    // return 0;
}
