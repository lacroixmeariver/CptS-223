#ifndef PRODUCT
#define PRODUCT
#include <iostream>
#include <string>

class Product {
public:
  std::string uniqueID;
  std::string productName;
  std::string category;
  double sellingPrice; // now converted to a double for comparison purposes
  std::string productDescription;
  std::string amzSeller;

  // constructor
  // I shortened this up because there was just a lot of blank information and Subu mentioned being allowed to clean the CSV file up a bit
  Product(std::string newID = "", std::string newProdName = "",
          std::string newCategory = "", double newSellingPrice = 0.0,
          std::string newAMZSeller = "", std::string newProdDescription = "")
      : uniqueID(newID), productName(newProdName), category(newCategory),
        sellingPrice(newSellingPrice), productDescription(newProdDescription),
        amzSeller(newAMZSeller){}

  // destructor
  ~Product() {};

  friend std::ostream &operator<<(std::ostream &lhs, Product &rhs) {
    lhs << "ID: [" << rhs.uniqueID << "], Price: [" << rhs.sellingPrice << "] "
        << "Product: [" << rhs.productName << "]" << std::endl;
    return lhs;
  }

  // overloaded comparison operators set to compare selling price
  // greater than
  friend bool operator>(const Product &lhs, const Product &rhs) {
    return lhs.sellingPrice > rhs.sellingPrice;
  }

  // less than
  friend bool operator<(const Product &lhs, const Product &rhs) {
    return lhs.sellingPrice < rhs.sellingPrice;
  }
};

#endif
