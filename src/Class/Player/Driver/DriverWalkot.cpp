#include "Walikota.hpp"
#include "Walikota.cpp"

// Item
#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Animal.hpp"
#include "../Items/Animal.cpp"

#include "../Items/Product.hpp"
#include "../Items/Product.cpp"

#include "../Items/Bangunan.hpp"
#include "../Items/Bangunan.cpp"

// Player
#include "Player.hpp"
#include "Player.cpp"

#include "Petani.hpp"
#include "Petani.cpp"

#include "Peternak.hpp"
#include "Peternak.cpp"

// Config
#include "../Data/Exception.hpp"
#include "../Data/Exception.cpp"

#include "../Data/ReadConfig.hpp"
#include "../Data/ReadConfig.cpp"

#include "../Data/Misc.hpp"
#include "../Data/Misc.cpp"

#include "../Data/Recipe.hpp"
#include "../Data/Recipe.cpp"

// Per map an
#include "MatrixMap.hpp"

#include "Inventory.hpp"
#include "Inventory.cpp"

#include "Kandang.hpp"
#include "Kandang.cpp"

#include "ladang.hpp"
#include "ladang.cpp"

// Toko
#include "Toko.hpp"
#include "Toko.cpp"

using namespace std;

int main()
{
    // Create a Walikota
    Player *walikota = new Walikota("John Doe", 5, 'M', 5000, 100);

    // Print the role of the Walikota
    std::cout << "Role: " << walikota->getRole() << std::endl;

    // Create a vector of Recipe objects (assuming Recipe is a class you have defined)

    ReadConfig config("config1");
    std::cout << "berhasil load config" << std::endl;

    Inventory inventory(3, 'A');
    walikota->setInventory(inventory);

    Item *product1 = new Product(1, "TAW", "TEAK_WOOD", "PRODUCT_MATERIAL_PLANT", "TEAK_TREE", 0, 9);
    Item *product2 = new Product(2, "SAW", "SANDALWOOD_WOOD", "PRODUCT_MATERIAL_PLANT", "SANDALWOOD_TREE", 0, 8);

    walikota->addItem(product1,1, 'A');
    walikota->addItem(product2,2, 'A');
    walikota->getInventory().printInventory();
    cout << endl;

    cout << "Uang: " << walikota->getMoney() << endl;

    // Create a Recipe object
    vector<Recipe> resep = config.getRecipe();

    // Call the buatBangunan method
    walikota->buatBangunan(resep);

    walikota->getInventory().printInventory();

    // Call the tambahPemain method (assuming Misc is a class you have defined)
    walikota->addMoney(50);
    Misc misc = config.getMisc();
    walikota->tambahPemain(misc);
    walikota->tambahPemain(misc);
    
    // Buat player baru
    Player *petani = new Petani("John Diss", 5, 'C', 30, 550,3,'A');
    
    Item* productbaru = new Bangunan(6,"KON","Rumah Mantap",250);
    petani->addItem(productbaru,1,'A');


    // Call the dapatPajak method
    walikota->dapatPajak(resep);

    cout << walikota->getMoney() << endl;

    return 0;
}