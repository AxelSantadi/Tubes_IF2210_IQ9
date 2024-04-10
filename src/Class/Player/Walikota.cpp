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
    for (int i = 1; i <= getInventoryPointer().getRows(); i++) {
        for (char j = 'A'; j < getInventoryPointer().getCols(); j++) {
            if (getInventoryPointer().getValue(i, j)->getName() == namaBahan) {
                cout << getInventoryPointer().getValue(i, j)->getName() << endl;
                getInventoryPointer().getData().erase({i, j});
                jumlah -= 1;
            }
        }
    }
}

void Walikota::removeBahan(string namaBahan, int jumlah, Inventory inven) {
    for (int i = 1; i <= inven.getRows(); i++) {
        for (char j = 'A'; j < inven.getCols(); j++) {
            if (inven.getValue(i, j)->getName() == namaBahan && jumlah > 0) {
                inven.removeValue(i, j);
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
            if (a == "Batal") {
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
            this->removeBahan(resep.at(idx).getNamaMaterial(j), resep.at(idx).getJumlahMaterialNeeded(j));
            cout << "removed bahan " << j+1 << endl;
        }

        Bangunan bangun(resep.at(idx).getID(), resep.at(idx).getCode(), resep.at(idx).getName(), resep.at(idx).getPrice());
        
        for (int i = 1; i <= getInventoryPointer().getRows(); i++) {
            for (char j = 'A'; j < getInventoryPointer().getCols(); j++) {
                if (!getInventoryPointer().isExist(i, j)) {
                    getInventoryPointer().setValue(i, j, &bangun);
                }
            }
        }
        
        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
        
    }
}

void Walikota::buatBangunan(vector<Recipe> resep, Inventory invent) {
    if (invent.isFull()) {
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
                if (invent.getJenisTiapItemNama(resep.at(idx).getNamaMaterial(j)) < resep.at(idx).getJumlahMaterialNeeded(j)) {
                    adaBahan = false;
                }
            }
        }

        while (!adaResep || !adaBahan) {
            if (a == "Batal") {
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
                resep.at(idx).selisihBahan(a, invent);
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
                    if (invent.getJenisTiapItemNama(resep.at(idx).getNamaMaterial(j)) < resep.at(idx).getJumlahMaterialNeeded(j)) {
                        adaBahan = false;
                    }
                }
            }
        }

        int p = resep.at(idx).getNamaMaterialWhole().size();
        for (int j = 0; j < p; j++) {
            removeBahan(resep.at(idx).getNamaMaterial(j), resep.at(idx).getJumlahMaterialNeeded(j), invent);
        }

        Bangunan bangun(resep.at(idx).getID(), resep.at(idx).getCode(), resep.at(idx).getName(), resep.at(idx).getPrice());
        for (int i = 1; i <= invent.getRows(); i++) {
            for (char j = 'A'; j < invent.getCols(); j++) {
                if (!invent.isExist(i, j)) {
                    invent.setValue(i, j, &bangun);
                }
            }
        }
        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
        
    }
}

int Walikota::getPajak(vector<Recipe> resep) {
    float total;
    int playerSize = players.size();
    cout << "Cring cring cring..." << endl << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < playerSize; i++) {
        if (players.at(i)->getRole() == "Walikota") {
            continue;
        } else {
            cout << i+1 << ". " << players.at(i)->getName() << " - " << getRole() << ": " << players.at(i)->getPajak(resep) << "Gulden" << endl;
            total += getPajak(resep);
        }
    }
    cout << "Negara mendapatkan pemasukkan sebesar " << total << " gulden." << endl << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
    return total;
}

void Walikota::dapatPajak(vector<Recipe> resep) {
    money += getPajak(resep);
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

        cout << "Pemain baru ditambahkan!" << endl << "Selamat datang " << '"' << nama_pemain << '"' << " di kota ini!" << endl;
    }
}