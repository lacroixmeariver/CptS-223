#pragma once

#include "us_cities.hpp"
#include "avl_node.hpp"
#include "avl_map.hpp"
#include <map> 
#include <fstream>
#include <string>

class testingClass 
{
    public:
    ~testingClass()
    {
        
    }

    void run()
    {
        int zip; 
        string line, latitude, longitude, city, stateID, stateName, zcta, parentZcta, pop, 
        density, countyFlips, countyName, countyWeights, countyNamesAll, countyFlipsAll, 
        impersice, military, timezone; 

        avl_map<int, us_cities> testMap;
        map<int, us_cities> testMap2; 

        list<int> zipList; 

        
    
        ifstream file("uszips.csv"); 
        getline(file, line); 
        for (int i = 0; i < 3374; i++)
        {
        getline(file, line, ','); 
        string cleanLine = line.substr(1, line.size() - 2);
        zip = std::stoi(cleanLine, nullptr, 10); 
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

        testMap.insert(tempCity.getZip(), tempCity); 
        ///testMap2.insert({tempCity.getZip(), tempCity});

        zipList.push_back(zip); 
        
    }
    file.close();
    testMap.find(603);
    testMap.find(2);


    //testMap.printTree();
    }

};