#ifndef _PRODUCT_HPP_
#define _PRODUCT_HPP_

#include <iostream>
#include <string>
using namespace std;

class Product

{
public:
    Product();                                                                                          // Default ctor
    Product(int id, string code, string name, string type, string origin, int added_weight, int price); // User-Defined Ctor
    Product(const Product &);
    ~Product();

    Product &operator=(const Product &);

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

    Product &operator+=(int x);
    Product &operator+=(int x);

    Product &operator+=(const Product &i);
    Product &operator+=(const Product &i);

    void input(istream &is);
    void output(ostream &os);

protected:
    static int numOfProduct;

    int id;
    string code;
    string name;
    string type;
    string origin;
    int added_weight;
    int price;
};

#endif