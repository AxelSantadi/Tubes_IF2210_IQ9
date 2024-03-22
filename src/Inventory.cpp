#include "Inventory.hpp"

Inventory::Inventory(int n, int m) : n(n), m(m), items(n, m) {}

int Inventory::getN() const
{
    return n;
}

int Inventory::getM() const
{
    return m;
}

Product Inventory::getItem(int i, int j) const
{
    return items.get(i, j);
}

void Inventory::setItem(int i, int j, Product item)
{
    items.set(i, j, item);
}

void Inventory::setN(int n)
{
    this->n = n;
}

void Inventory::setM(int m)
{
    this->m = m;
}