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

string Bangunan::getType() const
{
    return "Bangunan";
}

string Bangunan::getCode() const
{
    return code;
}

string Bangunan::getName() const
{
    return name;
}

void Bangunan::setCode(string c)
{
    code = c;
}

void Bangunan::setName(string n)
{
    name = n;
}

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