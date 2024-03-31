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
    int getId() const;
    void setId(int i);

    string getCode() const;
    void setCode(string c);

    string getName() const;
    void setName(string n);

    string getType() const;
    void setType(string t);

    string getOrigin() const;
    void setOrigin(string o);

    int getAddedWeight() const;
    void setAddedWeight(int a);

    int getPrice() const;
    void setPrice(int p);

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

protected:
    static int numOfProduct;

    // Atribut yang spesifik untuk class Product
    string type;
    string origin;
    int added_weight;
};

#endif