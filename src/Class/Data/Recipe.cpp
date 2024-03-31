#include "Recipe.hpp"

Recipe::Recipe(int id, string code, string name, int price, vector<string> namaMaterial, vector<int> jumlahMaterialNeeded) {
    this->id = id;
    this->code = code;
    this->name = name;
    this->price = price;
    this->namaMaterial = namaMaterial;
    this->jumlahMaterialNeeded = jumlahMaterialNeeded;
}

bool Recipe::cekResep(string name) {
    for (int i = 0; i < this->name.size(); i++) {
        if (this->name == name) {
            return true;
        }
    }
    return false;
}

    /*Resep bangunan yang ada adalah sebagai berikut.
        1. SMALL_HOUSE (50 gulden, teak wood 1, sandal wood 1)
        2. MEDIUM_HOUSE (70 gulden, aloe wood 1, ironwood wood 1)
        3. LARGE_HOUSE (90 gulden, teak wood 2, aloe wood 1, ironwood wood 1)
        4. HOTEL (150 gulden, teak wood 3, aloe wood 4, ironwood wood 4, sandal wood 2)
    */
void Recipe::printBangunan() {
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    for (int i = 0; i < this->name.size(); i++) {
        cout << i + 1 << ". " << this->name << " (" << this->price << " gulden, ";
        for (int j = 0; j < namaMaterial.size(); j++) {
            cout << namaMaterial[j] << " " << jumlahMaterialNeeded[j] << ", ";
        }
        cout << ")" << endl;
    }
}

void Recipe::selisihBahan(string name, Inventory w_storage) {
    for (int i = 0; i < this->name.size(); i++) {
        if (this->name == name) {
            for (int j = 0; j < namaMaterial[i].size(); j++) {
                if (jumlahMaterialNeeded[j] > w_storage.getJenisTiapItemNama(namaMaterial[j])) {
                    cout << jumlahMaterialNeeded[j] - w_storage.getJenisTiapItemNama(namaMaterial[j]) << " " << namaMaterial[i][j] << "!" << endl;
                }
            }
        }
    }
}