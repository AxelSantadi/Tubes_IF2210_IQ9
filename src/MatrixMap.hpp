#ifndef MATRIXMAP_HPP
#define MATRIXMAP_HPP

#include <iostream>
#include <string>
#include <map>

using namespace std;

template<typename T>
class MatrixMap {
protected:
    map<pair<int, char>, T> data;
    int rows;
    char cols;

public:
    // Constructor
    MatrixMap(int rows , char cols);

    // Boolean
    bool isExist(int x, char c) const;
    bool isFull() const;

    // Getter and Setter
    void setValue(int x, char c, T value);
    T getValue(int x, char c) const; 
    int getRows() const;
    int getCols() const;
    int countEmpty() const; // Count empty cell
    int countNotEmpty() const; // Count not empty cell

    // Methods
    virtual void print() const;
};

#endif /* MATRIX_HPP */
