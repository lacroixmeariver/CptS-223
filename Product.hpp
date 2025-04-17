#ifndef _PRODUCT
#define _PRODUCT

#include <iostream>
#include <string>
// using namespace std;

class Product {
public:
  std::string uniqueID;
  std::string productName;
  std::string category;
  double sellingPrice;
  std::string productDescription;
  std::string amzSeller;

  // constructor
  Product(string newID = "", string newProdName = "", string newCategory = "",
          double newSellingPrice = 0.0, string newAMZSeller = "",
          string newProdDescription = "")
      : uniqueID(newID), productName(newProdName), category(newCategory),
        sellingPrice(newSellingPrice), amzSeller(newAMZSeller),
        productDescription(newProdDescription) {}

  // destructor
  ~Product() {};

  friend std::ostream &operator<<(std::ostream &lhs, Product &rhs) {
    lhs << "ID: [" << rhs.uniqueID << "], Price: [" << rhs.sellingPrice << "] "
        << "Product: [" << rhs.productName << "]" << std::endl;
    return lhs;
  }

  friend inline bool operator>(const Product &lhs, const Product &rhs) {
    return lhs.sellingPrice > rhs.sellingPrice;
  }

  friend inline bool operator<(const Product &lhs, const Product &rhs) {
    return lhs.sellingPrice < rhs.sellingPrice;
  }
};

#endif
