#include <string>
#include <map>

class Recipe {
public:
    Recipe(int id, const std::string& code, const std::string& name, int price, const std::map<std::string, int>& materials)
        : id(id), code(code), name(name), price(price), materials(materials) {}

    int getId() const { return id; }
    std::string getCode() const { return code; }
    std::string getName() const { return name; }
    int getPrice() const { return price; }
    std::map<std::string, int> getMaterials() const { return materials; }

private:
    int id;
    std::string code;
    std::string name;
    int price;
    std::map<std::string, int> materials;
};