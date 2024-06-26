#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include "Walikota.hpp"
#include "../Items/Bangunan.hpp"

// using namespace std;

Walikota::Walikota(string nama, int n, char m) : Player(nama, n, m) {}

Walikota::Walikota(string nama, int n, char m, int weight, int money) : Player(nama, n, m, weight, money) {}

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
        throw penyimpananPenuhExeption();
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
            if (a == "Batal" || a == "batal" || a == "BATAL" || a == "B" || a == "b") {
                cout << "Pembangunan dibatalkan!" << endl;
                return;
            } else if (!adaResep) {
                cout << "Bangunan yang dimasukkan tidak valid!" << endl;
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

        for (int j = 0; j < static_cast<int>(resep.at(idx).getNamaMaterialWhole().size()); j++) {
            removeBahan(resep.at(idx).getNamaMaterial(j), resep.at(idx).getJumlahMaterialNeeded(j));
        }

        Bangunan * bangun = new Bangunan(resep.at(idx).getID(), resep.at(idx).getCode(), resep.at(idx).getName(), resep.at(idx).getPrice());
        inventory += bangun;
        
        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    }
}

int Walikota::getPajak(vector<Recipe> resep) {return 0;}

void Walikota::dapatPajak(vector<Recipe> resep) {
    std::vector<std::pair<std::string, std::pair<std::string, int>>> sorted_data;
    int total = 0, totalTemp;
    cout << "Cring cring cring..." << endl << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < static_cast<int>(players.size()); i++) {
        if (players.at(i)->getRole() == "Walikota") {
            continue;
        } else {
            totalTemp = players.at(i)->getPajak(resep);
            sorted_data.push_back(std::make_pair(players.at(i)->getName(), std::make_pair(players.at(i)->getRole(), totalTemp)));
            total += totalTemp;
        }
    }

    // print pajak berurut berdasarkan totalTemp, mulai dari yang paling besar
    
    std::sort(sorted_data.begin(), sorted_data.end(), [](const std::pair<std::string, std::pair<std::string, int>>& left, const std::pair<std::string, std::pair<std::string, int>>& right) {
        return left.second.second > right.second.second;
    });

    int j = 1;
    for (const auto& pair : sorted_data) {
        cout << j << ". " << pair.first << " - " << pair.second.first << ": " << pair.second.second << " gulden" << endl;
        j++;
    }

    this->money += total;
    cout << endl << "Negara mendapatkan pemasukkan sebesar " << total << " gulden." << endl << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::tambahPemain(Misc misc) {
    string jenis_pemain;
    string nama_pemain = "";
    bool validName = true, spaceName = false;

    if (money < 50) {
        throw noMoneyException();
    } else {
        cout << "Masukkan jenis pemain (petani / peternak): ";
        cin >> jenis_pemain;
        while (jenis_pemain != "peternak" && jenis_pemain != "petani" && jenis_pemain != "Peternak" && jenis_pemain != "Petani") {
            cout << "Jenis pemain tidak valid. Masukkan jenis pemain: ";
            cin >> jenis_pemain;
        }
        cin.ignore();
        cout << "Masukkan nama pemain: ";
        getline(cin, nama_pemain);
        nama_pemain = trim(nama_pemain);

        for (int i = 0; i < static_cast<int>(players.size()); i++) {
            if (players.at(i)->getName() == nama_pemain) {
                validName = false;
            }
        }

        if (nama_pemain.empty() || all_of(nama_pemain.begin(), nama_pemain.end(), ::isspace)) {
            spaceName = true;
        }

        while (!validName || spaceName) {
            if (!validName) {
                cout << "Nama pemain sudah ada. Masukkan nama pemain: ";
                getline(cin, nama_pemain);
                nama_pemain = trim(nama_pemain);
                validName = true;
                for (int i = 0; i < static_cast<int>(players.size()); i++) {
                    if (players.at(i)->getName() == nama_pemain) {
                        validName = false;
                    }
                }
                if (nama_pemain.empty() || all_of(nama_pemain.begin(), nama_pemain.end(), ::isspace)) {
                    spaceName = true;
                }
            } else if (spaceName) {
                cout << "Nama macam apa ini Σ(°ロ°) ??? Orang waras mana yang ingin menamai anaknya seperti ini (⊙_⊙) ??? Coba ulangi lagi, kali ini jangan aneh-aneh namanya ya." << endl << "Masukkan nama pemain: ";
                getline(cin, nama_pemain);
                nama_pemain = trim(nama_pemain);
                spaceName = false;
                for (int i = 0; i < static_cast<int>(players.size()); i++) {
                    if (players.at(i)->getName() == nama_pemain) {
                        validName = false;
                    }
                }
                if (nama_pemain.empty() || all_of(nama_pemain.begin(), nama_pemain.end(), ::isspace)) {
                    spaceName = true;
                }
            }
        }



        if (jenis_pemain == "peternak" || jenis_pemain == "Peternak") {
            Peternak *ar = new Peternak(nama_pemain, 40, 50, misc.getFarmSize().first, misc.getFarmSize().second);
            money -= 50;
        } else if (jenis_pemain == "petani" || jenis_pemain == "Petani") {
            Petani *ar = new Petani(nama_pemain, misc.getStorageSize().first, misc.getStorageSize().second, misc.getFarmSize().first, misc.getFarmSize().second);
            money -= 50;
        }

        for (int i = 0; i < static_cast<int>(players.size()); i++) {
            cout << players.at(i)->getName() << endl;
        }
        cout << "Pemain baru ditambahkan!" << endl << "Selamat datang " << '"' << nama_pemain << '"' << " di kota ini!" << endl;
    }
}

string Walikota::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}