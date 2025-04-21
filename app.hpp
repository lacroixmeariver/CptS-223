#ifndef APPLICATION_
#define APPLICATION_
#define MAX_DATA 10500
#include "Product.hpp"
#include "arrayContainer.hpp"
#include "hashmapContainer.hpp"
#include "sorts.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;

class App {
protected:
  Array<string> categories;      // array to hold all total categories
  Array<Product> fileInputArray; // buffer container, holds data taken from the
  // input file before it gets place in hashmaps
  Hashmap<string, Product>
      categoryHash; // hashmap of categories acting as each of the buckets
  Hashmap<int, Product> idHash; // hashmap of IDs and Products


  void sortData() {
    ifstream file("cleanedMarketingData.csv");
    string stringBuffer;
    Array<string> arrayBuffer(10); // each index holds one product detail
    Product productBuffer; // temporary object in order to place in the master array

    getline(file, stringBuffer);
    while (getline(file, stringBuffer)) {
      // placing each line from the file into a buffer string
      getline(file, stringBuffer);
      // parseLine() helps separate strings with wacky formatting
      arrayBuffer = parseLine(stringBuffer);

      // big ugly chunk of Product member values being assigned
      productBuffer.uniqueID = arrayBuffer[0];
      productBuffer.productName = arrayBuffer[1];
      if (arrayBuffer[2] == "") {
        productBuffer.category = "N/A";
      } else {
        productBuffer.category = arrayBuffer[2];
      }
      if (isValidNumber((arrayBuffer[3]))) {
        productBuffer.sellingPrice = stod(arrayBuffer[3]);
      } else {
        productBuffer.sellingPrice = -1.0;
      }
      productBuffer.productDescription = arrayBuffer[4];
      productBuffer.amzSeller = arrayBuffer[5];

      // inserting into the Product class array
      fileInputArray.insertAtBack(productBuffer);
    }

    file.close();
  }

  // creates and populates hash map for individual categories
  void createCategoryHash() {
    Array<Product> parsingArray = fileInputArray; // copy of the main array holding all the data

    string stringBuffer;
    for (int i = 0; i < fileInputArray.getSize(); i++) {
      std::istringstream iss(parsingArray[i].category);
      // making the buffer string the input stream from the category index to
      // use getline()
      while (getline(iss, stringBuffer, '|')) {
        removeWhitespace(stringBuffer); // cleaning the leading and trailing whitespace after separating
        for (int j = 0; j < stringBuffer.size();
             j++) // making sure input is standardize to eliminate the need for capitalization from user
        {
          stringBuffer[j] = tolower(stringBuffer[j]);
        }
        categories.insertAtBack(stringBuffer);
        categoryHash.insert(stringBuffer, parsingArray[i]);
      }
    }
  }

  // creates and populates the ID -> Unique ID hash
  void createIdHash() {
    Array<Product> parsingArray = fileInputArray; // copy of the master vector
    string buffer;
    for (int i = 0; i < fileInputArray.getSize(); i++) {
      idHash.insert(i, parsingArray[i]); // i acts as the inventory ID
    }
  }

  bool findByCategory(const string query, int flag) {
    auto result = categoryHash.findByIndex(query);
    Array<Hashmap<string, Product>::Node *> sortedArray;

    switch (flag) {
    case 1:
      sortedArray = Sorts<string, Product>::insertionSort(result, ascendingCompare<Product>);
      break;
    case 2:
      sortedArray = Sorts<string, Product>::insertionSort(result, descendingCompare<Product>);
      break;
    case 3:
      sortedArray = Sorts<string, Product>::mergeSort(Sorts<string, Product>::arrayify(result), ascendingCompare<Product>);
      break;
    case 4:
      sortedArray = Sorts<string, Product>::mergeSort(Sorts<string, Product>::arrayify(result), descendingCompare<Product>);
      break;
    case 5:
      sortedArray = Sorts<string, Product>::insertionSort(result, ascendingCompare<Product>);
      break;
    case 6:
      sortedArray = Sorts<string, Product>::mergeSort(Sorts<string, Product>::arrayify(result), ascendingCompare<Product>);
      break;
    }
    if (sortedArray.isEmpty() && flag != 5 && flag != 6) {
      cout << "No category found for: " << query << endl;
      return false;
    } else if (flag != 5 && flag != 6) {
      for (int i = 0; i < sortedArray.getSize(); i++) {
        cout << sortedArray[i]->nodeData << endl;
      }
    }
    return true;
  }

  void findByID(int query) {
    auto result = idHash.find(query);
    if (result == nullptr) {
      cout << "No ID found for: " << query << endl;
    } else {
      cout << result->nodeData << endl;
    }
  }

  bool isValidNumber(string input) {
    try {
      stod(input);
      return true;
    }
    catch (...) { // general catch for whatever exception may come
      return false;
    }
  }

  // ******************************************* Public data functions start here *******************************************
public:
  // constructor
  App() {
    fileInputArray = Array<Product>(MAX_DATA);
    categories = Array<string>(MAX_DATA);
    categoryHash = Hashmap<string, Product>(MAX_DATA);
    idHash = Hashmap<int, Product>(MAX_DATA);
  }

