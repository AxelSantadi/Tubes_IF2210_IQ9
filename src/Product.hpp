#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <iostream>
using namespace std;

enum ProductType {
    PRODUCT_MATERIAL_PLANT,
    PRODUCT_FRUIT_PLANT,
    PRODUCT_ANIMAL
};

class Product {
private:
    int id;
    std::string code;
    std::string name;
    ProductType type;
    std::string origin;
    int added_weight;
    int price;

public:
    // Constructors
    Product();
    Product(int id, const std::string& code, const std::string& name, ProductType type, const std::string& origin, int added_weight, int price);
    
    // Getters
    int getId() const;
    std::string getCode() const;
    std::string getName() const;
    ProductType getType() const;
    std::string getOrigin() const;
    int getAddedWeight() const;
    int getPrice() const;

    friend ostream& operator<<(ostream& os, const Product& product);
};

#endif // PRODUCT_HPP