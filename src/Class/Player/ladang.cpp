#include "ladang.hpp"

Landang::Landang(int panjang, int lebar) : ladang(panjang, lebar){
    ladang = MatrixMap<Plant>(panjang, lebar);
}

void Landang::cetakLadang(){
    cout << "================[ Ladang ]=================" << endl;
    ladang.print();
    cout << endl << endl;
}