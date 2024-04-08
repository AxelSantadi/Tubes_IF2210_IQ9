#include "ReadConfig.hpp"

ReadConfig::ReadConfig() {}

ReadConfig::ReadConfig(string folderName)
{
    string folder = "../../../config/" + folderName;
    readMisc(folder + "/misc.txt");
    readAnimal(folder + "/animal.txt");
    readPlant(folder + "/plant.txt");
    readRecipe(folder + "/recipe.txt");
    readProduct(folder + "/product.txt");
}

void ReadConfig::readMisc(string filename)
{
    int duitMenang, beratMenang, n_inventory, m_inventory, n_lahan, m_lahan, n_peternakan, m_peternakan;
    ifstream file(filename);
    if (!file.is_open())
    {
        throw FileNotOpen();
    }

    file >> duitMenang >> beratMenang >> n_inventory >> m_inventory >> n_lahan >> m_lahan >> n_peternakan >> m_peternakan;

    file.close();
    pair<int, char> sizeInventory(n_inventory, 'A' + m_inventory - 1);
    pair<int, char> sizeLahan(n_lahan, 'A' + m_lahan - 1);
    pair<int, char> sizePeternakan(n_peternakan, 'A' + m_peternakan - 1);
    Misc x(duitMenang, beratMenang, sizeInventory, sizeLahan, sizePeternakan);
    misc = x;
}

void ReadConfig::readAnimal(string filename)
{
    int id, weightToHarvest, price;
    string code, name, type;

    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream ss(line);
            ss >> id >> code >> name >> type >> weightToHarvest >> price;
            animal.push_back(Animal(id, code, name, type, weightToHarvest, price));
        }
    }
}

void ReadConfig::readPlant(string filename)
{
    int id, harvest_duration, price;
    string code, name, type;

    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream ss(line);
            ss >> id >> code >> name >> type >> harvest_duration >> price;
            plant.push_back(Plant(id, code, name, type, harvest_duration, price));
        }
    }
}

void ReadConfig::readRecipe(string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            int id, price;
            string code, name;
            vector<string> namaMaterial;
            vector<int> jumlahMaterialNeeded;

            istringstream ss(line);
            ss >> id >> code >> name >> price;
            string material;
            int quantity;
            while (ss >> material >> quantity)
            {
                namaMaterial.push_back(material);
                jumlahMaterialNeeded.push_back(quantity);
            }
            recipe.push_back(Recipe(id, code, name, price, namaMaterial, jumlahMaterialNeeded));
        }
    }
}

void ReadConfig::readProduct(string filename)
{
    int id, price, added_weight;
    string code, name, type, origin;

    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            istringstream ss(line);
            ss >> id >> code >> name >> type >> origin >> added_weight >> price;
            Product p(id, code, name, type, origin, added_weight, price);
            product.push_back(p);
        }
    }
}

Misc ReadConfig::getMisc() const
{
    return misc;
}

vector<Animal> ReadConfig::getAnimal() const
{
    return animal;
}

vector<Plant> ReadConfig::getPlant() const
{
    return plant;
}

vector<Recipe> ReadConfig::getRecipe() const
{
    return recipe;
}

vector<Product> ReadConfig::getProduct() const
{
    return product;
}

Item *ReadConfig::createItem(string itemName) const
{
    // Iterate over animals
    for (const auto &a : animal)
    {
        if (a.getName() == itemName)
        {
            return new Animal(a.getId(), a.getCode(), a.getName(), a.getType(), a.getWeightToHarvest(), a.getPrice());
        }
    }

    // Iterate over plants
    for (const auto &p : plant)
    {
        if (p.getName() == itemName)
        {
            // Replace with the correct constructor for Plant
            return new Plant(p.getId(), p.getCode(), p.getName(), p.getType(), p.getHarvestDuration(), p.getPrice());
        }
    }

    // Iterate over products
    for (const auto &p : product)
    {
        if (p.getName() == itemName)
        {
            // Replace with the correct constructor for Product
            return new Product(p.getId(), p.getCode(), p.getName(), p.getType(), p.getOrigin(), p.getAddedWeight(), p.getPrice());
        }
    }

    // Iterate over recipes

    /*for (const auto& r : recipe) {
        if (r.getName() == itemName) {
            // Replace with the correct constructor for Recipe
            return new Recipe( parameters);
        }
    } */

    // If no match found, return null
    return nullptr;
}

Plant ReadConfig::createItemPlant(string itemName) const
{
    for (const auto &p : plant)
    {
        if (p.getName() == itemName)
        {
            return Plant(p.getId(), p.getCode(), p.getName(), p.getType(), p.getHarvestDuration(), p.getPrice());
        }
    }

    // If no match found, return a default Plant object
    return Plant();
}