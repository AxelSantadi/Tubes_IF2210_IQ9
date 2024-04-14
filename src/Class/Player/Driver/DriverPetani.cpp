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


int main (){
        ReadConfig readConfig("config1");

        vector<Product> product =  readConfig.getProduct();
        Item * plant1 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
        Item * plant2 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
        Item * plant3 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
        Item * plant4 = new Plant(2, "APP", "Apple Tree", "Fruit Tree", 3, 500);
        Item * plant5 = new Plant(2, "APP", "Apple Tree", "Fruit Tree", 3, 500);
        Item * plant6 = new Plant(2, "GAP", "Grape", "Fruit Tree", 10, 2000);
        Item * plant7 = new Plant(2, "GAP", "Grape", "Fruit Tree", 0, 2000);
        Item * plant8 = new Plant(2, "GAP", "Grape", "Fruit Tree", 0, 2000);
        Item * plant9 = new Plant(2, "GAP", "Grape", "Fruit Tree", 0, 2000);
        Item * plant10 = new Plant(2, "GAP", "Grape", "Fruit Tree", 0, 2000);

        Player* petani = new Petani("Jokowi", 5, 'F',5,'F');
        
        petani->addItem(plant1,1,'A');
        petani->addItem(plant2,1,'B');
        petani->addItem(plant3,1,'C');
        petani->addItem(plant4,2,'A');
        petani->addItem(plant5,2,'B');
        petani->addItem(plant6,2,'C');
        petani->addItem(plant7,3,'D');
        petani->addItem(plant8,4,'D');
        petani->addItem(plant8,5,'D');
        petani->addItem(plant8,1,'D');

        petani->tanam();
        Petani *p = dynamic_cast<Petani*>(petani);
        petani->nextDay();
        petani->nextDay();
        // petani->nextDay();
        // Plant pl = p->getLadang().getValue(1,'A');
        // cout << "Umur : " <<pl.getUmur()<< endl;
        // cout << "code : " << pl.getCode() << endl;
        petani->tanam();
        petani->tanam();
        p->getLadang().cetakLadang();
        petani->panen(product);
        petani->getInventory().printInventory();
        p->getLadang().cetakLadang();
        Plant p1 = p->getLadang().getValue(1,'A');
        cout << "Umur : "<<p1.getUmur()<< endl;
        

    return 0;
}





