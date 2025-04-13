#ifndef _PRODUCT
#define _PRODUCT
#include <string>
#include <iostream>
using namespace std; 

class Product
{
    public: 
    string uniqueID;
    string productName; 
    string brandName;
    string asin; // alphanumeric proprietary amazon code 
    string category;
    string upcEanCode;
    string listPrice;
    string sellingPrice;
    string quantity; 
    string modelNumber;
    string description;
    string specifications;
    string techDetails; 
    string shippingWeight; 
    string productDimensions; 
    string imageLink; 
    string variants;
    string sku;
    string url;
    string stock; 
    string details;
    string dimensions; 
    string color;
    string ingredients; 
    string directions; 
    string amzSeller;
    string qVariant; 
    string productDescription;

    // constructor
    Product(string id = "", string name = "", string brand = "", string asinNum = "", string cat = "",
    string upc = "", string priceList = "", string priceSell = "", string quant = "", string modNum = "", 
    string desc = "", string specs = "", string detailsTech = "", string weightShip = "", string prodDim = "", 
    string imgLink = "", string vars = "", string skuNum = "", string urlAdd = "", string stockNum = "", 
    string detailsProd = "", string dims = "", string colorProd = "", string ingred = "", string direct = "", 
    string isSeller = "", string quanVar = "", string descProd = "") : uniqueID(id), productName(name), brandName(brand),
    asin(asinNum), category(cat), upcEanCode(upc), listPrice(priceList), sellingPrice(priceSell), quantity(quant),
    modelNumber(modNum), description(desc), specifications(specs), techDetails(detailsTech), shippingWeight(weightShip),
    productDimensions(prodDim), imageLink(imgLink), variants(vars), sku(skuNum), url(urlAdd), stock(stockNum),
    details(detailsProd), dimensions(dims), color(colorProd), ingredients(ingred), directions(direct),  amzSeller(isSeller),
    qVariant(quanVar), productDescription(descProd) {};

    // destructor
    ~Product(){};

    friend ostream& operator<<(ostream& lhs, Product &rhs)
    {
        lhs << "ID: [" << rhs.uniqueID << "], Product: [" << rhs.productName << "]" << endl; 
        return lhs;   
    }

};



#endif
