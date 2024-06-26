#include "Item.hpp"

int Item::numOfItem = 0;

Item::Item()
{
    this->id = 0;
    this->code = "";
    this->name = "";
    this->price = 0;
    Item::numOfItem++;
}

Item::Item(int id, string code, string name, int price)
{
    this->id = id;
    this->code = code;
    this->name = name;
    this->price = price;

    Item::numOfItem++;
}

Item::Item(const Item &i)
{
    this->id = i.id;
    this->code = i.code;
    this->name = i.name;
    this->price = i.price;

    Item::numOfItem++;
}

Item &Item::operator=(const Item &i)
{
    this->id = i.id;
    this->code = i.code;
    this->name = i.name;
    this->price = i.price;
    return *this;
}

Item::~Item()
{
    Item::numOfItem--;
}

int Item::getId() const
{
    return id;
}

void Item::setId(int i)
{
    id = i;
}

string Item::getCode() const
{
    return code;
}

void Item::setCode(string c)
{
    code = c;
}

string Item::getName() const
{
    return name;
}

void Item::setName(string n)
{
    name = n;
}

int Item::getPrice() const
{
    return price;
}

void Item::setPrice(int p)
{
    price = p;
}

Item &Item::operator+=(int x)
{
    id += x;
    return *this;
}

Item &Item::operator-=(int x)
{
    id -= x;
    return *this;
}

Item &Item::operator+=(const Item &i)
{
    id += i.id;
    return *this;
}

Item &Item::operator-=(const Item &i)
{
    id -= i.id;
    return *this;
}

bool Item::operator==(const Item &i) const
{
    return (id == i.id && code == i.code && name == i.name && price == i.price);
}

void Item::input(istream &is)
{
    is >> id;
    is >> code;
    is >> name;
    is >> price;
}

void Item::output(ostream &os)
{
    os << id << endl;
    os << code << endl;
    os << name << endl;
    os << price << endl;
}

// Display item
void Item::display()
{
    cout << "ID: " << id << endl;
    cout << "Code: " << code << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
}

ostream &operator<<(ostream &os, const Item &i)
{
    os << i.code;
    return os;
}

ostream &operator<<(ostream &os, const Item *i){
    os << i->getCode();
    return os;
}


bool Item::isUnlimited() const { return false; }