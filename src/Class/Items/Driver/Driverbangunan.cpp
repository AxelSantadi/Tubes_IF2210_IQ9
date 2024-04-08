#include "../Bangunan.hpp"
#include "../Bangunan.cpp"
#include "../Item.hpp"
#include "../Item.cpp"
#include "../../Data/Recipe.hpp"
#include "../../Data/Recipe.cpp"
#include "../../Player/MatrixMap.hpp"
#include "../../Player/MatrixMap.cpp"
#include "../../Data/Exception.hpp"
#include "../../Data/Exception.cpp"



#include <iostream>

int main() {
    // Create a new Bangunan object
    Bangunan b1(1, "B01", "Building 1", 1000);

    // Display the details of the Bangunan object
    cout << "ID: " << b1.getId() << endl;
    cout << "Code: " << b1.getCode() << endl;
    cout << "Name: " << b1.getName() << endl;
    cout << "Price: " << b1.getPrice() << endl;

    // Modify the Bangunan object
    b1.setName("Modified Building 1");
    b1.setPrice(2000);

    // Display the modified details of the Bangunan object
    cout << "Modified Name: " << b1.getName() << endl;
    cout << "Modified Price: " << b1.getPrice() << endl;

    return 0;
}