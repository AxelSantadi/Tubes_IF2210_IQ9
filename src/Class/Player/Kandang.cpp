#include "Kandang.hpp"

Kandang::Kandang(int panjang, int lebar) : kandang(panjang, lebar){
    kandang = MatrixMap<Animal>(panjang, lebar);
}

void Kandang::cetakKandang(){
    cout << "================[ Kandang ]=================" << endl;
    kandang.print();
    cout << endl << endl;
}