#include "MatrixMap.hpp"

// Constructor
template <typename T>
MatrixMap<T>::MatrixMap(int rows , char cols) : rows(rows), cols(cols){}

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

// Function to check if the matrix is full
template <typename T>
bool MatrixMap<T>::isFull() const
{
    return data.size() == rows * (cols - 'A' + 1);
}

// Function to check if the matrix is empty
template <typename T>
bool MatrixMap<T>::isEmpty() const
{
    return data.size() == 0;
}

template <typename T>
map<pair<int, char>, T> MatrixMap<T>::getData() const
{
    return data;
}
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
void MatrixMap<T>::removeValue(int x, char c)
{
    if (x <= 0 || x > rows || c > cols || c < 'A')
    {
        cout << "Invalid position!" << endl;
        // nanti pakai exception
    }
    else
    {
        data.erase({x, c});
    }
}

template <typename T>
T MatrixMap<T>::getValue(int x, char c) const
{
    if (x <= 0 || x > rows || c > cols || c < 'A')
    {
        cout << "Invalid position!" << endl;
        return T();
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
            return T(); 
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
char MatrixMap<T>::getCols() const
{
    return cols;
}

template <typename T>
int MatrixMap<T>::countEmpty() const
{
    return rows * (cols - 'A' + 1) - data.size();
}

template <typename T>
int MatrixMap<T>::countNotEmpty() const
{
    return data.size();
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
        if (i < 10)
        {
            cout << " 0"<<i<<" |";
        }
        else
        {
            cout << " "<<i<<" |";
        }
        
        for (char j = 'A'; j <= cols; j++)
        {
            if (isExist(i, j))
            {
                cout << " " << *getValue(i, j) << " |";
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
