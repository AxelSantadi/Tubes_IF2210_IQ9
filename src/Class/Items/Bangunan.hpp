#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include "Item.hpp"
#include "../Data/Recipe.hpp"

using namespace std;

class Bangunan : public Item
{
public:
    // 4 sekawan : ctor, cctor, dtor, op=
    Bangunan(int id, string code, string name, int price);
    Bangunan(const Bangunan &b);
    Bangunan &operator=(const Bangunan &b);
    ~Bangunan();

    // Pure virtual function yang diimplementasiin
    int getAddedWeight() const;
    bool isMakanan() const;

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

#endif