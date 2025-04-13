
#ifndef _APP_
#define _APP_
#define MAX_DATA 10500
#include <iostream>
#include <fstream>
#include "arrayContainer.hpp"
#include "hashmapContainer.hpp"
#include "Product.hpp"
#include <sstream>
using namespace std;

class App
{
    protected: 

    Array<string> categories; // array to hold all total categories 
    Array<Product> fileInputArray; // buffer container, holds data taken from the input file before it gets place in hashmaps
    Hashmap<string, Product> categoryHash; // hashmap of categories acting as each of the buckets
    Hashmap<int, Product> idHash; // hashmap of IDs and Products 

    void sortData()
    {
        ifstream file("marketingData.csv");
        string stringBuffer; 
        Array<string> arrayBuffer(30); // each index holds one product detail 
        Product productBuffer; // temporary object in order to place in the master array
        
        getline(file, stringBuffer); 
        while(getline(file, stringBuffer))
        {
            // placing each line from the file into a buffer string 
            getline(file, stringBuffer);
            // parseLine() helps separate strings with wacky formatting 
            arrayBuffer = parseLine(stringBuffer); 
         
            // big ugly chunk of Product member values being assigned 
            productBuffer.uniqueID = arrayBuffer[0];  
            productBuffer.productName = arrayBuffer[1];
            productBuffer.brandName = arrayBuffer[2];
            productBuffer.asin = arrayBuffer[3];
            if (arrayBuffer[4] == "")
            {
                productBuffer.category = "N/A";
            }
            else
            {
                productBuffer.category = arrayBuffer[4];
            }
            productBuffer.upcEanCode = arrayBuffer[5];
            productBuffer.listPrice = arrayBuffer[6];
            productBuffer.sellingPrice.erase(std::remove(productBuffer.sellingPrice.begin(), productBuffer.sellingPrice.end(), '$'), productBuffer.sellingPrice.end());
            productBuffer.sellingPrice = arrayBuffer[7];
            productBuffer.quantity = arrayBuffer[8];
            productBuffer.modelNumber = arrayBuffer[9];
            productBuffer.description = arrayBuffer[10];
            productBuffer.specifications = arrayBuffer[11];
            productBuffer.techDetails = arrayBuffer[12];
            productBuffer.shippingWeight = arrayBuffer[13];
            productBuffer.productDimensions = arrayBuffer[14];
            productBuffer.imageLink = arrayBuffer[15];
            productBuffer.variants = arrayBuffer[16];
            productBuffer.sku = arrayBuffer[17];
            productBuffer.url = arrayBuffer[18];
            productBuffer.stock = arrayBuffer[19];
            productBuffer.details = arrayBuffer[20];
            productBuffer.dimensions = arrayBuffer[21];
            productBuffer.color = arrayBuffer[22];
            productBuffer.ingredients = arrayBuffer[23];
            productBuffer.directions = arrayBuffer[24];
            productBuffer.amzSeller = arrayBuffer[25];
            productBuffer.qVariant = arrayBuffer[26];
            // inserting into the Product class array
            fileInputArray.insertAtBack(productBuffer);
        }

        file.close();
    }

    // creates and populates hash map for individual categories 
    void createCategoryHash()
    {
        Array<Product> parsingArray = fileInputArray; // copy of the main array holding all the data  
        string stringBuffer;
        for (int i = 0; i < fileInputArray.getSize(); i++)
        {
            std::istringstream iss(parsingArray[i].category); // making the buffer string the input stream from the category index to use getline()
            while (getline(iss, stringBuffer, '|'))
            {
                removeWhitespace(stringBuffer); // cleaning the leading and trailing whitespace after separating 
                for (int i = 0; i < stringBuffer.size(); i++) // making sure input is standardize to eliminate the need for capitalization from user 
                {
                    stringBuffer[i] = tolower(stringBuffer[i]);
                }
                categoryHash.insert(stringBuffer, parsingArray[i]); 
            }
        }
    }

