#include <iostream>
#include "Walikota.hpp"
#include "Inventory.hpp"
#include "../Data/Misc.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "Player.hpp"
#include "../Data/ReadConfig.hpp"


Walikota::Walikota() : w_storage(Inventory(getMisc().getStorageSize().first, getMisc().getStorageSize().second)) {
    this->Berat_badan = 40;
    this->w_gulden = 50;
}

Walikota::~Walikota() {}

string Walikota::getRole() const {
    return "Walikota";
}

void Walikota::saveStatePlayer(ofstream &file) const 
{
    Player::saveStatePlayer(file);
}

void Walikota::removeBahan(string namaBahan, int jumlah) {
    for (int i = 0; i < w_storage.getRows(); i++) {
        for (int j = 'A'; j < w_storage.getCols(); j++) {
            if (w_storage.getValue(i, j)->getName() == namaBahan) {
                w_storage.removeValue(i, j);
                jumlah--;
            }
        }
    }
}

void Walikota::buatBangunan() {
    if (w_storage.isFull()) {
        cout << "Bangunan sudah penuh!" << endl;
        return;
    } else {
        cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
        int idx;
        for (int i = 0; i < getRecipe().size(); i++) {
            getRecipe().at(i).printBangunan(i+1);
        }
        string a;
        cout << "Bangunan yang ingin dibangun (bisa ketik 'Batal' untuk membatalkan): ";
        cin >> a;
        bool adaResep = false, adaBahan = true;

        for (int i = 0; i < getRecipe().size(); i++) {
            if (getRecipe().at(i).getName() == a) {
                adaResep = true;
                idx = i;
            }
        }

        if (adaResep) {
            for (int j = 0; j < getRecipe().at(idx).namaMaterial.size(); j++) {
                if (w_storage.getJenisTiapItem(getRecipe().at(idx).getNamaMaterial(j)) < getRecipe().at(idx).getJumlahMaterialNeeded(j)) {
                    adaBahan = false;
                }
            }
        }

        while (!adaResep || !adaBahan) {
            if (a == "Batal") {
                cout << "Pembangunan dibatalkan!" << endl;
                return;
            } else if (!adaResep) {
                cout << "Kamu tidak punya resep bangunan tersebut!";
                adaResep = false;
                adaBahan = true;
                for (int i = 0; i < getRecipe().size(); i++) {
                    getRecipe().at(i).printBangunan(i+1);
                }
                cout << "Bangunan yang ingin dibangun: ";
                cin >> a;
            } else if (!adaBahan){
                cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << getRecipe().at(idx).selisihBahan(a, w_storage) << "!" << endl << endl;
                adaResep = false;
                adaBahan = true;
                cout << "Bangunan yang ingin dibangun: ";
                cin >> a;
            }

            for (int i = 0; i < getRecipe().size(); i++) {
                if (getRecipe().at(i).getName() == a) {
                    adaResep = true;
                    idx = i;
                }
            }

            if (adaResep) {
                for (int j = 0; j < getRecipe().at(idx).namaMaterial.size(); j++) {
                    if (w_storage.getJenisTiapItem(getRecipe().at(idx).getNamaMaterial(j)) < getRecipe().at(idx).getJumlahMaterialNeeded(j)) {
                        adaBahan = false;
                    }
                }
            }
        }

        for (int i = 0; i < getRecipe().size(); i++) {
            if (getRecipe().at(i).getName() == a) {
                for (int j = 0; j < getRecipe().at(i).namaMaterial.size(); j++) {
                    removeBahan(getRecipe().at(i).getNamaMaterial(j), getRecipe().at(i).getJumlahMaterialNeeded(j));
                }
            }
        }

        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    }
}

void Walikota::jualBangunan() {}

float Walikota::tagihPajak() {
    float total;
    cout << "Cring cring cring..." << endl << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < players.size(); i++) {
        cout << i+1 << ". " << players.at(i)->getName() << " - " << getRole() << ": " << players.at(i)->getPajak() << "Gulden" << endl;
        total += getPajak();
    }
    w_gulden += total;
    cout << "Negara mendapatkan pemasukkan sebesar " << total << " gulden." << endl << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::tambahPemain() {
    string jenis_pemain;
    string nama_pemain;
    if (w_gulden < 50) {
        cout << "Uang tidak cukup";
    } else {
        cout << "Masukkan jenis pemain (petani / peternak): ";
        cin >> jenis_pemain;
        while (jenis_pemain != "peternak" && jenis_pemain != "petani" && jenis_pemain != "Peternak" && jenis_pemain != "Petani") {
            cout << "Jenis pemain tidak valid. Masukkan jenis pemain: ";
            cin >> jenis_pemain;
        }
        cout << "Masukkan nama pemain: ";
        cin >> nama_pemain;

        if (jenis_pemain == "peternak" || jenis_pemain == "Peternak") {
            Peternak a(nama_pemain, 40, 50, getMisc().getFarmSize().first, getMisc().getFarmSize().second);
            players.push_back(a);
            w_gulden -= 50;
        } else if (jenis_pemain == "petani" || jenis_pemain == "Petani") {
            Petani a(nama_pemain);
            players.push_back(a);
            w_gulden -= 50;
        }

        cout << "Pemain baru ditambahkan!" << endl << 'Selamat datang "' << nama_pemain << '" di kota ini!' << endl;
    }
}

void Walikota::wMakan() {
    bool success = false;
    string slot;
    if (w_storage.isEmpty())
    {
        throw EmptyInventoryException();
    }
    else if (w_storage.noFood())
    {
        throw noFoodInInventory();
    }
    else
    {
        cout << "Pilih makanan dari peyimpanan" << endl;
        w_storage.print();
        while (!success)
        {
            try
            {
                cout << "Slot: ";
                cin >> slot;
                char col = slot[0];
                int row = stoi(slot.substr(1));
                cout << w_storage.getRows() << " " << row << " " << w_storage.getCols() << " " << col << endl;
                if (w_storage.isExist(row, col))
                {
                    Item *p = w_storage.getValue(row, col);
                    if (p->isMakanan())
                    {
                        addWeight(p->getAddedWeight());
                        removeItem(row, col);
                        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                        cout << "Alhasil, berat badan kamu naik menjadi " << getWeight() << endl
                             << endl;
                        success = true;
                    }
                    else
                    {
                        throw BukanMakananException();
                    }
                }
                else if (w_storage.getRows() < row || 1 < row || w_storage.getCols() < col || 'A' < col)
                {
                    throw outOfBoundException();
                }
                else
                {
                    throw SlotKosongException();
                }
            }
            catch (BukanMakananException &e)
            {
                cerr << e.what() << endl
                     << "Silahkan masukan slot yang berisi makanan.\n\n";
            }
            catch (outOfBoundException &e)
            {
                cerr << e.what() << endl
                     << "Silahkan masukan slot yang benar.\n\n";
            }
            catch (SlotKosongException &e)
            {
                cerr << e.what() << endl
                     << "Silahkan masukan slot yang berisi makanan.\n\n";
            }
        }
    }
}