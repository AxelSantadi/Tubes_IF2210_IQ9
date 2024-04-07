#include "Petani.hpp"

using namespace std;

Petani::Petani(string nama,int n , int m, int panjang , int lebar): Player(nama, n, m), ladang(panjang,lebar)
{}

Petani::~Petani(){

}

string Petani::getRole() const
{
    return "Petani";
}

void Petani::saveStatePlayer(ofstream &file) const
{
    Player::saveStatePlayer(file);
    file << this->ladang.countNotEmpty() << endl;
    for (auto it : this->ladang.getData())
    {
        file << it.first.second;
        if (it.first.first >= 10 )
        {
            file << it.first.first;
        } 
        else 
        {
            file << "0" << it.first.first;
        } 
        file << " " << it.second.getName() << " " << it.second.getUmur() << endl;
    }
}

void Petani::tanam(vector<Product> product){
    // cetak inventory
    cout << "Pilih tanaman dari penyimpanan :" << endl;

    inventory.printInventory();
    try
    {
        cout << "Slot :" << endl;
        string slot;
        cin >> slot;
        char a;
        int b;
        a = slot[0];
        slot = slot.substr(1, slot.length()-1);
        b = stoi(slot);
        if (!inventory.isExist(b,a) || !dynamic_cast<Plant*>(inventory.getValue(b,a)))
        {
            throw BukanTanamanExeption();
        }
        Plant* plant = dynamic_cast<Plant*>(inventory.getValue(b,a));
        inventory.removeValue(b,a);

        cout << "Kamu memilih" << plant->getName() << endl;
        // pilih posisi tanam
        cout << "Pilih petak tanah yang akan ditanami ";
        ladang.cetakLadang();
        // cetak ladang
        bool success = false; 
        while(!success)
        {
            try
            {
                // pilih posisi tanam
                string posisi;
                cout << "Petak tanah : ";
                cin >> posisi;
                cout << endl;
                char x;
                int y;
                x = posisi[0];
                posisi = posisi.substr(1, posisi.length()-1);
                y = stoi(posisi);
                
                if(ladang.isExist(y,x))
                {
                    throw petakTerisiExeption();
                }

                ladang.setValue(y,x,*plant);
                success = true;
            }
            catch(petakTerisiExeption e)
            {
                cerr << e.what() << endl;
            }
        }

        cout << "Cangkul, cangkul, cangkul, yang dalam ~!" << endl;
        cout << plant->getName() << " berhasil ditanam " <<endl;

    }catch(BukanTanamanExeption e){
        cerr << e.what() << endl;
    }
        
}

void Petani::panen(vector<Product> product)
{
    // print ladang
    ladang.cetakLadang();
    cout << endl;
    // print isi ladang
    ladang.cetakJenisTanaman();
    cout << endl;
    // pilih panen
    cout << "Pilih tanaman siap panen yang kamu miliki " << endl;
    int i = 1 ; // indeks pilihan
    map<int,pair<string,int>> pilihan;
    for (auto it = ladang.countPanen().begin(); it != ladang.countPanen().end(); it++)
    {
        cout << i << "." << it->first << " ( " << it->second <<" petak siap panen)" << endl;
        i++;
        pilihan[i] = {it->first,it->second};
    }
    try{
        int a; // input pilihan
        cout<< "Nomor tanaman yang ingin dipanen:";  
        cin >> a;
        // validasi apakah terdapat inputan a

        if (a > i || a < 0){
            throw salahPanenExeption();
        }

        // menyimpan kode tanaman dan jumlah tanaman yang siap panen
        pair<string,int> pilihan_panen = pilihan[a];
        string code = pilihan_panen.first;
        int jumlah = pilihan_panen.second;
        
        // input jumlah tanaman yang ingin dipanen
        int b;
        cout << "Berapa petak yang ingin dipanen: ";
        cin >> b;
        // validasi apakah b cukup
        if (b > jumlah || b < 0){
            throw jumlahPanenExeption();
        }
        if (inventory.countEmpty() < b){
            throw penyimpananPenuhExeption();
        }
        
        vector<string> petak;
        petak = ladang.ambilPanen(code,b);

        // Merubah tanaman yang dipanen menjadi product
        int idx;
        if(code == "TAW"){
            idx = 0;
        }else if(code == "SAW"){
            idx = 1;
        }else if(code == "ALW"){
            idx = 2;
        }else if(code == "IRW"){
            idx = 3;
        }else if(code == "APP"){
            idx = 4;
        }else if(code == "ORP"){
            idx = 5;
        }else if(code == "BNP"){
            idx = 6;
        }else if(code == "GAP"){
            idx = 7;
        }
        Product p = product[idx];

        for (int i = 0 ; i < petak.size(); i++ )
        {
            string koordinat;
            koordinat = petak[i];
            char a;
            int b;
            a = koordinat[0];
            koordinat = koordinat.substr(1, koordinat.length()-1);
            b = stoi(koordinat);


            for (int i = 0; i < inventory.getRows(); i++)
            {
                for (char j = 'A'; j <= inventory.getCols(); j++)
                {
                    if (!inventory.isExist(i,j))
                    {
                        inventory.setValue(i,j,&p);
                        break;
                    }
                }
            }
        }
        
        cout << b << "petak tanaman "<< code << " pada petak ";
        for (int i = 0; i < petak.size(); i++)
        {
            if (i == petak.size()-1){
                cout << petak[i] << " telah dipanen!";
            } else {
                cout << petak[i] << ", ";
            }
        }
    }catch(salahPanenExeption e){
        cerr << e.what() << endl;
    }catch(jumlahPanenExeption e){
        cerr << e.what() << endl;
    }catch(penyimpananPenuhExeption e){
        cerr << e.what() << endl;
    }  
}

// int Petani::getPajak()
// {
//     int total = 0;

//     for (int k = 0; k < resep.size(); k++) {
//         for (int i = 0; i < inventory.getRows(); i++) {
//             for (int j = 0; j < inventory.getCols(); j++) {
//                 if (inventory.getValue(i, j)->getCode() == resep.at(k).getCode()) {
//                     total += resep.at(k).getPrice();
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < ladang.getRows(); i++) {
//         for (int j = 0; j < ladang.getCols(); j++) {
//             if (ladang.isExist(i, j)) {
//                 total += ladang.getValue(i, j).getPrice();
//             }
//         }
//     }

//     total += money;

//     if (total < 13) {
//         total = 0;
//     } else {
//         total -= 13;
//     }

//     if (money <= total) {
//         money = 0;
//         return money;
//     } else {
//         money -= total;
//         return total;
//     }
// }