#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
    // 4 Sekawan : ctor, cctor, dtor, op=
    Item();
    Item(int id, string code, string name, int price);
    Item(const Item &i);
    Item &operator=(const Item &i);
    ~Item();

    // Getter and Setter
    int getId();
    void setId(int i);

    string getCode();
    void setCode(string c);

    string getName();
    void setName(string n);

    int getPrice();
    void setPrice(int p);

    // Operator Overloading
    Item &operator+=(int x);
    Item &operator-=(int x);

    Item &operator+=(const Item &i);
    Item &operator-=(const Item &i);

    // Input and Output
    virtual void input(istream &is);
    virtual void output(ostream &os);

    // Display item
    virtual void display();
    friend ostream &operator<<(ostream &os,const Item &i);

protected:
    static int numOfItem;
    int id;
    string code;
    string name;
    int price;
};

#endif