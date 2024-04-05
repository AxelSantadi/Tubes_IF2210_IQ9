#include "Product.hpp"

int Product::numOfProduct = 0;

Product::Product() : Item()
{
    this->type = "";
    this->origin = "";
    this->added_weight = 0;
}

Product::Product(int id, string code, string name, string type, string origin, int added_weight, int price) : Item(id, code, name, price)
{
    this->type = type;
    this->origin = origin;
    this->added_weight = added_weight;
}

Product::Product(const Product &P) : Item(P.id, P.code, P.name, P.price)
{
    this->type = P.type;
    this->origin = P.origin;
    this->added_weight = P.added_weight;
}

Product::~Product()
{
    Product::numOfProduct--;
}

Product &Product::operator=(const Product &P)
{
    this->Item::operator=(P);
    this->type = P.type;
    this->origin = P.origin;
    this->added_weight = P.added_weight;
    return *this;
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


int Product::getNumOfProduct()
{
    return Product::numOfProduct;
}

Product &Product::operator+=(int x)
{
    this->price += x;
    return *this;
}

Product &Product::operator-=(int x)
{
    this->added_weight -= x;
    return *this;
}

Product &Product::operator+=(const Product &i)
{
    this->price += i.price;
    return *this;
}

Product &Product::operator-=(const Product &i)
{
    this->added_weight -= i.added_weight;
    return *this;
}

void Product::input(istream &is)
{
    Item::input(is);
    is >> type;
    is >> origin;
    is >> added_weight;
}

void Product::output(ostream &os)
{
    Item::output(os);
    os << type << endl;
    os << origin << endl;
    os << added_weight << endl;
}

void Product::display()
{
    Item::display();
    cout << "Type : " << this->type << endl;
    cout << "Origin : " << this->origin << endl;
    cout << "Added Weight : " << this->added_weight << endl;
}

bool Product::isMakanan() const
{
    return (added_weight > 0);
}