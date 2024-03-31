#include "Petani.hpp"

Petani::Petani(string nama, int Berat_badan, int w_gulden, int panjang , int lebar): Player(nama, Berat_badan, w_gulden) , ladang(panjang,lebar)
{
    ladang = Landang(panjang, lebar);
}

void Petani::tanam(const Petani& p){
    // cetak inventory
    cout << "Pilih tanaman dari penyimpanan :" << endl;

    inventory.printInventory();
    cout << "Slot :" << endl;
    string slot;
    cin >> slot;
    int a;
    int b;
    a = stoi(slot.substr(0, 1));
    a = a - 65;
    slot = slot.substr(1, slot.length()-1);
    b = stoi(slot);
    Product plant = inventory.getValue(a, b);
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


    // pilih panen
    cout << "Pilih tanaman siap panen yang kamu miliki " << endl;
    

    
}



