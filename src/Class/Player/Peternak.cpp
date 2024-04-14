#include "Peternak.hpp"

Peternak::Peternak(string nama,int n, char m,int panjang,char lebar) : Player(nama,n,m), kandang(panjang,lebar)
{}

Peternak::Peternak(string nama,int n, char m,int weight,int money,int panjang,char lebar) : Player(nama,n,m,weight,money), kandang(panjang,lebar)
{}

Peternak::~Peternak(){}

string Peternak::getRole() const
{
    return "Peternak";
}

void Peternak::addTernak(Animal animal, int i, char j)
{
    kandang.setValue(i, j, animal);
}

Kandang Peternak::getKandang() const
{
    return kandang;
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

void Peternak::ternak(){
    // cetak inventory
    std::cout << "Pilih hewan dari penyimpanan :" << endl;

    inventory.printInventory();
    std::cout << endl;
    try
    {
        std::cout << "Slot :";
        string slot;
        std::cin >> slot;
        char a;
        int b;
        a = slot[0];
        slot = slot.substr(1, slot.length()-1);
        b = stoi(slot);
        if (inventory.getValue(b,a)->getJenis() != "Animal"){
            throw BukanHewanException();
        } else if (!inventory.isExist(b,a)){
            throw SlotKosongException();
        } else if (inventory.getRows() < b || inventory.getCols() < a){
            throw outOfBoundException();
        }
        Animal* animal = dynamic_cast<Animal*>(inventory.getValue(b,a));
        

        std::cout << "Kamu memilih " << animal->getName() << endl;
        // pilih posisi tanam
        std::cout << "Pilih petak tanah yang akan ditinggali";
        kandang.cetakKandangPanen();
        // cetak kandang
        bool success = false; 
        while(!success)
        {
            try
            {
                // pilih posisi hewan
                string posisi;
                std::cout << "Petak tanah : ";
                std::cin >> posisi;
                std::cout << endl;
                char x;
                int y;
                x = posisi[0];
                posisi = posisi.substr(1, posisi.length()-1);
                y = stoi(posisi);
                
                if(kandang.isExist(y,x))
                {
                    throw petakTerisiExeption();
                } else if (y < 1 || y >= kandang.getRows() || x < 'A' || x >= kandang.getCols()){
                    throw outOfBoundException();
                }

                inventory.removeValue(b,a);
                addTernak(*animal,y,x);
                success = true;
            }
            catch(petakTerisiExeption &e)
            {
                std::cerr << e.what() << endl;
            }
            catch(outOfBoundException &e)
            {
                std::cerr << e.what() << endl;
            }
        }

        std::cout << "Dengan hati-hati, kamu meletakkan seekor "<< animal->getName() <<" di kandang." << endl;
        std::cout << animal->getName() << " telah menjadi peliharaanmu sekarang!" <<endl;
        std::cout << endl;

    }catch(BukanHewanException &e){
        std::cerr << e.what() << endl;
    }catch(SlotKosongException &e){
        std::cerr << e.what() << endl;
    }catch(outOfBoundException &e){
        std::cerr << e.what() << endl;
    }
        
}

void Peternak::feedTernak(){
    if (kandang.isEmpty())
    {
        std::cout << "Kandangmu kosong, tidak ada hewan yang bisa diberi makan." << endl;
        return;
    }
    else{
    std::cout << "Pilih petak kandang yang akan dikasih makan" << endl;
    kandang.cetakKandangPanen();
    std::cout << endl;
    kandang.cetakJenisHewan();
    std::cout << endl;
    bool success = false;
    try {
        std::cout << "Petak kandang: ";
        string posisi;
        std::cin >> posisi;
        std::cout << endl;
        char x;
        int y;
        x = posisi[0];
        posisi = posisi.substr(1, posisi.length()-1);
        y = stoi(posisi);
        if (!kandang.isExist(y,x))
        {
            throw SlotKosongException();
        }

        Animal* animal = new Animal(kandang.getValue(y,x));
        std::cout << "Kamu memilih " << animal->getName() << " untuk diberi makan." << endl;
        if (animal->isHerbivore() && inventory.noFoodHerbivore())
        {
            std::cout << "Tidak ada makanan hewan ini di penyimpanan." << endl;

        } else if (animal->isCarnivore() && inventory.noFoodCarnivore())
        {
            std::cout << "Tidak ada makanan hewan ini di penyimpanan." << endl;
        } else 
        {
        std::cout << "Pilih pangan yang akan diberikan:" << endl;
        inventory.printInventory();
        while (!success)
        {
            try{
            std::cout << "Slot: ";
            string slot;
            std::cin >> slot;
            std::cout << endl;
            char a;
            int b;
            a = slot[0];
            slot = slot.substr(1, slot.length()-1);
            b = stoi(slot);
            if (inventory.isExist(b, a))
                {
                    Item* item = inventory.getValue(b,a);
                    if (item->isMakanan())
                    {
                        if (animal->isHerbivore()){
                            if (item->getCode() == "COM" ||
                                item->getCode() == "SHM" || 
                                item->getCode() == "HRM" || 
                                item->getCode() == "RBM" || 
                                item->getCode() == "SNM" || 
                                item->getCode() == "CHM" || 
                                item->getCode() == "DCM" || 
                                item->getCode() == "CHE" || 
                                item->getCode() == "DCE")
                            {
                                throw BukanMakananHerbivore();
                            } else  {
                                std::cout << "Kamu memilih " << item->getName() << endl;
                                //menambahkan berat badan hewan yang dipilih menggunakan item;
                                std::cout << "Berat badan " << animal->getName() << " sebelumnya adalah " << animal->getBerat() << endl;
                                animal->setBerat(animal->getBerat() + item->getAddedWeight());
                                
                                std::cout << "Dengan lahapnya, " << animal->getName() << " memakan hidangan itu" << endl;
                                std::cout << "Alhasil, berat badan " << animal->getName() << " naik menjadi " << animal->getBerat() << endl;
                                addTernak(*animal,y,x);
                                inventory.removeValue(b,a);
                                
                                success = true;
                            }
                        } else if (animal->isCarnivore()){
                            if (item->getCode() == "TAW" ||
                                item->getCode() == "SAW" ||
                                item->getCode() == "ALW" ||
                                item->getCode() == "IRW" ||
                                item->getCode() == "APP" ||
                                item->getCode() == "ORP" ||
                                item->getCode() == "BNP" ||
                                item->getCode() == "GAP")
                            {
                                throw BukanMakananCarnivore();
                            } else {
                                std::cout << "Kamu memilih " << item->getName() << endl;
                                //menambahkan berat badan hewan yang dipilih menggunakan item;
                                animal->setBerat(animal->getBerat() + item->getAddedWeight());
                                kandang.setValue(y,x,*animal);
                                inventory.removeValue(b,a);
                                std::cout << "Dengan lahapnya, " << animal->getName() << " memakan hidangan itu" << endl;
                                std::cout << "Alhasil, berat badan " << animal->getName() << " naik menjadi " << animal->getBerat() << endl;
                                success = true;
                            }
                        } else if (animal->isOmnivore()){
                            std::cout << "Kamu memilih " << item->getName() << endl;
                            //menambahkan berat badan hewan yang dipilih menggunakan item;
                            animal->setBerat(animal->getBerat() + item->getAddedWeight());
                            kandang.setValue(y,x,*animal);
                            inventory.removeValue(b,a);
                            std::cout << "Dengan lahapnya, " << animal->getName() << " memakan hidangan itu" << endl;
                            std::cout << "Alhasil, berat badan " << animal->getName() << " naik menjadi " << animal->getBerat() << endl;
                            success = true;
                        }
                        
                    } else
                    {
                        throw BukanMakananHewanException();
                    }
                }
                else if (inventory.getRows() < b || 1 < b || inventory.getCols() < a || 'A' < a)
                {
                    throw outOfBoundException();
                }
                else
                {
                    throw SlotKosongException();
                }
            
            }catch(outOfBoundException &e){
                std::cerr << e.what() << endl;
            }catch(SlotKosongException &e){
                std::cerr << e.what() << endl;
            }catch(BukanMakananHewanException &e){
                std::cerr << e.what() << endl;
            }catch(BukanMakananHerbivore &e){
                std::cerr << e.what() << endl;
            }catch(BukanMakananCarnivore &e){
                std::cerr << e.what() << endl;
            }
        }
        }

    } catch(SlotKosongException &e){
        std::cerr << e.what() << endl;
    }

    }
}


void Peternak::panen(vector<Product> product){
    kandang.cetakKandangPanen();
    std::cout << endl;
    kandang.cetakJenisHewan();
    std::cout << endl;

    std::cout << "Pilih hewan siap panen yang kamu miliki" << endl;
    int i = 1;
    map<int,pair<string,int>> pilihan;
    unordered_map<string,int> hasilCount = kandang.countPanen();
    for (const std::pair<const std::string, int>& entry : hasilCount) {
        std::cout << i << "." << entry.first << " ( " << entry.second <<" petak siap panen)" << endl;
        pilihan[i] = {entry.first,entry.second};
        i++;
    } 
    std::cout<<endl;

    try{
        int a; // input pilihan
        std::cout<< "Nomor hewan yang ingin dipanen: ";  
        std::cin >> a;
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
        std::cout << "Berapa petak yang ingin dipanen: ";
        std::cin >> b;

        // validasi apakah b cukup
        if (b > jumlah){
            throw jumlahPanenExeption();
        }
        if (inventory.countEmpty() < b){
            throw penyimpananPenuhExeption();
        }
        
        int idx;
        if(code == "COW"){
            idx = 8;
        } else if(code == "SHP"){
            idx = 9;
        } else if(code == "HRS"){
            idx = 10;
        } else if(code == "RBT"){
            idx = 11;
        } else if(code == "SNK"){
            idx = 12;
        } else if(code == "CHK"){
            idx = 13;
            if (inventory.countEmpty() < b*2){
                throw penyimpananPenuhExeption();
            }
        } else if(code == "DCK"){
            idx = 14;
            if (inventory.countEmpty() < b*2){
                throw penyimpananPenuhExeption();
            }
        }
        vector<string> petak;
        petak = kandang.ambilPanenhewan(code,b);
        
        if (idx == 13){
            Item * p = new Product(product[idx]);
            Item * p2 = new Product(product[idx+2]);
            int n = b;
            while (n > 0)
            {
                inventory.setRandomValue(p);
                inventory.setRandomValue(p2);
                n--;
            } 
        } 
        else if (idx == 14){
            Item * p = new Product(product[idx]);
            Item * p2 = new Product(product[idx+2]);
            int n = b;
            while (n > 0)
            {
                inventory.setRandomValue(p);
                inventory.setRandomValue(p2);
                n--;
            } 
        }else {
            Item * p = new Product(product[idx]);
            int n = b;
            while (n > 0)
            {
                inventory.setRandomValue(p);
                n--;
            } 
        }

        
        // menyimpan hasil panen ke inventory
       

        
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
    }  
}   

int Peternak::getPajak(vector<Recipe> resep){
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

    for (int i = 0; i < kandang.getRows(); i++) {
        for (int j = 0; j < kandang.getCols(); j++) {
            if (!kandang.isExist(i, j)) {
                continue;
            } else {
                total += kandang.getValue(i, j).getPrice();
            }
        }
    }

    total += this->money;

    if (total < 11) {
        total = 0;
    } else {
        total -= 11;
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