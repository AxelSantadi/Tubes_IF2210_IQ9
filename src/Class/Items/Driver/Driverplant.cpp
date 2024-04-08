#include "../Plant.hpp"
#include "../Plant.cpp"
#include "../Item.hpp"
#include "../Item.cpp"

#include <iostream>

int main() {
    // Create an instance of Plant
    Plant plant1(1, "code1", "plant1", "type1", 10, 100);

    // Display the plant
    plant1.output(std::cout);

    // Change the plant's properties
    plant1.setType("newType");
    plant1.setHarvestDuration(20);

    // Display the plant again
    plant1.output(std::cout);

    // Create another instance of Plant
    Plant plant2(2, "code2", "plant2", "type2", 30, 300);

    // Use operator overloading
    plant1 += plant2;
    plant1.output(std::cout);

    return 0;
}