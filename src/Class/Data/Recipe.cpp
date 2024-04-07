#include "Recipe.hpp"
#include "ReadConfig.hpp"

Recipe::Recipe(int id, string code, string name, int price, vector<string> namaMaterial, vector<int> jumlahMaterialNeeded) {
    this->id = id;
    this->code = code;
    this->name = name;
    this->price = price;
    this->namaMaterial = namaMaterial;
    this->jumlahMaterialNeeded = jumlahMaterialNeeded;
}

bool Recipe::cekResep(string name) {
    if (this->name == name) {
        return true;
    } else {
        return false;
    }
}

    /*Resep bangunan yang ada adalah sebagai berikut.
        1. SMALL_HOUSE (50 gulden, teak wood 1, sandal wood 1)
        2. MEDIUM_HOUSE (70 gulden, aloe wood 1, ironwood wood 1)
        3. LARGE_HOUSE (90 gulden, teak wood 2, aloe wood 1, ironwood wood 1)
        4. HOTEL (150 gulden, teak wood 3, aloe wood 4, ironwood wood 4, sandal wood 2)
    */
void Recipe::printBangunan(int i) {
    cout << i << ". " << this->name << " (" << this->price << " gulden, ";
    for (int j = 0; j < namaMaterial.size(); j++) {
        cout << namaMaterial[j] << " " << jumlahMaterialNeeded[j];
        if (j == namaMaterial.size() - 1) {
            cout << ")" << endl;
        } else {
            cout << ", ";
        }
    }
}

void Recipe::selisihBahan(string name, Inventory w_storage) {
    for (int i = 0; i < namaMaterial.size(); i++) {
        if (w_storage.getJenisTiapItem(namaMaterial[i]) < jumlahMaterialNeeded[i]) {
            cout << jumlahMaterialNeeded[i] - w_storage.getJenisTiapItem(namaMaterial[i]) << " " << namaMaterial[i] << endl;
        }
    }
}

void Recipe::setID(int id) {
    this->id = id;
}

void Recipe::setCode(string code) {
    this->code = code;
}

void Recipe::setName(string name) {
    this->name = name;
}

void Recipe::setPrice(int price) {
    this->price = price;
}

void Recipe::setNamaMaterial(vector<string> namaMaterial) {
    this->namaMaterial = namaMaterial;
}

void Recipe::setSatuNamaMaterial(string namaMaterial) {
    this->namaMaterial.push_back(namaMaterial);
}

void Recipe::setJumlahMaterialNeeded(vector<int> jumlahMaterialNeeded) {
    this->jumlahMaterialNeeded = jumlahMaterialNeeded;
}

void Recipe::setSatuJumlahMaterialNeeded(int jumlahMaterialNeeded) {
    this->jumlahMaterialNeeded.push_back(jumlahMaterialNeeded);
}

int Recipe::getID() {
    return id;
}

string Recipe::getCode() {
    return code;
}

string Recipe::getName() {
    return name;
}

int Recipe::getPrice() {
    return price;
}

string Recipe::getNamaMaterial(int idx) {
    return namaMaterial[idx];
}

int Recipe::getJumlahMaterialNeeded(int idx) {
    return jumlahMaterialNeeded[idx];
}