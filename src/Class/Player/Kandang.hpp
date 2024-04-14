#ifndef KANDANG_HPP
#define KANDANG_HPP

#include <iostream>
#include "MatrixMap.hpp"
#include <string>
#include <unordered_map>
#include <vector>
#include "../Items/Animal.hpp"
#include "../Exception/Exception.hpp"
#include "../Exception/fileException.hpp"
#include "../Exception/inventoryException.hpp"
#include "../Exception/itemException.hpp"
#include "../Exception/playerException.hpp"
using namespace std;

class Kandang : public MatrixMap<Animal>{
        
    public:
        Kandang(int panjang, char lebar);
        void cetakKandang();
        void cetakKandangPanen();
        unordered_map<string,int> countPanen();
        void cetakJenisHewan();
        Animal getAnimal(int x, char a) const;
        vector<string> ambilPanenhewan(string code, int n);
};
#endif