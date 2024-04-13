#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "ladang.cpp"

#include "../Data/Exception.hpp"
#include "../Data/Exception.cpp"

#include "MatrixMap.cpp"

int main()
{
        Ladang ladang(5, 'E');
        Plant plant1 (1, "TAW", "Teak Wood Tree", "Material Tree", 4, 1000);
        Plant plant2 (1, "TAW", "Teak Wood Tree", "Material Tree", 4, 1000);
        ladang.setValue(1, 'E', plant1);
        ladang.setValue(2, 'E', plant2);
        ladang.cetakLadang();
        ladang.cetakJenisTanaman();
    return 0;
}