#include <iostream>
#include "Walikota.hpp"
#include "Inventory.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "../Data/ReadConfig.hpp"
#include "../Data/ReadConfig.cpp"


Walikota::Walikota(Misc m) : Player("Walikota", m.getStorageSize().first, m.getStorageSize().second) {}

Walikota::~Walikota() {}

string Walikota::getRole() const {
    return "Walikota";
}

void Walikota::saveStatePlayer(ofstream &file) const 
{
    Player::saveStatePlayer(file);
}

void Walikota::removeBahan(string namaBahan, int jumlah) {
    for (int i = 0; i < inventory.getRows(); i++) {
        for (int j = 'A'; j < inventory.getCols(); j++) {
            if (inventory.getValue(i, j)->getName() == namaBahan) {
                inventory.removeValue(i, j);
                jumlah--;
            }
        }
    }
}

void Walikota::buatBangunan(Misc m, vector<Recipe> resep) {
    if (inventory.isFull()) {
        cout << "Bangunan sudah penuh!" << endl;
        return;
    } else {
        cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
        int idx;
        for (int i = 0; i < resep.size(); i++) {
            resep.at(i).printBangunan(i+1);
        }
        string a;
        cout << "Bangunan yang ingin dibangun (bisa ketik 'Batal' untuk membatalkan): ";
        cin >> a;
        bool adaResep = false, adaBahan = true;

        for (int i = 0; i < resep.size(); i++) {
            if (resep.at(i).getName() == a) {
                adaResep = true;
                idx = i;
            }
        }

        if (adaResep) {
            for (int j = 0; j < resep.at(idx).getNamaMaterialWhole().size(); j++) {
                if (inventory.getJenisTiapItem(resep.at(idx).getNamaMaterial(j)) < resep.at(idx).getJumlahMaterialNeeded(j)) {
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
                for (int i = 0; i < resep.size(); i++) {
                    resep.at(i).printBangunan(i+1);
                }
                cout << "Bangunan yang ingin dibangun: ";
                cin >> a;
            } else if (!adaBahan){
                cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
                resep.at(idx).selisihBahan(a, inventory);
                cout << "!" << endl << endl;
                adaResep = false;
                adaBahan = true;
                cout << "Bangunan yang ingin dibangun: ";
                cin >> a;
            }

            for (int i = 0; i < resep.size(); i++) {
                if (resep.at(i).getName() == a) {
                    adaResep = true;
                    idx = i;
                }
            }

            if (adaResep) {
                for (int j = 0; j < resep.at(idx).getNamaMaterialWhole().size(); j++) {
                    if (inventory.getJenisTiapItem(resep.at(idx).getNamaMaterial(j)) < resep.at(idx).getJumlahMaterialNeeded(j)) {
                        adaBahan = false;
                    }
                }
            }
        }

        for (int i = 0; i < resep.size(); i++) {
            if (resep.at(i).getName() == a) {
                for (int j = 0; j < resep.at(i).getNamaMaterialWhole().size(); j++) {
                    removeBahan(resep.at(i).getNamaMaterial(j), resep.at(i).getJumlahMaterialNeeded(j));
                }
            }
        }

        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    }
}

float Walikota::tagihPajak() {
    float total;
    cout << "Cring cring cring..." << endl << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < players.size(); i++) {
        cout << i+1 << ". " << players.at(i)->getName() << " - " << getRole() << ": " << players.at(i)->getPajak() << "Gulden" << endl;
        total += getPajak();
    }
    money += total;
    cout << "Negara mendapatkan pemasukkan sebesar " << total << " gulden." << endl << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::tambahPemain(Misc misc) {
    string jenis_pemain;
    string nama_pemain;
    if (money < 50) {
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
            Peternak *ar;
            Peternak a(nama_pemain, 40, 50, misc.getFarmSize().first, misc.getFarmSize().second);
            ar = &a;
            players.push_back(ar);
            money -= 50;
        } else if (jenis_pemain == "petani" || jenis_pemain == "Petani") {
            Petani *ar;
            Petani a(nama_pemain, 40, 50, misc.getFarmSize().first, misc.getFarmSize().second);
            ar = &a;
            players.push_back(ar);
            money -= 50;
        }

        cout << "Pemain baru ditambahkan!" << endl << 'Selamat datang "' << nama_pemain << '" di kota ini!' << endl;
    }
}

void Walikota::wMakan() {
    bool success = false;
    string slot;
    if (inventory.isEmpty())
    {
        throw EmptyInventoryException();
    }
    else if (inventory.noFood())
    {
        throw noFoodInInventory();
    }
    else
    {
        cout << "Pilih makanan dari peyimpanan" << endl;
        inventory.print();
        while (!success)
        {
            try
            {
                cout << "Slot: ";
                cin >> slot;
                char col = slot[0];
                int row = stoi(slot.substr(1));
                cout << inventory.getRows() << " " << row << " " << inventory.getCols() << " " << col << endl;
                if (inventory.isExist(row, col))
                {
                    Item *p = inventory.getValue(row, col);
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
                else if (inventory.getRows() < row || 1 < row || inventory.getCols() < col || 'A' < col)
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