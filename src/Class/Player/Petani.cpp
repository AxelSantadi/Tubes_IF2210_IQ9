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
    std::cout << "Pilih tanaman dari penyimpanan :" << endl;

    inventory.printInventory();
    std::cout << endl;
    try
    {
        std::cout << "Slot : ";
        string slot;
        std::cin >> slot;
        std::cout << endl;
        char a;
        int b;
        a = slot[0];
        slot = slot.substr(1, slot.length()-1);
        b = stoi(slot);
        if (!inventory.isExist(b,a))
        {
            throw SlotKosongException();    
        }
        else if (inventory.getValue(b,a)->getJenis() != "Plant")
        {
            throw BukanTanamanExeption();
        }
        Plant* plant = dynamic_cast<Plant*>(inventory.getValue(b,a));
        std::cout << "Kamu memilih " << plant->getName() << endl;
        // pilih posisi tanam
        std::cout << "Pilih petak tanah yang akan ditanami ";
        ladang.cetakLadangPanen();
        // cetak ladang
        bool success = false; 
        while(!success)
        {
            try
            {
                // pilih posisi tanam
                string posisi;
                std::cout << "Petak tanah : ";
                std::cin >> posisi;
                std::cout << endl;
                char x;
                int y;
                x = posisi[0];
                posisi = posisi.substr(1, posisi.length()-1);
                y = stoi(posisi);
                
                if(ladang.isExist(y,x))
                {
                    throw petakTerisiExeption();
                }else if (y < 1 || y > ladang.getRows() || x < 'A' || x > ladang.getCols())
                {
                    throw salahPetakExeption();
                }
                inventory.removeValue(b,a);
                addTanaman(*plant, y, x);
                success = true;
            }
            catch(petakTerisiExeption &e)
            {
                std::cerr << e.what() << endl;
            }
            catch(salahPetakExeption &e)
            {
                std::cerr << e.what() << endl;
            }
        }

        std::cout << "Cangkul, cangkul, cangkul, yang dalam ~!" << endl;
        std::cout << plant->getName() << " berhasil ditanam " <<endl;
        std::cout << endl;

    }catch(BukanTanamanExeption &e){
        std::cerr << e.what() << endl;
    }catch(SlotKosongException &e){
        std::cerr << e.what() << endl;
    }
        
}

void Petani::panen(vector<Product> product)
{
    // print ladang
    ladang.cetakLadangPanen();
    std::cout << endl;
    // print isi ladang
    ladang.cetakJenisTanaman();
    std::cout << endl;
    // pilih panen
    std::cout << "Pilih tanaman siap panen yang kamu miliki " << endl;
    int i = 1 ; // indeks pilihan
    map<int,pair<string,int>> pilihan;
    unordered_map<string,int> hasilCount = ladang.countPanen();
    for (const std::pair<const std::string, int>& entry : hasilCount) {
        cout << i << "." << entry.first << " ( " << entry.second <<" petak siap panen)" << endl;
        pilihan[i] = {entry.first,entry.second};
        i++;
    } 
    std::cout<<endl;

    try{
        if (i == 1){
            throw belumPanenExeption();
        }
        string a; // input pilihan
        std::cout<< "Nomor tanaman yang ingin dipanen: ";  
        std::cin >> a;

        int pil = stoi(a);

        // validasi apakah terdapat inputan a

        if (pil >= i || pil < 0){
            throw salahPanenExeption();
        }

        // menyimpan kode tanaman dan jumlah tanaman yang siap panen
        pair<string,int> pilihan_panen = pilihan[pil];
        string code = pilihan_panen.first;
        int jumlah = pilihan_panen.second;
        
        // input jumlah tanaman yang ingin dipanen
        string b;
        std::cout << "Berapa petak yang ingin dipanen  : ";
        std::cin >> b;

        int bi = stoi(b);

        // validasi apakah b cukup
        if (bi > jumlah){
            throw jumlahPanenExeption();
        }
        if (inventory.countEmpty() < bi){
            throw penyimpananPenuhExeption();
        }
        
        vector<string> petak;
        petak = ladang.ambilPanenTumbuhan(code,bi);

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
        int n = bi;
        while (n > 0)
        {
            inventory + p;
            n--;
        } 

        
        std::cout << b << " petak tanaman "<< code << " pada petak ";
        for (int i = 0; i < static_cast<int>(petak.size()); i++)
        {
            if (i == static_cast<int>(petak.size()-1)){
                std::cout << petak[i] << " telah dipanen!";
            } else {
                std::cout << petak[i] << ", ";
            }
        }
        std::cout << endl;
    }catch(salahPanenExeption &e){
        std::cerr << e.what() << endl;
    }catch(jumlahPanenExeption &e){
        std::cerr << e.what() << endl;
    }catch(penyimpananPenuhExeption &e){
        std::cerr << e.what() << endl;
    }catch(belumPanenExeption &e){
        std::cerr << e.what() << endl;
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