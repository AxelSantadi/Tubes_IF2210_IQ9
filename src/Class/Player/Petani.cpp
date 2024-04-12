#include "Petani.hpp"

using namespace std;

Petani::Petani(string nama,int n , char m, int panjang , char lebar): Player(nama, n, m), ladang(panjang,lebar)
{}

Petani::Petani(string nama,int n , char m, int weight, int money, int panjang , char lebar): Player(nama, n, m, weight, money), ladang(panjang,lebar)
{}

Petani::~Petani(){

}

string Petani::getRole() const
{
    return "Petani";
}

void Petani::addTanaman(Plant plant, int i, char j) 
{
    ladang.setValue(i, j, plant);
}

Ladang Petani::getLadang()const{
    return ladang;
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

void Petani::tanam(){
    // cetak inventory
    cout << "Pilih tanaman dari penyimpanan :" << endl;

    inventory.printInventory();
    cout << endl;
    try
    {
        cout << "Slot : ";
        string slot;
        cin >> slot;
        cout << endl;
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
                }else if (y < 1 || y >= ladang.getRows() || x < 'A' || x >= ladang.getCols())
                {
                    throw salahPetakExeption();
                }
                inventory.removeValue(b,a);
                addTanaman(*plant, y, x);
                success = true;
            }
            catch(petakTerisiExeption e)
            {
                cerr << e.what() << endl;
            }
            catch(salahPetakExeption e)
            {
                cerr << e.what() << endl;
            }
        }

        cout << "Cangkul, cangkul, cangkul, yang dalam ~!" << endl;
        cout << plant->getName() << " berhasil ditanam " <<endl;
        cout << endl;

    }catch(BukanTanamanExeption e){
        cerr << e.what() << endl;
    }
        
}

void Petani::panen(vector<Product> product)
{
    // print ladang
    ladang.cetakLadangPanen();
    cout << endl;
    // print isi ladang
    ladang.cetakJenisTanaman();
    cout << endl;
    // pilih panen
    cout << "Pilih tanaman siap panen yang kamu miliki " << endl;
    int i = 1 ; // indeks pilihan
    map<int,pair<string,int>> pilihan;
    unordered_map<string,int> hasilCount = ladang.countPanen();
    for (const std::pair<std::string, int>& entry : hasilCount) {
        cout << i << "." << entry.first << " ( " << entry.second <<" petak siap panen)" << endl;
        pilihan[i] = {entry.first,entry.second};
        i++;
    } 
    cout<<endl;

    try{
        int a; // input pilihan
        cout<< "Nomor tanaman yang ingin dipanen: ";  
        cin >> a;
        // validasi apakah terdapat inputan a

        if (a >= i || a < 0){
            throw salahPanenExeption();
        }

        // menyimpan kode tanaman dan jumlah tanaman yang siap panen
        pair<string,int> pilihan_panen = pilihan[a];
        string code = pilihan_panen.first;
        int jumlah = pilihan_panen.second;
        
        // input jumlah tanaman yang ingin dipanen
        int b;
        cout << "Berapa petak yang ingin dipanen  : ";
        cin >> b;

        // validasi apakah b cukup
        if (b > jumlah){
            throw jumlahPanenExeption();
        }
        if (inventory.countEmpty() < b){
            throw penyimpananPenuhExeption();
        }
        
        vector<string> petak;
        petak = ladang.ambilPanenTumbuhan(code,b);

        // Merubah tanaman yang dipanen menjadi product
        int idx;
        if(code == "TEK"){
            idx = 0;
        }else if(code == "SDT"){
            idx = 1;
        }else if(code == "ALT"){
            idx = 2;
        }else if(code == "IRN"){
            idx = 3;
        }else if(code == "APL"){
            idx = 4;
        }else if(code == "ORG"){
            idx = 5;
        }else if(code == "BNT"){
            idx = 6;
        }else if(code == "GAV"){
            idx = 7;
        }
        
        Item * p = new Product(product[idx]);
        

        // menyimpan hasil panen ke inventory
        int n = b;
        while (n > 0)
        {
            cout << n << endl;
            inventory.setRandomValue(p);
            n--;
        } 

        
        cout << b << " petak tanaman "<< code << " pada petak ";
        for (int i = 0; i < petak.size(); i++)
        {
            if (i == petak.size()-1){
                cout << petak[i] << " telah dipanen!";
            } else {
                cout << petak[i] << ", ";
            }
        }
        cout << endl;
    }catch(salahPanenExeption e){
        cerr << e.what() << endl;
    }catch(jumlahPanenExeption e){
        cerr << e.what() << endl;
    }catch(penyimpananPenuhExeption e){
        cerr << e.what() << endl;
    }  
}

void Petani::nextDay()
{
    ladang.nextUmur();
}

int Petani::getPajak(vector<Recipe> resep) {
    int total = 0;

    for (int i = 1; i <= inventory.getRows(); i++) {
        for (char j = 'A'; j <= inventory.getCols(); j++) {
            if (!inventory.isExist(i,j)) {
                continue;
            } else {
                total += inventory.getValue(i, j)->getPrice();
            }
        }
    }


    for (int i = 0; i < ladang.getRows(); i++) {
        for (int j = 0; j < ladang.getCols(); j++) {
            if (!ladang.isExist(i, j)) {
                continue;
            } else {
                total += ladang.getValue(i, j).getPrice();
            }
        }
    }

    total += this->money;

    if (total < 13) {
        total = 0;
    } else {
        total -= 13;
    }

    if (total <= 6) {
        total = total * 5 / 100;
    } else if (total > 6 && total <= 25) {
        total = total * 15 / 100;
    } else if (total > 25 && total <= 50) {
        total = total * 25 / 100;
    } else if (total > 50 && total <= 500){
        total = total * 30 / 100;
    } else {
        total = total * 35 / 100;
    }

    if (money <= total) {
        money = 0;
        return money;
    } else {
        money -= total;
        return total;
    }
}