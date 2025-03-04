#pragma once
#include <map> 
#include <fstream>
#include <string>
#include <vector>
#include "us_cities.hpp"
#include "avl_node.hpp"
#include "avl_map.hpp"
using namespace std; 

#define MAX_ZIPS 33783



class testingClass 
{
    public:
    // data members for testing use 
    avl_map<int, us_cities> testAVl;
    map<int, us_cities> testMAP; 
    vector<int> zipList; 
    vector<int> returnList;


    ~testingClass()
    {

    }

    void run()
    {
        int zip; 
        string line, latitude, longitude, city, stateID, stateName, zcta, parentZcta, pop, 
        density, countyFlips, countyName, countyWeights, countyNamesAll, countyFlipsAll, 
        impersice, military, timezone; 

        double avlTime = 0.0, averageAvlTime = 0.0, mapTime = 0.0, averageMapTime = 0.0;
    
        ifstream file("uszips.csv");  // opening zips file, close at the end 
        getline(file, line); 
        for (int i = 0; i < MAX_ZIPS ; i++) // the entire list 
        {
            getline(file, line, ','); 
            string cleanLine = line.substr(1, line.size() - 2); // making a substring because most fields surrounded by forward slashes 
            zip = std::stoi(cleanLine, nullptr, 10); // forcing decimal, some numbers start with 00
            getline(file, latitude, ','); 
            getline(file, longitude, ','); 
            getline(file, city, ','); 
            getline(file, stateID, ','); 
            getline(file, stateName, ','); 
            getline(file, zcta, ','); 
            getline(file, parentZcta, ','); 
            getline(file, pop, ','); 
            getline(file, density, ','); 
            getline(file, countyFlips, ','); 
            getline(file, countyName, ','); 
            getline(file, countyWeights, ','); 
            getline(file, countyNamesAll, ','); 
            getline(file, countyFlipsAll, ','); 
            getline(file, impersice, ','); 
            getline(file, military, ','); 
            getline(file, timezone, '\n'); 
    
            us_cities tempCity(zip, latitude, longitude, city, stateID, stateName, zcta, parentZcta, 
            pop, density, countyFlips, countyName, countyWeights, countyNamesAll, countyFlipsAll, 
            impersice, military, timezone);

            // time keeping 
            clock_t k = clock(); // avl time keeping start
            clock_t startAVL;
            do startAVL = clock();
            while (startAVL == k);
            testAVl.insert(tempCity.getZip(), tempCity); // populating avl tree
            clock_t endAVL = clock();

            clock_t j = clock(); // map time keeping start
            clock_t startMAP;
            do startMAP = clock();
            while (startMAP == j);
            testMAP.insert({tempCity.getZip(), tempCity}); // populating map
            clock_t endMAP = clock();

            zipList.push_back(zip); // for testing down the line 

            double elapsedAvlTime = static_cast<double>(endAVL - startAVL)/CLOCKS_PER_SEC,
            elapsedMapTime = static_cast<double>(endMAP - startMAP)/CLOCKS_PER_SEC; 
            avlTime+= elapsedAvlTime;
            mapTime+= elapsedMapTime;
           
        }

        // printing output 
        averageAvlTime = avlTime / MAX_ZIPS;
        averageMapTime = mapTime / MAX_ZIPS; 
        cout << "Average AVL insertion time: " << averageAvlTime << endl;
        cout << "Average MAP insertion time: " << averageMapTime << endl;
    }

    void randomValues()
    // populating a vector of random values to test find 
    {
        for (int i = 0; i < 1000; i++)
        {
            int randomNumber = rand() % 1000;
            returnList.push_back(zipList[randomNumber]);
        }
    }

    void testAvlFind()
    {
        double avlTime = 0.0, averageAvlTime = 0.0;
        for (int i = 0; i < 1000; i++)
        {
            clock_t k = clock(); // time keeping start
            clock_t start;
            do start = clock();
            while (start == k);
            testAVl.find(returnList[i]);
            clock_t end = clock();

            double elapsedTime = static_cast<double>(end - start)/CLOCKS_PER_SEC; 
            avlTime+= elapsedTime;
        }
         
        averageAvlTime = avlTime / 1000;
        cout << "Average AVL find time: " << averageAvlTime << endl;

    }


    void testMapFind()
    {
        double mapTime = 0.0, averageMapTime = 0.0;
        for (int i = 0; i < 1000; i++)
        {
            clock_t k = clock(); // time keeping start
            clock_t start;
            do start = clock();
            while (start == k);
            testMAP.find(returnList[i]);
            clock_t end = clock();

            double elapsedTime = static_cast<double>(end - start)/CLOCKS_PER_SEC; 
            mapTime+= elapsedTime;
        }
         
        averageMapTime = mapTime / 1000;
        cout << "Average MAP find time: " << averageMapTime << endl;
    }
};