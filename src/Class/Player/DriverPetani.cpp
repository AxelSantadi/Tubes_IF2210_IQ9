#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Animal.hpp"
#include "../Items/Animal.cpp"

#include "../Items/Product.hpp"
#include "../Items/Product.cpp"


#include "../Data/Exception.hpp"
#include "../Data/Exception.cpp"

#include "MatrixMap.cpp"
#include "ladang.cpp"

#include "../Data/Recipe.cpp"
#include "../Data/ReadConfig.cpp"
#include "../Data/Misc.cpp"
#include "Toko.cpp"
#include "Player.cpp"
#include "Petani.cpp"
#include "Petani.hpp"


int main (){
        Item * plant1 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
        Item * plant2 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
        Item * plant3 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
        Item * plant4 = new Plant(2, "APP", "Apple Tree", "Fruit Tree", 3, 500);
        Item * plant5 = new Plant(2, "APP", "Apple Tree", "Fruit Tree", 3, 500);
        Item * plant6 = new Plant(2, "GAP", "Grape", "Fruit Tree", 10, 2000);
        Item * plant7 = new Plant(2, "GAP", "Grape", "Fruit Tree", 0, 2000);
        Item * plant8 = new Plant(2, "GAP", "Grape", "Fruit Tree", 0, 2000);

        Plant plant9(2, "GAP", "Grape", "Fruit Tree", 10, 2000);
        


        Petani* petani = new Petani("Jokowi", 5, 'F',5,'F');

        petani->addItem(plant1,1,'A');
        petani->addItem(plant2,1,'B');
        petani->addItem(plant3,1,'C');
        petani->addItem(plant4,2,'A');
        petani->addItem(plant5,2,'B');
        petani->addItem(plant6,2,'C');
        petani->addItem(plant7,3,'D');
        petani->addItem(plant8,4,'D');

        petani->getInventory().printInventory();
        petani->tanam();
        petani->tanam();
        petani->tanam();
        // petani->tanam();
        petani->getLadang().cetakLadang();
        // // petani->panen(product)



    return 0;
}





