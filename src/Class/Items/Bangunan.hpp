#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include "Item.hpp"

using namespace std;

class Bangunan : public Item
{
public:
    // 4 sekawan : ctor, cctor, dtor, op=
    Bangunan(int id, string code, string name, int price);
    Bangunan(const Bangunan &b);
    Bangunan &operator=(const Bangunan &b);
    ~Bangunan();

    // Operator Overloading
    Bangunan &operator+=(int x);
    Bangunan &operator-=(int x);

    Bangunan &operator+=(const Bangunan &b);
    Bangunan &operator-=(const Bangunan &b);

    bool operator==(const Bangunan &b) const;

    // Method buat makan
    int getAddedWeight() const;
    bool isMakanan() const;

    // Method buat jenis
    string getJenis() const;

protected:
    static int numOfBangunan;
};

#endif