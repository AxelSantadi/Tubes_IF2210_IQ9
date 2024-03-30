#include "Product.hpp"

int Product::numOfProduct = 0;

Product::Product()
{
    this->id = 0;
    this->code = "";
    this->name = "";
    this->type = "";
    this->origin = "";
    this->added_weight = 0;
    this->price = 0;
}

// Default ctor
Product::Product(int id, string code, string name, string type, string origin, int added_weight, int price)
{
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
    this->origin = origin;
    this->added_weight = added_weight;
    this->price = price;
}

Product::Product(const Product &P)
{
    this->id = P.id;
    this->code = P.code;
    this->name = P.name;
    this->type = P.type;
    this->origin = P.origin;
    this->added_weight = P.added_weight;
    this->price = P.price;
}

Product::~Product()
{
    Product::numOfProduct--;
}

Product &Product::operator=(const Product &P)
{
    this->id = P.id;
    this->code = P.code;
    this->name = P.name;
    this->type = P.type;
    this->origin = P.origin;
    this->added_weight = P.added_weight;
    this->price = P.price;
    return *this;
}

int Product::getId() const
{
    return id;
}

void setId(int i);

string Product::getCode() const
{
    return code;
}
void Product::setCode(string c)
{
    this->code = c;
}

string Product::getName() const
{
    return name;
}
void Product::setName(string n)
{
    this->name = n;
}

string Product::getType() const
{
    return type;
}
void Product::setType(string t)
{
    this->type = t;
}

string Product::getOrigin() const
{
    return origin;
}

void Product::setOrigin(string o)
{
    this->origin = o;
}

int Product::getAddedWeight() const
{
    return added_weight;
}

void Product::setAddedWeight(int a)
{
    this->added_weight = a;
}

int Product::getPrice() const
{
    return price;
}
void Product::setPrice(int p)
{
    this->price = p;
}

int Product::getNumOfProduct()
{
    return Product::numOfProduct;
}

Product &Product::operator+=(int x)
{
    this->price += x;
    return *this;
}

Product &Product::operator+=(int x)
{
    this->added_weight += x;
    return *this;
}

Product &Product::operator+=(const Product &i)
{
    this->price += i.price;
    return *this;
}

Product &Product::operator+=(const Product &i)
{
    this->added_weight += i.added_weight;
    return *this;
}

void Product::input(istream &is)
{
    is >> this->id >> this->code >> this->name >> this->type >> this->origin >> this->added_weight >> this->price;
}

void Product::output(ostream &os)
{
    os << this->id << " " << this->code << " " << this->name << " " << this->type << " " << this->origin << " " << this->added_weight << " " << this->price;
}