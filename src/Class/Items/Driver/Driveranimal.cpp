#include "../Animal.hpp"
#include "../Animal.cpp"
#include "../Item.hpp"
#include "../Item.cpp"

#include <iostream>

int main() {
    // Create an instance of Animal
    Animal animal1(1, "code1", "animal1", "type1", 10, 100);

    // Display the animal
    animal1.display();

    // Change the animal's properties
    animal1.setType("newType");
    animal1.setWeightToHarvest(20);

    // Display the animal again
    animal1.display();

    // Create another instance of Animal
    Animal animal2(2, "code2", "animal2", "type2", 30, 300);

    // Use operator overloading
    animal1 += animal2;
    animal1.display();

    return 0;
}