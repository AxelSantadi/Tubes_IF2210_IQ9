#include "Petani.hpp"

Petani::Petani(string nama, int Berat_badan, int w_gulden, int panjang , int lebar): Player(nama, Berat_badan, w_gulden) , ladang(panjang,lebar)
{
    ladang = Landang(panjang, lebar);
}

void Petani::tanam(Plant plant){
    // cetak inventory
    // pilih barang dari inventory

    cout << "Kamu memilih" << plant.getName() << endl;
    // pilih posisi tanam
    cout << "Pilih petak tanah yang akan ditanami ";

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

    
}



