#ifndef STORAGE_HPP
#define STORAGE_HPP
#include <iostream>
#include <array>
#include <string>

using namespace std;

class Storage {
public:
    Storage();
    ~Storage();
    void add(int, int, std::string); // modified add function to include position
    void remove(int, int); // modified remove function to include position
    void print();
    void print();
private:
    array<array<string, 8>, 8> data; // changed to 2D array
};

#endif