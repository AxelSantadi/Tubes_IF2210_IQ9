#include "Peternak.hpp"

Peternak::Peternak(string nama,int n, char m,int panjang,char lebar) : Player(nama,n,m), kandang(panjang,lebar)
{}

Peternak::~Peternak(){}

void Peternak::addTernak(Animal animal, int i, char j)
{
    kandang.setValue(i, j, animal);
}

void Peternak::ternak(){
    // cetak inventory
    cout << "Pilih tanaman dari penyimpanan :" << endl;

    inventory.printInventory();
    cout << endl;
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
        if (!inventory.isExist(b,a) || !dynamic_cast<Animal*>(inventory.getValue(b,a)))
        {
            throw BukanHewanException();
        }
        Animal* animal = dynamic_cast<Animal*>(inventory.getValue(b,a));
        inventory.removeValue(b,a);

        cout << "Kamu memilih" << animal->getName() << endl;
        // pilih posisi tanam
        cout << "Pilih petak tanah yang akan ditanami ";
        kandang.cetakKandang();
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
                
                if(kandang.isExist(y,x))
                {
                    throw petakTerisiExeption();
                }

                addTernak(*animal,y,x);
                success = true;
            }
            catch(petakTerisiExeption e)
            {
                cerr << e.what() << endl;
            }
        }

        cout << "Dengan hati-hati, kamu meletakkan seekor "<< animal->getName() <<" di kandang." << endl;
        cout << animal->getName() << " telah menjadi peliharaanmu sekarang!" <<endl;
        cout << endl;

    }catch(BukanHewanException e){
        cerr << e.what() << endl;
    }
        
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
        file << " " << it.second.getName() << " " << it.second.getBerat() << endl;
    }
}

// void Peternak::feedTernak(){
//     cout << "Pilih petak kandang yang akan diberi makan" << endl;
//     kandang.cetakKandang();
//     string choice;
//     Animal *animal = nullptr;
//     Item *item = nullptr;
//     Product *produk = (Product *)item;
//     try
//     {
//         while (true)
//         {
//             cout << "Petak kandang: ";
//             cin >> choice;
//             char a;
//             int b;
//             a = choice[0];
//             choice = choice.substr(1, choice.length()-1);
//             b = stoi(choice);
//             try
//             {
//                 animal = kandang.getValue(b, a);
//             }
//             catch (out_of_range &e)
//             {
//                 cout << "Kamu memilih kandang kosong." << endl;
//                 cout << "Silahkan masukkan kandang yang berisi ternak." << endl;
//             }
//         }
//         Animal *hewan = dynamic_cast<Animal *>(animal);
//         cout << "Kamu memilih " << hewan->getName() << " untuk diberi makan." << endl;
//         cout << "Pilih pangan yang akan diberikan:" << endl;
//         inventory.printInventory();
//         while (true)
//         {
//             cout << "Slot: ";
//             cin >> choice;
//             char a;
//             int b;
//             a = choice[0];
//             choice = choice.substr(1, choice.length()-1);
//             b = stoi(choice);
//             try
//             {
//                 item = inventory.getValue(b, a);
//             }
//             catch (out_of_range &e)
//             {
//                 cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
//                 cout << "Silahkan masukkan slot yang berisi makanan." << endl;
//             }
//             if (item->isBuilding())
//             {
//                 cout << "Apa yang kamu lakukan?\?!! Kamu mencoba untuk memberi makan itu?!!" << endl;
//                 cout << "Silahkan masukkan slot yang berisi makanan." << endl;
//             }
//             if (!produk->isEdibleAnimal() && !produk->isEdiblePlant())
//             {
//                 cout << "Itu produk yang tidak bisa dimakan sobat." << endl;
//                 cout << "Silahkan masukkan slot yang berisi makanan." << endl;
//             }
//             else
//             {
//                 map<string, Animal *> ladang = barn.getAllItems();
//                 for (const auto &pair : ladang)
//                 {
//                     if (pair.first == choice)
//                     {
//                         cout << "Kamu memilih " << pair.second->getName() << RESET << endl;
//                     }
//                 }
//             }
//         }
//         animal->feed(produk);
//         inventory.DeleteItemAt(choice);
//         cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
//         cout << BOLD GREEN << "Alhasil, berat badan kamu naik menjadi " << this->weight << endl;
//     }
//     catch (wrongFoodException e)
//     {
//         cout << e.what() << '\n';
//     }
// }

void Peternak::panenTernak(vector<Product> product){
    kandang.cetakKandang();
    cout << endl;
    kandang.cetakJenisHewan();
    cout << endl;
    cout << "Pilih hewan siap panen yang kamu miliki" << endl;
    int i =1;
    map<int,pair<string,int>> pilihan;
    for (auto it = kandang.countPanen().begin(); it != kandang.countPanen().end(); it++)
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
        if (b > jumlah){
            throw jumlahPanenExeption();
        }
        if (inventory.countEmpty() < b){
            throw penyimpananPenuhExeption();
        }
        
        vector<string> petak;
        petak = kandang.ambilPanen(code,b);

        // Merubah tanaman yang dipanen menjadi product
        int idx;

        if(code == "COM"){
            idx = 0;
        } else if(code == "SHM"){
            idx = 1;
        } else if(code == "HRM"){
            idx = 2;
        } else if(code == "RBM"){
            idx = 3;
        } else if(code == "SNM"){
            idx = 4;
        } else if(code == "CHM"){
            idx = 5;
        } else if(code == "DCM"){
            idx = 6;
        } else if(code == "CHE"){
            idx = 7;
        } else if(code == "DCE"){
            idx = 8;
        }
        Item * p = new Product(product[idx]);

        for (int i = 0 ; i < petak.size(); i++ )
        {
            string koordinat;
            koordinat = petak[i];
            char a;
            int b;
            a = koordinat[0];
            koordinat = koordinat.substr(1, koordinat.length()-1);
            b = stoi(koordinat);
            int n = 0;
            while(n < b){
                for (int i = 1; i < inventory.getRows(); i++)
                {
                    for (char j = 'A'; j <= inventory.getCols(); j++)
                    {
                        if(n == b){
                            break;
                        }
                        if (!inventory.isExist(i,j))
                        {
                            addItem(p,i,j);
                            n++;
                            break;
                        }
                    }
                    if(n == b){
                        break;
                    }
                }
            }
            
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

int Peternak::getPajak(vector<Recipe> resep){
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

    for (int i = 0; i < kandang.getRows(); i++) {
        for (int j = 0; j < kandang.getCols(); j++) {
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