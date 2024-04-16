/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <iostream>
#include "pcolor.hpp"

using namespace std;

void print_red(char c)
{
    cout << RED << c << NORMAL;
}

void print_green(char c)
{
    cout << GREEN << c << NORMAL;
}

void print_blue(char c)
{
    cout << BLUE << c << NORMAL;
}
