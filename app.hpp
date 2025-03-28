
#ifndef _APP_
#define _APP_
#define MAX_DATA 10500

#include <iostream>
#include <fstream>
using namespace std;
#include "Array.hpp"
#include "Hashmap.hpp"
#include "Product.hpp"
#include <sstream>
class App
{
    protected: 
    Array<string> categories;
    Array<Product> masterArray; 
    Hashmap<string, Product> categoryHash;
    Hashmap<int, Product> idHash; 

    public: 
    App()
    {
        //categories = 0; 
        masterArray = Array<Product>(MAX_DATA);
        //categories = Array<string>(MAX_DATA); 
        categoryHash = Hashmap<string, Product>(MAX_DATA); 
        idHash = Hashmap<int, Product>(MAX_DATA);
    }    

    void sortData()
    {
        ifstream file("marketingData.csv");
        ofstream outFile("cleanData.csv"); 
        string buffer;
        Array<string> bufferArray(100); 
        Product bufferProd; 
        
        getline(file, buffer); 
        while (file)
        {

            getline(file, buffer);
            bufferArray = parseLine(buffer); 
            bufferArray.getSize();
         
            bufferProd.uniqueID = bufferArray[0];  
            bufferProd.productName = bufferArray[1];
            bufferProd.brandName = bufferArray[2];
            bufferProd.asin = bufferArray[3];
            if (bufferArray[4] == "")
            {
                bufferProd.category = "N/A";
            }
            else
            {
                bufferProd.category = bufferArray[4];
            }
            bufferProd.upcEanCode = bufferArray[5];
            bufferProd.listPrice = bufferArray[6];
            bufferProd.sellingPrice = bufferArray[7];
            bufferProd.quantity = bufferArray[8];
            bufferProd.modelNumber = bufferArray[9];
            bufferProd.description = bufferArray[10];
            bufferProd.specifications = bufferArray[11];
            bufferProd.techDetails = bufferArray[12];
            bufferProd.shippingWeight = bufferArray[13];
            bufferProd.productDimensions = bufferArray[14];
            bufferProd.imageLink = bufferArray[15];
            bufferProd.variants = bufferArray[16];
            bufferProd.sku = bufferArray[17];
            bufferProd.url = bufferArray[18];
            bufferProd.stock = bufferArray[19];
            bufferProd.details = bufferArray[20];
            bufferProd.dimensions = bufferArray[21];
            bufferProd.color = bufferArray[22];
            bufferProd.ingredients = bufferArray[23];
            bufferProd.directions = bufferArray[24];
            bufferProd.amzSeller = bufferArray[25];
            bufferProd.qVariant = bufferArray[26];
            masterArray.insertAtBack(bufferProd);
        }

        file.close();
    }

    // populates hash map for individual categories 
    void populateCategories()
    {
        Array<Product> parsingArray = masterArray; // copy of the master vector 
        string buffer;
        for (int i = 0; i < masterArray.getSize(); i++)
        {
            std::istringstream iss(parsingArray[i].category); // making a buffer string the input stream from the category index 
            while (getline(iss, buffer, '|'))
            {
                removeWhitespace(buffer); 
                //cout << "Inserting: " << parsingArray[i] << " into: " << buffer << endl; 
                categoryHash.insert(buffer, parsingArray[i]);
            }
            categoryHash.insert(buffer, parsingArray[i]);
        }
    }
    
    void populateIds()
    {
        Array<Product> parsingArray = masterArray; // copy of the master vector 
        string buffer;
        for (int i = 0; i < masterArray.getSize(); i++)
        {
            //size_t index = idHash.hashFunction(parsingArray[i].uniqueID);
            idHash.insert(i, parsingArray[i]); 
        }
    }
 
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

    string removeWhitespace(string &str)
    {
        size_t strBegin = 0, strEnd = str.size();
        int i = 0; 
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

    Array<string> parseLine(string &line)
    {
        Array<string> separatedFields(1001); 
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
                separatedFields.insertAtBack(indvField);
                indvField = "";
            }
            else 
            {
                indvField += lineChar; 
            }
        }
        separatedFields.insertAtBack(indvField);
        return separatedFields; 
    }

    
    void findByCategory(const string query)
    {
        categoryHash.printIndexList(query);
    }

    void findByID(int query)
    {
        idHash.find(query);
        idHash.printIndexList(query); 
    }

    void printHelp()
    {
        cout << "Supported list of commands: " << endl;
        cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
        cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
            << endl;
    }

    bool validCommand(string line)
    {
        return (line == ":help") ||
            (line.rfind("find", 0) == 0) ||
            (line.rfind("listInventory") == 0);
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
            // Look up the appropriate datastructure to find if the inventory exist
            //cout << "YET TO IMPLEMENT!" << endl;
            
        }
        // if line starts with listInventory
        else if (line.rfind("listInventory") == 0)
        {
            // Look up the appropriate datastructure to find all inventory belonging to a specific category
            //cout << "YET TO IMPLEMENT!" << endl;
            populateCategories();
            cout << "Enter category: " << endl;
            string input; 
            cin >> input; 
            findByCategory(input);
            
        }
    }

    void bootStrap()
    {
        cout << "\n Welcome to Amazon Inventory Query System" << endl;
        cout << " enter :quit to exit. or :help to list supported commands." << endl;
        cout << "\n> ";

    }
 

};

#endif