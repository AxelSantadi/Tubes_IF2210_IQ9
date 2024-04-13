#include <iostream>
#include "Bangunan.hpp"

using namespace std;

Bangunan::Bangunan(int id, string code, string name, int price) : Item(id, code, name, price) {}

Bangunan::Bangunan(const Bangunan &b) : Item(b) {}

Bangunan &Bangunan::operator=(const Bangunan &b)
{
    Item::operator=(b);
    return *this;
}

Bangunan::~Bangunan() {}

Bangunan &Bangunan::operator+=(int x)
{
    Item::operator+=(x);
    return *this;
}

Bangunan &Bangunan::operator-=(int x)
{
    Item::operator-=(x);
    return *this;
}

Bangunan &Bangunan::operator+=(const Bangunan &b)
{
    Item::operator+=(b);
    return *this;
}

Bangunan &Bangunan::operator-=(const Bangunan &b)
{
    Item::operator-=(b);
    return *this;
}

bool Bangunan::operator==(const Bangunan &b) const
{
    return Item::operator==(b);
}

int Bangunan::getAddedWeight() const{
    return 0;
}

bool Bangunan::isMakanan() const{
    return false;
}

string Bangunan::getJenis() const{
    return "Bangunan";
}