  ~App()= default;

  // helper function to determine if something is a duplicate or not
  bool isDuplicate(string str) {
    for (int i = 0; i < categories.getSize(); i++) {
      if (categories[i] == str) {
        return true;
      }
    }
    return false;
  }

  // helper function to remove leading and trailing whitespace
  // returns a substring from the original
  // string removeWhitespace(string &str) {
  //   size_t strBegin = 0, strEnd = str.size();
  //   while (strBegin < strEnd && str[strBegin] == ' ') {
  //     strBegin++;
  //   }
  //   while (strEnd > strBegin && str[strEnd - 1] == ' ') {
  //     strEnd--;
  //   }
  //   str = str.substr(strBegin, strEnd - strBegin);
  //   return str;
  // }

  // removes all whitespce
  string removeWhitespace(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
  }

  // iterates through a string char by char and disregards commas depending on
  // whether or not they're present between "" using a bool val also accounts
  // for instances of consecutive "" returns array that collectively carries the
  // information for 1 Product class object
  Array<string> parseLine(string &line) {
    Array<string> separatedFields(101);
    string indvField;
    bool inQuotes = false;
    for (size_t i = 0; i < line.size(); i++) {
      char lineChar = line[i];
      if (lineChar == '"') {
        if (inQuotes &&
            line[i + 1] == '"') // more than one set of "" consecutively
        {
          indvField += '"';
          i++;
        } else {
          inQuotes = !inQuotes; // toggles depending on the presence of quotes
        }
      } else if (lineChar == ',' && !inQuotes) // field is complete
      {
        separatedFields.insertAtBack(indvField); // into the array it goes
        indvField = "\0"; // setting it back to  null char
      } else {
        indvField += lineChar;
      }
    }
    separatedFields.insertAtBack(indvField);
    return separatedFields;
  }

  void evalCommand(string line) {
    if (line == ":help") {
      printHelp();
    }
    else if (line == "runTests") {
      runTests();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0) {
      istringstream iss(
          line); // to be able to take input on the same line as command
      string command;
      int input;
      iss >> command >> input;
      findByID(input);
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0) {
      istringstream iss(line);
      string command, input, order, typeSort;
      iss >> command >> input >> typeSort >> order;
      getline(iss >> ws, input); // ws removes leading whitespace
      // cleaning up the input
      for (int i = 0; i < input.size(); i++) {
        input[i] = tolower(input[i]);
      }
      if (typeSort.empty()) {
        findByCategory(input, 1);
      }
      else if (typeSort == "desc") {
        findByCategory(input, 2);
      }
      else if (typeSort == "merge") {
        if (order.empty()) {
          findByCategory(input, 3);
        }
        else {
          findByCategory(input, 4);
        }
      }
    }
  }

  bool validCommand(string line) {
    return (line == ":help") || (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0) || (line.rfind("runTests", 0) == 0);
  }

  void bootStrap() {
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands."
         << endl;
    cout << "\n> ";
    sortData();
    createIdHash();
    createCategoryHash();
  }

  void printHelp() {
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If "
            "exists, prints details. If not, prints 'Inventory not found'."
         << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name "
            "of all inventory belonging to the specified category. If the "
            "category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
  }

  void runTests() {
    srand(time(NULL));
    bool sortFlag = true;
    bool validFlag = true;
    // testing insertion sort
    while(sortFlag) {
      std::chrono::duration<double> insertionSortAvg;
      for (int k = 0; k < 50; k++) {
        int randomCategory = rand() % categories.getSize();
        // starting point for time capturing
        auto start = chrono::high_resolution_clock::now();
        validFlag = findByCategory(categories[randomCategory], 5);
        // end timestamp
        auto end = chrono::high_resolution_clock::now();
        while (!validFlag) {
          int randomCategory = rand() % categories.getSize();
          start = chrono::high_resolution_clock::now();
          validFlag = findByCategory(categories[randomCategory], 5);
          end = chrono::high_resolution_clock::now();
        }
        std::chrono::duration<double> duration = end - start;
        insertionSortAvg += duration;
      }
      sortFlag = false;
      insertionSortAvg / 100.0;
      cout << "Insertion sort avg: " << insertionSortAvg.count() << endl;
    }

    sortFlag = true;
    // merge sort
    while(sortFlag) {
      std::chrono::duration<double> mergeSortAvg;
      for (int k = 0; k < 50; k++) {
        int randomCategory = rand() % categories.getSize();
        // starting point for time capturing
        auto start = chrono::high_resolution_clock::now();
        findByCategory(categories[randomCategory], 6);
        // end timestamp
        auto end = chrono::high_resolution_clock::now();
        while (!validFlag) {
          int randomCategory = rand() % categories.getSize();
          start = chrono::high_resolution_clock::now();
          validFlag = findByCategory(categories[randomCategory], 6);
          end = chrono::high_resolution_clock::now();
        }
        std::chrono::duration<double> duration = end - start;
        mergeSortAvg += duration;
      }
      sortFlag = false;
      mergeSortAvg / 100.0;
      cout << "Merge sort avg: " << mergeSortAvg.count() << endl;
    }
  }
};
#endif
