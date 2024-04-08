#include <iostream>
#include "../Items/Item.hpp"
#include "Recipe.hpp"

using namespace std;

class Bangunan : public Item
{
public:
    // 4 sekawan : ctor, cctor, dtor, op=
    Bangunan(int id, string code, string name, int price);
    Bangunan(const Bangunan &b);
    Bangunan &operator=(const Bangunan &b);
    ~Bangunan();

    // Getter and Setter
    string getType() const;
    string getCode() const;
    string getName() const;

    void setCode(string c);
    void setName(string n);

    // Operator Overloading
    Bangunan &operator+=(int x);
    Bangunan &operator-=(int x);

    Bangunan &operator+=(const Bangunan &b);
    Bangunan &operator-=(const Bangunan &b);
protected:
    static int numOfBangunan;
    string code;
    string nama;
};