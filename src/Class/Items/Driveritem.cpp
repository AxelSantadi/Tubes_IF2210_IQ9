#include "Item.hpp"
#include <iostream>

int main() {
    // Create an instance of Item
    Item item1(1, "code1", "item1", 100);

    // Display the item
    item1.display();

    // Change the item's properties
    item1.setCode("newCode");
    item1.setName("newName");
    item1.setPrice(200);

    // Display the item again
    item1.display();

    // Create another instance of Item
    Item item2(2, "code2", "item2", 300);

    // Use operator overloading
    item1 += item2;
    item1.display();

    return 0;
}