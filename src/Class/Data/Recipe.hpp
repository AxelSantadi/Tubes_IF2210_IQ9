#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../Player/Inventory.hpp"

using namespace std;

class Recipe {
public:
    /*
    1 SMH SMALL_HOUSE 50 TEAK_WOOD 1 SANDAL_WOOD 1
    2 MDH MEDIUM_HOUSE 70 ALOE_WOOD 1 IRONWOOD_WOOD 1
    3 LRH LARGE_HOUSE 90 TEAK_WOOD 2 ALOE_WOOD 1 IRONWOOD_WOOD 1
    4 HTL HOTEL 150 TEAK_WOOD 3 ALOE_WOOD 4 IRONWOOD_WOOD 4 SANDAL_WOOD 2
    */
   Recipe(int id, string code, string name, int price, vector<string> namaMaterial, vector<int> jumlahMaterialNeeded);
    
    bool cekResep(string name);
    /*Resep bangunan yang ada adalah sebagai berikut.
        1. SMALL_HOUSE (50 gulden, teak wood 1, sandal wood 1)
        2. MEDIUM_HOUSE (70 gulden, aloe wood 1, ironwood wood 1)
        3. LARGE_HOUSE (90 gulden, teak wood 2, aloe wood 1, ironwood wood 1)
        4. HOTEL (150 gulden, teak wood 3, aloe wood 4, ironwood wood 4, sandal wood 2)
    */

    void printBangunan();

    
    void selisihBahan(string name, Inventory w_storage);
    
private:
    int id;
    string code;
    string name;
    int price;
    vector<string> namaMaterial;
    vector<int> jumlahMaterialNeeded;
};