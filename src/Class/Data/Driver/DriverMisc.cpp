#include "../Misc.hpp"
#include "../Misc.cpp"
#include <iostream>

int main() {
    // Create a Misc object
    Misc misc(1000, 200, std::make_pair(10, 'A'), std::make_pair(20, 'B'), std::make_pair(30, 'C'));

    // Print the Misc object
    std::cout << misc << std::endl;

    return 0;
}