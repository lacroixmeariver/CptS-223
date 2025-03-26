
#ifndef _APP_
#define _APP_

#include <iostream>
using namespace std;
#include "Vector_.hpp"
#include "Hashmap.hpp"
#include "Product.hpp"
#include "List_.hpp"
#include <sstream>
class App
{
    public: 

    Vector_<string> categories;
    Vector_<Product> masterVector; 

    void extractData()
    {
        ifstream file("marketingData.csv");
        ofstream outFile("cleanData.csv"); 
        string buffer;
        Product bufferProd; 
        
        getline(file, buffer);
        int i = 0; 
        while (i < 100)
        {
            
            getline(file, buffer, ',');
            bufferProd.uniqueID = buffer;  
            getline(file, buffer, '"');
            //buffer.erase(remove(buffer.begin(), buffer.end(), '"'), buffer.end()); // get rid of some errant single double quotes 
            bufferProd.productName = buffer;
            getline(file, buffer, ',');
            bufferProd.brandName = buffer;
            getline(file, buffer, ',');
            bufferProd.asin = buffer;
            getline(file, buffer, ',');
            buffer.erase(remove(buffer.begin(), buffer.end(), '"'), buffer.end());
            trim(buffer); 
            if (buffer == "")
            {
                bufferProd.category = "N/A";

            }
            else
            {
                bufferProd.category = buffer;
            }

            cout << "Category going in: " << buffer << endl;
            getline(file, buffer, ',');
            bufferProd.upcEanCode = buffer;
            getline(file, buffer, ',');
            bufferProd.listPrice = buffer;
            getline(file, buffer, ',');
            bufferProd.sellingPrice = buffer;
            getline(file, buffer, ',');
            
            bufferProd.quantity = buffer;
            getline(file, buffer, ',');
            bufferProd.modelNumber = buffer;
            getline(file, buffer, ',');
            bufferProd.description = buffer;
            getline(file, buffer, ',');
            bufferProd.specifications = buffer;
            getline(file, buffer, ',');
            bufferProd.techDetails = buffer;
            getline(file, buffer, ',');
            bufferProd.shippingWeight = buffer;
            getline(file, buffer, ',');
            bufferProd.productDimensions = buffer;
            getline(file, buffer, ',');
            bufferProd.imageLink = buffer;
            getline(file, buffer, ',');
            bufferProd.variants = buffer;
            getline(file, buffer, ',');
            bufferProd.sku = buffer;
            getline(file, buffer, ',');
            bufferProd.url = buffer;
            getline(file, buffer, ',');
            bufferProd.stock = buffer;
            getline(file, buffer, ',');
            bufferProd.details = buffer;
            getline(file, buffer, ',');
            bufferProd.dimensions = buffer;
            getline(file, buffer, ',');
            bufferProd.color = buffer;
            getline(file, buffer, ',');
            bufferProd.ingredients = buffer;
            getline(file, buffer, ',');
            bufferProd.directions = buffer;
            getline(file, buffer, ',');
            bufferProd.amzSeller = buffer;
            getline(file, buffer, ',');
            bufferProd.qVariant = buffer;
            getline(file, buffer, '\n');
            bufferProd.productDescription = buffer;
        
            masterVector.insertAtBack(bufferProd);
            i ++; 
        }
    
        file.close(); 
    
    } 
   
    void extractCategories()
    {
        Vector_<Product> parsingVector = masterVector; // copy of the master vector 
        string buffer; 
         
        for (int i = 0; i < parsingVector.getSize(); i++)
        {
            std::istringstream iss(parsingVector[i].category); // making a buffer string the input stream from the category index 
            while (getline(iss, buffer, '|'))
            {
                trim(buffer);
                if (buffer != "N/A" && !isDuplicate(buffer))
                {
                    categories.insertAtBack(buffer);
                }
                
            }
        }
    }
    

    void printCategories()
    {
        cout << "Categories: " << endl; 
        for (int i = 0; i < categories.getSize(); i++) 
        {
            cout << categories[i] << endl; 
        }
    }

    void trim(string &dirty)
    {
        //cout << dirty << endl;
        if (dirty[0] == ' ')
        {
            dirty.erase(0, 1); 
        }
        if (dirty[dirty.size()] == ' ')
        {
            dirty.erase(dirty.size(), dirty.size() - 1);
        }
        //cout << dirty << endl;
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
    
};

#endif