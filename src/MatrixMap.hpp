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

    // Function to set value at a specific position
    void set(int x, char c, T value);

    bool isExist(int x, char c) const;

    // Function to get value at a specific position
    T get(int x, char c) const;

    // Function to get number of rows
    int numRows() const;

    // Function to get number of columns
    int numCols() const;

    // Function to print the matrix
    void print() const;
};

#endif /* MATRIX_HPP */
