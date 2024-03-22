#include <string>

enum ProductType {
    PRODUCT_MATERIAL_PLANT,
    PRODUCT_FRUIT_PLANT,
    PRODUCT_ANIMAL
};

class Product {
public:
    Product(): id(-999), code(""), name(""), type(PRODUCT_MATERIAL_PLANT), origin(""), added_weight(0), price(0) {}
    Product(int id, const std::string& code, const std::string& name, ProductType type, const std::string& origin, int added_weight, int price)
        : id(id), code(code), name(name), type(type), origin(origin), added_weight(added_weight), price(price) {}
    int getId() const { return id; }
    std::string getCode() const { return code; }
    std::string getName() const { return name; }
    ProductType getType() const { return type; }
    std::string getOrigin() const { return origin; }
    int getAddedWeight() const { return added_weight; }
    int getPrice() const { return price; }

private:
    int id;
    std::string code;
    std::string name;
    ProductType type;
    std::string origin;
    int added_weight;
    int price;
};