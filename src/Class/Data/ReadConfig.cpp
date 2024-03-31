#include "ReadConfig.hpp"

ReadConfig::ReadConfig(string folderName) : misc()
{
    string folder = "../../../config/" + folderName;
    readMisc(folder + "/misc.txt");
    // readAnimal(folder + "/animal.txt");
    // readPlant(folder + "/plant.txt");
    readRecipe(folder + "/recipe.txt");
    // readProduct(folder + "/product.txt");
}

void ReadConfig::readMisc(string filename)
{
    int duitMenang, beratMenang, n_inventory, m_inventory, n_lahan, m_lahan, n_peternakan, m_peternakan;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Gagal membuka file " << filename << endl;
    }

    file >> duitMenang >> beratMenang >> n_inventory >> m_inventory >> n_lahan >> m_lahan >> n_peternakan >> m_peternakan;

    file.close();
    pair<int, int> sizeInventory(n_inventory, m_inventory);
    pair<int, int> sizeLahan(n_lahan, m_lahan);
    pair<int, int> sizePeternakan(n_peternakan, m_peternakan);
    Misc x(duitMenang, beratMenang, sizeInventory, sizeLahan, sizePeternakan);
    misc = x;
}

// void ReadConfig::readAnimal(string filename)
// {
//     int id, weightToHarvest, price;
//     string code, name, type;

//     ifstream file(filename);
//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream ss(line);
//             ss >> id >> code >> name >> type >> weightToHarvest >> price;
//             animal.push_back(Animal(id, code, name, type, weightToHarvest, price));
//         }
//     }
// }

// void ReadConfig::readPlant(string filename)
// {
//     int id, harvest_duration, price;
//     string code, name, type;

//     ifstream file(filename);
//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream ss(line);
//             ss >> id >> code >> name >> type >> harvest_duration >> price;
//             plant.push_back(Plant(id, code, name, type, harvest_duration, price));
//         }
//     }
// }

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
            cout << id << " " << code << " " << name << " " << price << " ";
            string material;
            int quantity;
            while (ss >> material >> quantity)
            {
                namaMaterial.push_back(material);
                jumlahMaterialNeeded.push_back(quantity);
                cout << material << " " << quantity << " ";
            }
            cout << endl;
            recipe.push_back(Recipe(id, code, name, price, namaMaterial, jumlahMaterialNeeded));
        }
    }
}

// void ReadConfig::readProduct(string filename)
// {
//     int id, price, added_weight;
//     string code, name, type, origin;

//     ifstream file(filename);
//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             istringstream ss(line);
//             ss >> id >> code >> name >> type >> origin >> added_weight >> price;
//             Product p(id, code, name, type, origin, added_weight, price);
//             product.push_back(p);
//         }
        
//     }
    
// }

Misc ReadConfig::getMisc() const
{
    return misc;
}

// vector<Animal> ReadConfig::getAnimal() const
// {
//     return animal;
// }

// vector<Plant> ReadConfig::getPlant() const
// {
//     return plant;
// }

vector<Recipe> ReadConfig::getRecipe() const
{
    return recipe;
}

// vector<Product> ReadConfig::getProduct() const
// {
//     return product;
// }

