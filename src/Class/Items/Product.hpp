#ifndef _PRODUCT_HPP_
#define _PRODUCT_HPP_

#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

class Product : public Item
{
public:
    // 4 Sekawan : ctor, cctor, dtor, op=
    Product();
    Product(int id, string code, string name, string type, string origin, int added_weight, int price);
    Product(const Product &);
    ~Product();
    Product &operator=(const Product &);

    // Getter and Setter
    string getType() const;
    void setType(string t);

    string getOrigin() const;
    void setOrigin(string o);

    int getAddedWeight() const override;
    void setAddedWeight(int a);

    int getNumOfProduct();

    // Operator Overloading
    Product &operator+=(int x);
    Product &operator-=(int x);

    Product &operator+=(const Product &i);
    Product &operator-=(const Product &i);

    // Input and Output
    void input(istream &is) override;
    void output(ostream &os) override;

    void display() override;

    bool isMakanan() const override;

    string getJenis() const override;

protected:
    static int numOfProduct;

    // Atribut yang spesifik untuk class Product
    string type;
    string origin;
    int added_weight;
};

#endif