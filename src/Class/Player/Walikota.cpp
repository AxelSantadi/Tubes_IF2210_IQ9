#include <iostream>
#include "Walikota.hpp"
#include "Inventory.hpp"
#include "MatrixMap.hpp"
#include "../Data/Misc.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "Player.hpp"
#include "../Data/ReadConfig.hpp"
#include "../Data/ReadConfig.cpp"

using namespace std;

Walikota::Walikota() : w_storage(Inventory(getStorageSize().first, getStorageSize().second)) {
    this->Berat_badan = 40;
    this->w_gulden = 50;
}

Walikota::~Walikota() {}

void Walikota::buatBangunan() {
    if (w_storage.isFull()) {
        cout << "Bangunan sudah penuh!" << endl;
        return;
    } else {
        printBangunan();
        string a;
        cout << "Bangunan yang ingin dibangun (bisa ketik 'Batal' untuk membatalkan): ";
        cin >> a;
        while (!resep.cekResep(a) || !resep.cekBahan(a)) {
            if (a == "Batal") {
                cout << "Pembangunan dibatalkan!" << endl;
                return;
            } else if (!resep.cekResep(a)) {
                cout << "Kamu tidak punya resep bangunan tersebut!";
                resep.printBangunan();
                cout << "Bangunan yang ingin dibangun: ";
                cin >> a;
            } else if (!resep.cekBahan(a)){
                cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << resep.selisihBahan(a, w_storage) << "!" << endl << endl;
                cout << "Bangunan yang ingin dibangun: ";
                cin >> a;
            }
        }

        
        cout << a << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
    }
}

void Walikota::jualBangunan() {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    w_storage.print();
    int a;
    cout << "Ada berapa bangunan yang ingin dijual: ";
    cin >> a;
    
    for (int i = 0; i < a; i++) {
        cout << "Silahkan pilih petak yang ingin Anda jual!" << endl << "Petak: ";
        cin >> 
    }
}

float Walikota::tagihPajak() {
    float total;
    cout << "Cring cring cring..." << endl << "Pajak sudah dipungut!" << endl << endl;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < players.size(); i++) {
        cout << i+1 << ". " << players.at(i)->getName() << " - " << getJenis() << ": " << players.at(i)->getPajak() << "Gulden" << endl;
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
            Peternak a(nama_pemain);
            players.push_back(a);
            w_gulden -= 50;
        } else if (jenis_pemain == "petani" || jenis_pemain == "Petani") {
            Petani a(nama_pemain);
            pemain.push_back(a);
            w_gulden -= 50;
        }

        cout << "Pemain baru ditambahkan!" << endl << 'Selamat datang "' << nama_pemain << '" di kota ini!' << endl;
    }
}