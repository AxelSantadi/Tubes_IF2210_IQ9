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

#include "Petani.cpp"
#include "Petani.hpp"


int main (){
    Item * plant1 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
    Item * plant2 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
    Item * plant3 = new Plant(1, "TAW" , "Teak Wood Tree", "Material Tree", 4, 1000);
    Item * plant4 = new Plant(2, "APP", "Apple Tree", "Fruit Tree", 3, 500);
    Item * plant5 = new Plant(2, "APP", "Apple Tree", "Fruit Tree", 3, 500);
    Item * plant6 = new Plant(2, "GAP", "Grape", "Fruit Tree", 10, 2000);
    

    Petani* petani = new Petani("Jokowi", 50, 45,9,9);
    
    petani->getInventory().printInventory();

    // petani->getInventory().setValue(0,'A',plant1);
    // petani->getInventory().setValue(1,'B',plant2);
    // petani->getInventory().setValue(2,'C',plant3);
    // petani->getInventory().setValue(3,'D',plant4);
    // petani->getInventory().setValue(4,'E',plant5);
    // petani->getInventory().setValue(5,'F',plant6);


    return 0;
}






