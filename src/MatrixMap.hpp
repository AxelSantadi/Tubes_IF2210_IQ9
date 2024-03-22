#ifndef MATRIXMAP_HPP
#define MATRIXMAP_HPP

#include <iostream>
#include <map>

using namespace std;

template<typename T>
class MatrixMap {
private:
    map<pair<int, int>, T> data;
    int rows;
    int cols;

public:
    // Constructor
    MatrixMap(int numRows, int numCols);

    // Function to set value at a specific position
    void set(int x, int y, T value);

    // Function to get value at a specific position
    T get(int x, int y) const;

    // Function to get number of rows
    int numRows() const;

    // Function to get number of columns
    int numCols() const;
};

#endif /* MATRIX_HPP */
