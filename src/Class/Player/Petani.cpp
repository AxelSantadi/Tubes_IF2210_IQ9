#include "Petani.hpp"
using namespace std;
Petani::Petani(string nama, int Berat_badan, int w_gulden, int panjang , int lebar): Player(nama, Berat_badan, w_gulden), ladang(panjang,lebar)
{}

void Petani::tanam(const Petani& p){
    // cetak inventory
    cout << "Pilih tanaman dari penyimpanan :" << endl;

    inventory.printInventory();
    cout << "Slot :" << endl;
    string slot;
    cin >> slot;
    char a;
    int b;
    a = slot[0];
    slot = slot.substr(1, slot.length()-1);
    b = stoi(slot);
    Item plant = inventory.getValue(b,a);
    // pilih barang dari inventory

    cout << "Kamu memilih" << plant.getName() << endl;
    // pilih posisi tanam
    cout << "Pilih petak tanah yang akan ditanami ";
    ladang.cetakLadang();
    // cetak ladang 

    // pilih posisi tanam
    string posisi;
    cout << "Petak tanah : ";
    cin >> posisi;
    cout << endl;
    int x;
    int y;
    x = stoi(posisi.substr(0, 1));
    x = x - 65;
    posisi = posisi.substr(1, posisi.length()-1);
    y = stoi(posisi);
    
    // tanam


    cout << "Cangkul, cangkul, cangkul, yang dalam ~!" << endl;
    cout << plant.getName() << " berhasil ditanam " <<endl;
}

void Petani::panen(){
    // print ladang
    ladang.cetakLadang();
    
    // print isi ladang
    ladang.cetakJenisTanaman();
    
    // pilih panen
    cout << "Pilih tanaman siap panen yang kamu miliki " << endl;
    int i = 1 ; // indeks pilihan
    map<int,pair<string,int>> pilihan;
    for (auto it = ladang.countPanen().begin(); it != ladang.countPanen().end(); it++){
        cout << i << "." << it->first << " ( " << it->second <<" petak siap panen)" << endl;
        i++;
        pilihan[i] = {it->first,it->second};
    }
    
    int a; // input pilihan
    cout<< "Nomor tanaman yang ingin dipanen:";  
    cin >> a;
    // validasi apakah terdapat inputan a

    if (a > i || a < 0){
        throw "Invalid input";
    }
    pair<string,int> pilihan_panen = pilihan[a];
    string code = pilihan_panen.first;
    int jumlah = pilihan_panen.second;
    
    int b;
    cout << "Berapa petak yang ingin dipanen: ";
    cin >> b;
    // validasi apakah b cukup
    if (b > jumlah || b < 0){
        throw "Invalid input";
    }

    vector<string> petak;
    petak = ladang.ambilPanen(code,b);
    cout << b << "petak tanaman "<< code << " pada petak ";
    for (int i = 0; i < petak.size(); i++){
        if (i == petak.size()-1){
            cout << petak[i] << " telah dipanen!";
        } else {
            cout << petak[i] << ", ";
        }
    }
}