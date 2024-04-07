#include "Peternak.hpp"

Peternak::Peternak(string nama, int Berat_badan, int w_gulden, int panjang, int lebar) : Player(nama, Berat_badan, w_gulden),kandang(panjang, lebar){
    this->panjang = panjang;
    this->lebar = lebar;
    kandang = Kandang(panjang, lebar);
}   

Peternak::~Peternak(){}

void Peternak::ternak(const Peternak& p){
    cout << "Belum" << endl;
}

string Peternak::getRole() const
{
    return "Peternak";
}

void Peternak::saveStatePlayer(ofstream &file) const
{
    Player::saveStatePlayer(file);
    file << this->kandang.countNotEmpty() << endl;
    for (auto it : this->kandang.getData())
    {
        file << it.first.second;
        if (it.first.first >= 10)
        {
            file << it.first.first;
        }
        else
        {
            file << "0" << it.first.first;
        }
        file << " " << it.second.getName() << " " << "berat" << endl;
    }
}


int Peternak::getPajak(){
    int total = 0;

    for (int k = 0; k < resep.size(); k++) {
        for (int i = 0; i < inventory.getRows(); i++) {
            for (int j = 0; j < inventory.getCols(); j++) {
                if (inventory.getValue(i, j)->getCode() == resep.at(k).getCode()) {
                    total += resep.at(k).getPrice();
                }
            }
        }
    }

    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            if (kandang.isExist(i, j)) {
                total += kandang.getValue(i, j).getPrice();
            }
        }
    }

    total += money;

    if (total < 11) {
        total = 0;
    } else {
        total -= 11;
    }

    if (money <= total) {
        money = 0;
        return money;
    } else {
        money -= total;
        return total;
    }
}