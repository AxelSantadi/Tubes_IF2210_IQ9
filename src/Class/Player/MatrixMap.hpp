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
    bool isEmpty() const;

    // Getter and Setter
    map<pair<int, char>, T> getData() const;
    virtual void setValue(int x, char c, T value);
    virtual void removeValue(int x, char c);
    T getValue(int x, char c) const; 
    int getRows() const;
    char getCols() const;
    int countEmpty() const;
    int countNotEmpty() const; 

    // Methods
    virtual void print() const;
};

#endif /* MATRIX_HPP */
