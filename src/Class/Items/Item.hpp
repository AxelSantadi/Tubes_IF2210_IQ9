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
    Item(int id, string code, string name, string type);
    Item &operator=(const Item &i);
    ~Item();

    // Getter and Setter
    int getId();
    void setId(int i);

    string getCode();
    void setCode(string c);

    string getName();
    void setName(string n);

    string getType();
    void setType(string t);

    void input(istream &is);
    void output(ostream &os);

    // Operator Overloading
    Item &operator+=(int x);
    Item &operator-=(int x);

    Item &operator+=(const Item &i);
    Item &operator-=(const Item &i);

    // Display item
    virtual void display();

protected:
    int id;
    string code;
    string name;
    string type;
};

#endif