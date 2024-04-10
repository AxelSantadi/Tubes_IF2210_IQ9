#include <iostream>
#include "Walikota.hpp"
#include "../Items/Bangunan.hpp"

// using namespace std;

Walikota::Walikota(string nama, int n, char m) : Player(nama, n, m) {}

Walikota::Walikota(string nama, int n, char m, int money, int weight) : Player(nama, n, m, money, weight) {}

Walikota::~Walikota() {}

string Walikota::getRole() const {
    return "Walikota";
}

void Walikota::saveStatePlayer(ofstream &file) const 
{
    Player::saveStatePlayer(file);
}

// nih keknya errornya disini
void Walikota::removeBahan(string namaBahan, int jumlah) {
    for (char j = 'A'; j <= getInventory().getCols(); j++) {
        for (int i = 1; i <= getInventory().getRows(); i++) {
            if (!getInventory().isExist(i,j)) {
                continue;
            } else if (getInventory().getValue(i, j)->getName() == namaBahan && getInventory().isExist(i,j)) {
                removeItem(i, j);
                jumlah -= 1;
            }
        }
    }
}

void Walikota::buatBangunan(vector<Recipe> resep) {
    if (getInventoryPointer().isFull()) {
        cout << "Bangunan sudah penuh!" << endl;
        return;
    } else {
        cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
        int idx, resepSize = resep.size();
        for (int i = 0; i < resepSize; i++) {
            resep.at(i).printBangunan(i+1);
        }
        string a;
        cout << endl << "Bangunan yang ingin dibangun (bisa ketik 'Batal' untuk membatalkan): ";
        cin >> a;
        bool adaResep = false, adaBahan = true;

        for (int i = 0; i < resepSize; i++) {
            if (resep.at(i).getName() == a) {
                adaResep = true;
                idx = i;
            }
        }

        if (adaResep) {
            int p = resep.at(idx).getNamaMaterialWhole().size();
            for (int j = 0; j < p; j++) {
                if (getInventoryPointer().getJenisTiapItemNama(resep.at(idx).getNamaMaterial(j)) < resep.at(idx).getJumlahMaterialNeeded(j)) {
                    adaBahan = false;
                }
            }
        }

        while (!adaResep || !adaBahan) {
            if (a == "Batal" || a == "batal") {
                cout << "Pembangunan dibatalkan!" << endl;
                return;
            } else if (!adaResep) {
                cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
                adaResep = false;
                adaBahan = true;
                for (int i = 0; i < resepSize; i++) {
                    resep.at(i).printBangunan(i+1);
                }
                cout << endl << "Bangunan yang ingin dibangun (bisa ketik 'Batal' untuk membatalkan): ";
                cin >> a;
            } else if (!adaBahan){
                cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
                resep.at(idx).selisihBahan(a, getInventoryPointer());
                cout << endl << endl;
                adaResep = false;
                adaBahan = true;
                cout << endl << "Bangunan yang ingin dibangun (bisa ketik 'Batal' untuk membatalkan): ";
                cin >> a;
            }

            for (int i = 0; i < resepSize; i++) {
                if (resep.at(i).getName() == a) {
                    adaResep = true;
                    idx = i;
                }
            }

            if (adaResep) {
                int p = resep.at(idx).getNamaMaterialWhole().size();
                for (int j = 0; j < p; j++) {
                    if (getInventoryPointer().getJenisTiapItemNama(resep.at(idx).getNamaMaterial(j)) < resep.at(idx).getJumlahMaterialNeeded(j)) {
                        adaBahan = false;
                    }
                }
            }
        }

        for (int j = 0; j < resep.at(idx).getNamaMaterialWhole().size(); j++) {
            removeBahan(resep.at(idx).getNamaMaterial(j), resep.at(idx).getJumlahMaterialNeeded(j));
        }

        Bangunan * bangun = new Bangunan(resep.at(idx).getID(), resep.at(idx).getCode(), resep.at(idx).getName(), resep.at(idx).getPrice());
        inventory.setRandomValue(bangun);
        
        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    }
}

int Walikota::getPajak(vector<Recipe> resep) {return 0;}

void Walikota::dapatPajak(vector<Recipe> resep) {
    int total = 0, totalTemp;
    int j = 1;
    cout << "Cring cring cring..." << endl << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i)->getRole() == "Walikota") {
            continue;
        } else {
            totalTemp = players.at(i)->getPajak(resep);
            cout << j << ". " << players.at(i)->getName() << " - " << players.at(i)->getRole() << ": " << totalTemp << " Gulden" << endl;
            total += totalTemp;
            j++;
        }
    }
    this->money += total;
    cout << "Negara mendapatkan pemasukkan sebesar " << total << " gulden." << endl << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::tambahPemain(Misc misc) {
    string jenis_pemain;
    string nama_pemain;
    for (int i = 0; i < players.size(); i++) {
        cout << players.at(i)->getName() << endl;
    }

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
            Peternak *ar = new Peternak(nama_pemain, 40, 50, misc.getFarmSize().first, misc.getFarmSize().second);
            money -= 50;
        } else if (jenis_pemain == "petani" || jenis_pemain == "Petani") {
            Petani *ar = new Petani(nama_pemain, misc.getStorageSize().first, misc.getStorageSize().second, misc.getFarmSize().first, misc.getFarmSize().second);
            money -= 50;
        }

        for (int i = 0; i < players.size(); i++) {
            cout << players.at(i)->getName() << endl;
        }
        cout << "Pemain baru ditambahkan!" << endl << "Selamat datang " << '"' << nama_pemain << '"' << " di kota ini!" << endl << endl;
    }
}