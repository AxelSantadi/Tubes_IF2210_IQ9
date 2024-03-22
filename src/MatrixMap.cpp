#include "MatrixMap.hpp"

// Constructor
template<typename T>
MatrixMap<T>::MatrixMap(int numRows, int numCols) : rows(numRows), cols(numCols) {}

// Function to set value at a specific position
template<typename T>
void MatrixMap<T>::set(int x, int y, T value) {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        data[{x, y}] = value;
    } else {
        cout << "Invalid position!" << endl;
    }
}

// Function to get value at a specific position
template<typename T>
T MatrixMap<T>::get(int x, int y) const {
    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        auto it = data.find({x, y});
        if (it != data.end()) {
            return it->second;
        } else {
            // Return a default value
            return T(); // Ini akan memanggil konstruktor default dari kelas Product
        }
    } else {
        cout << "Invalid position!" << endl;
        return T(); // Ini akan memanggil konstruktor default dari kelas Product
    }
}

// Function to get number of rows
template<typename T>
int MatrixMap<T>::numRows() const {
    return rows;
}

// Function to get number of columns
template<typename T>
int MatrixMap<T>::numCols() const {
    return cols;
}
