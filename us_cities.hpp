#pragma once

using namespace std;
#include <iostream>

class us_cities
{
    private:
    // all the fields here are strings apart from the zipcode 
    int zip;
    string latitude, longitude, city, stateID, stateName, zcta, parentZcta, pop, 
    density, countyFlips, countyName, countyWeights, countyNamesAll, countyFlipsAll, 
    impersice, military, timezone;

    public:
    us_cities(int newZip, string newLat, string newLong, string newCity, string newStateID, string newStateName, string newZcta, 
    string newParentZcta, string newPop, string newDensity, string newCountyFlips, string newCountyName, string newCountyWeights, 
    string newNamesAll, string newFlipsAll, string newImp, string newMilitary, string newTimezone) : zip(newZip), latitude(newLat), longitude(newLong),
    city(newCity), stateID(newStateID), stateName(newStateName), zcta(newZcta), parentZcta(newParentZcta), pop(newPop), 
    density(newDensity), countyFlips(newCountyFlips), countyName(newCountyName), countyWeights(newCountyWeights), countyNamesAll(newNamesAll), 
    countyFlipsAll(newFlipsAll), impersice(newImp), military(newMilitary), timezone(newTimezone){};

    const int getZip()  
    {
        return zip;
    }


    

};