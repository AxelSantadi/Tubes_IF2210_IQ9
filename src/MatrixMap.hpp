#ifndef MATRIXMAP_HPP
#define MATRIXMAP_HPP

#include <iostream>
#include <map>

using namespace std;

template<typename T>
class MatrixMap {
private:
    map<pair<int, char>, T> data;
    int rows;
    char cols;

public:
    // Constructor
    MatrixMap(int rows , char cols);


    bool isExist(int x, char c) const;

    // Function to set value at a specific position
    void setValue(int x, char c, T value);
 
    // Function to get value at a specific position
    T getValue(int x, char c) const; 

    // Function to get number of rows
    int getRows() const;

    // Function to get number of columns
    int getCols() const;

    // Function to print the matrix
    void print() const;
};

#endif /* MATRIX_HPP */
