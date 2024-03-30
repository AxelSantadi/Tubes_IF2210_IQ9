#include "Product.hpp"

Product::Product() : id(-999), code(""), name(""), type(PRODUCT_MATERIAL_PLANT), origin(""), added_weight(0), price(0) {}

Product::Product(int id, const std::string &code, const std::string &name, ProductType type, const std::string &origin, int added_weight, int price)
    : id(id), code(code), name(name), type(type), origin(origin), added_weight(added_weight), price(price) {}

int Product::getId() const
{
    return id;
}

std::string Product::getCode() const
{
    return code;
}

std::string Product::getName() const
{
    return name;
}

ProductType Product::getType() const
{
    return type;
}

std::string Product::getOrigin() const
{
    return origin;
}

int Product::getAddedWeight() const
{
    return added_weight;
}

int Product::getPrice() const
{
    return price;
}

ostream& operator<<(ostream &os, const Product &product)
{
    os << product.getCode();
    return os;
}