#include "Product.hpp"
#include <iostream>

int main() {
    // Create an instance of Product
    Product product1(1, "code1", "product1", "type1", "origin1", 10, 100);

    // Display the product
    product1.display();

    // Change the product's properties
    product1.setCode("newCode");
    product1.setName("newName");
    product1.setType("newType");
    product1.setOrigin("newOrigin");
    product1.setAddedWeight(20);
    product1.setPrice(200);

    // Display the product again
    product1.display();

    // Create another instance of Product
    Product product2(2, "code2", "product2", "type2", "origin2", 30, 300);

    // Use operator overloading
    product1 += product2;
    product1.display();

    return 0;
}