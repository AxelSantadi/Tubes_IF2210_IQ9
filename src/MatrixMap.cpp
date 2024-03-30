#include "MatrixMap.hpp"

// Constructor
template <typename T>
MatrixMap<T>::MatrixMap(int rows , char cols): rows(rows) , cols(cols) {}

// Function to set value at a specific position
template <typename T>
void MatrixMap<T>::setValue(int x, char c, T value)
{
    if (x <= 0 || x > rows || c > cols || c < 'A')
    {
        cout << "Invalid position!" << endl;
        // nanti pakai exception
    }
    else
    {
        data[{x, c}] = value;
    }
}

template <typename T>
bool MatrixMap<T>::isExist(int x, char c) const
{
    if (x <= 0 || x > rows || c > cols || c < 'A')
    {
        return false;
    }
    else
    {
        return data.find({x, c}) != data.end();
    }
}


// Function to get value at a specific position
template <typename T>
T MatrixMap<T>::getValue(int x, char c) const
{
    if (x <= 0 || x > rows || c > cols || c < 'A')
    {
        cout << "Invalid position!" << endl;
        return T(); // Ini akan memanggil konstruktor default dari kelas Product
    }
    else
    {
        auto it = data.find({x, c});
        if (it != data.end())
        {
            return it->second;
        }
        else
        {
            // Return a default value
            return T(); // Ini akan memanggil konstruktor default dari kelas Product
        }
    }
}

// Function to get number of rows
template <typename T>
int MatrixMap<T>::getRows() const
{
    return rows;
}

// Function to get number of columns
template <typename T>
int MatrixMap<T>::getCols() const
{
    return cols;
}

// Function to print the matrix
template <typename T>
void MatrixMap<T>::print() const
{
    cout << "     ";
    for (char i = 'A'; i <= cols; i++)
    {
        cout << "  "<< i <<"   ";
    }
    cout << endl << "    ";
    for (char i = 'A'; i <= cols; i++)
    {
        cout << "+-----";
    }
    cout << "+" <<endl;
    for (int i = 1; i <= rows; i++)
    {
        cout << " 0"<<i<<" |";
        for (char j = 'A'; j <= cols; j++)
        {
            if (isExist(i, j))
            {
                cout << " " << getValue(i, j) << " |";
            }
            else
            {
                cout << "     |";
            }
        }
        cout << endl << "    ";
        for (char i = 'A'; i <= cols; i++)
        {
            cout << "+-----";
        }
        cout << "+" <<endl;
    }
}