    // creates and populates the ID -> Unique ID hash 
    void createIdHash() 
    {
        Array<Product> parsingArray = fileInputArray; // copy of the master vector 
        string buffer;
        for (int i = 0; i < fileInputArray.getSize(); i++)
        {
            idHash.insert(i, parsingArray[i]); // i acts as the inventory ID
        }
    }

    void findByCategory(const string query)
    {
        // each index in this hash is a type of container 
        if (categoryHash.find(query))
        {
            categoryHash.displayByIndex(query); 
        }
        else
        {
            cout << "Invalid category" << endl; 
        }
    }

    void findByID(int query)
    {
        if (idHash.find(query))
        {
            idHash.displayByIndex(query); 
        }
        else
        {
            cout << "Inventory/Product not found" << endl; 
        }
    }

    // ******************************************* Public data functions start here *******************************************
    public: 

    // constructor 
    App()
    {
        fileInputArray = Array<Product>(MAX_DATA);
        categoryHash = Hashmap<string, Product>(MAX_DATA); 
        idHash = Hashmap<int, Product>(MAX_DATA);
    }    
 
    // helper function to determine if something is a duplicate or not 
    bool isDuplicate(string str)
    {
        for (int i = 0; i < categories.getSize(); i++)
        {
            if (categories[i] == str)
            {
                return true; 
            }
        }
        return false; 
    }

    // helper function to remove leading and trailing whitespace
    // returns a substring from the original
    string removeWhitespace(string &str)
    {
        size_t strBegin = 0, strEnd = str.size();
        while(strBegin < strEnd && str[strBegin] == ' ')
        {
            strBegin++;
        }
        while(strEnd > strBegin && str[strEnd - 1] == ' ')
        {
            strEnd--;
        }
        str = str.substr(strBegin, strEnd - strBegin);
        return str; 
    }

    // iterates through a string char by char and disregards commas depending on whether or not they're present between "" using a bool val 
    // also accounts for instances of consecutive "" 
    // returns array that collectively carries the information for 1 Product class object 
    Array<string> parseLine(string &line)
    {
        Array<string> separatedFields(101); 
        string indvField; 
        bool inQuotes = false; 
        for (size_t i = 0; i < line.size(); i++)
        {
            char lineChar = line[i]; 
            if (lineChar == '"') 
            {
                if (inQuotes && line[i+1] == '"') // more than one set of "" consecutively 
                {
                    indvField += '"'; 
                    i++;
                }
                else 
                {
                    inQuotes = !inQuotes; // toggles depending on the presence of quotes 
                }
            }
            else if (lineChar == ',' && !inQuotes) // field is complete 
            {
                separatedFields.insertAtBack(indvField); // into the array it goes 
                indvField = "\0"; // setting it back to  null char 
            }
            else 
            {
                indvField += lineChar; 
            }
        }
        separatedFields.insertAtBack(indvField);
        return separatedFields; 
    }

    void evalCommand(string line)
    {
        if (line == ":help")
        {
            printHelp();
        }
    
        // if line starts with find
        else if (line.rfind("find", 0) == 0)
        {
            createIdHash();
            istringstream iss(line); // to be able to take input on the same line as command 
            string command; 
            int input;
            iss >> command >> input; 
            findByID(input);
        }
        // if line starts with listInventory
        else if (line.rfind("listInventory") == 0)
        {
            createCategoryHash();
            istringstream iss(line);
            string command, input; 
            iss >> command;
            getline(iss >> ws, input); // ws removes leading whitespace 
            for (int i = 0; i < input.size(); i++)
            {
                input[i] = tolower(input[i]);
            }
            findByCategory(input);
        }
    }

    bool validCommand(string line)
    {
        return (line == ":help") ||
        (line.rfind("find", 0) == 0) ||
        (line.rfind("listInventory") == 0);
    }

    void bootStrap()
    {
        cout << "\n Welcome to Amazon Inventory Query System" << endl;
        cout << " enter :quit to exit. or :help to list supported commands." << endl;
        cout << "\n> ";
        sortData();
    }

    void printHelp()
    {
        cout << "Supported list of commands: " << endl;
        cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
        cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
        << endl;
    }
   
};
#endif