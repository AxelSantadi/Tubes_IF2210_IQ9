#include "Perintah.hpp"

Perintah::Perintah()
{
    // Deklarasi
    string folderName, pilihan, perintah;
    bool valid = false;
    endGame = false;

    // Inisialisasi
    initilization();

    // Alur 1
    readConfig();

    // Alur 2
    muatState();
    toko = new Toko(config);

    // Alur 3
    cout << "Urutan giliran permainan berdasarkan urutan leksikografis dari username pemain." << endl;
    cout << "Selamat bermain!" << endl
         << endl;

    // Alur 4
    cout << "Sekarang adalah giliran " << Player::getCurrentPlayer()->getName() << endl;
    while (!endGame)
    {
        cout << "Masukkan perintah: ";
        cin >> perintah;
        if (perintah == "NEXT")
        {
            NEXT();
        }
        else if (perintah == "CETAK_PENYIMPANAN")
        {
            CETAK_PENYIMPANAN();
        }
        else if (perintah == "PUNGUT_PAJAK")
        {
            PUNGUT_PAJAK();
        }
        else if (perintah == "CETAK_LADANG")
        {
            CETAK_LADANG();
        }
        else if (perintah == "CETAK_PETERNAKAN")
        {
            CETAK_PETERNAKAN();
        }
        else if (perintah == "TANAM")
        {
            TANAM();
        }
        else if (perintah == "TERNAK")
        {
            TERNAK();
        }
        else if (perintah == "BANGUN")
        {
            BANGUN();
        }
        else if (perintah == "MAKAN")
        {
            MAKAN();
        }
        else if (perintah == "KASIH_MAKAN")
        {
            KASIH_MAKAN();
        }
        else if (perintah == "BELI")
        {
            BELI();
        }
        else if (perintah == "JUAL")
        {
            JUAL();
        }
        else if (perintah == "PANEN")
        {
            PANEN();
        }
        else if (perintah == "SIMPAN")
        {
            SIMPAN();
        }
        else if (perintah == "TAMBAH_PEMAIN")
        {
            TAMBAH_PEMAIN();
        }
        else if (perintah == "EXIT")
        {
            endGame = true;
        }
        else
        {
            cout << "Perintah Tidak Valid Masukan lagi yang benar." << endl;
        }
    }
}

Perintah::~Perintah()
{
    delete toko; // Delete toko to avoid memory leaks
}

void Perintah::initilization()
{
    cout << "           ......... =%::+%-..                    .....   ........   ............                  ....                           " << endl;
    cout << "          .::::::... =@. =@*    ...........................................-..........................................            " << endl;
    cout << "           #= .-%#:--+@. -@* ...............:---=---------=====++====----:***:::......:*+:.. ..:-=+=:.................            " << endl;
    cout << "           ++..-%%++++@: :@#....-%.:=%+:----@-      . ..=#*-::=*#%==+++++#+.:#=======@=..... .......  .**-=++***:....             " << endl;
    cout << "           =#..:%%====@: :@#...:#.....#*---=@:..#%%%#:.....+-:...:%=----+*...-%-----%#.................%*::-==*%=............     " << endl;
    cout << "           -%..:%%*===@:..%%###@-.=....#*-=+@..:%@%%%:.....#+......#=--+#....+%#---=%#.... =##**+=:.  =@=---==+%+-==+++=*....     " << endl;
    cout << "           :%:.:%%+--=@-..#%#*%+.%@:....%*-*%. =@%%=.....-#%@+......#++#....*%*+=--:.+#.....=%%%%##%%#%%**+=--:..    .:=**...     " << endl;
    cout << "          ..%-..%#**+==...*%###..........#*#+  *#:.....:%#@@%%=......+%:...#%%.....::+%@*:.....=#%@@=............:*#%%%%@@:..     " << endl;
    cout << "      ......#+............*%#%..%%%@*....:%%-..........*@@#*#%%-.........:@%@@::%%%%%%@@##%%=..... =@%%%@@@@@-.. .#@@%*:.....     " << endl;
    cout << "      ......+*............+%%:.#%@%@%=.....%:....-........*%**%%-.......:%%%%@+.....:%*+%@%###%%*:...-%@@@@%#+ ...=%*:.......     " << endl;
    cout << "   .......==*#............+%+.*%@#**#%-..=#%..+%%%%%*.......:+%%%-.....+%@#+*%#......*@#:#%##@@%#%%...-%***%#%.....###%+.....     " << endl;
    cout << "   .....-+==+%:..:::::::..=%:+%@%####%%#%%@#::#@@#%%%%%+:......:+%:...#%@#*##%%::==+*##%#-.:=+***+:...=%*##%%%:....:%###%:...     " << endl;
    cout << "   ....======@:..-%%%#%%. -%%%%%*****#%###%%#%%@****##%%%%=....:#%%:.#%%*##**%%-:%%%#%@%%#%#=:......-*%%*#*#%%= ....*%###%+..     " << endl;
    cout << "   ..-+===---%-..:%@%%%@:.:%%%%##*****##**#%%#%%*##****##%%%%=+%%@%%#@%******#@* ...:##*#@@##%%%%%%%%@%*****%#* ....:%+====*...   " << endl;
    cout << "    :+=======%+..:%@##*@-.:%%##**#**#=-=*******#=*#*****+*#%@%%@%*%%@%*******#%%@@%#%%%*****%%%#%%@@#****#*=### .:-+*##=+++++..   " << endl;
    cout << "   .-=====+==#%+++%@#**%*++#%+#..%#*+==-+*+++*%-.+%***+***###*#%#++%*+++*%*:....:*@@%%*.-#************###%#++%#%%%%@@@%+-==+*:.   " << endl;
    cout << "   -=--------+%%%%%@####%@@@@@-...#*-==--=**##...-@*+--#+..--....+#***#%: -*##+....+#%#....-##*******#%@:.-#=%%########*====++:   " << endl;
    cout << "   +++========+##******+*###%=.....%*===---*+.....%#*%*.:%%%#%%...:#+%+..*%@%%%@=...+%%.......-*#*****%@=.:%===--+***###+=++**:   " << endl;
    cout << "   :+==========*#**####*-**##.......%*++=+%-..... *#%=..+%@#%%%*...*@*...%%***%@*...-@%.  .......-*#**%%+..%#=--==#***###+++#=    " << endl;
    cout << "    -++=--=--==-+*******==*%..==....:@+=+#..= ....=@#...:%*++*%....+@:...:##++%#....-@@-............:*#%#..##*=:+####****+-+%:.   " << endl;
    cout << "   .:%+==---====-+#*****--#-.:%%-....-%#+..%%.....:%+......::......##.   ...........*%%= -%#:...........+:.+%*+----++++++++%*..   " << endl;
    cout << "   ...*+==----==-=--====-**..%%%#.....==.=%%@-.....##.............*%%-.............+%%%*.:%@%%#=...........=%**==-=--====*@-...   " << endl;
    cout << "   ....-#+==========++++*#..*%%*%%......*%%##* ....*@+..........:#%@%%............*%%*%#..##%@@%%#=........:%*#++++++++*##...     " << endl;
    cout << "   .....:##+++===+++====%@%#%@#**%+....#%%#**%.... =%%%-.....:=#%@%*%%@*:......-#%@%*#%%..*#***%@@%%%+:.....###+=+===+*%=....     " << endl;
    cout << "      ....:##+==--=======#%%@%####%=.-%%%***+@=....:%%%#%%%%%%%@%++**#@##%%%%%%%@%#***%%-:+%******%%%%%%**#%%#*+=++*#@=......     " << endl;
    cout << "      .......-%#*+++=----=********#%*%%%*****#%#%%%%##+*%@%%%#*+**++++++%%%%%%#*+*****%%#%%%*#####***#@%@@@@%###=*%#........      " << endl;
    cout << "          ......*@#+===---=********#%%#****###@@@@@@%#++++++++++++++++++++++************######*==+***********##@%-.......         " << endl;
    cout << "             .....*%%%#*+===******=-%***********************++++++++***-=*********************+==+++*######%@%%- .....            " << endl;
    cout << "             .... *%####%@%#***###+++######*#+-********+*-+*++++++++*+-===*###########*+*#*****====++*#%@%###%%:......            " << endl;
    cout << "             .....+##*******=#%%%#*+++#*****====*********+===******+===+=====+******+====+**###*#%%#*-***+**##%:.....             " << endl;
    cout << "             .....+#*+++*##*......-*%@%%%##+===--+*****#*=----------------------===++****#%%@%+:......***+**#%%:...               " << endl;
    cout << "              ... +#***+*##+..............:=+#%@@@%%##########****+****####%%%@@@@@%*=-...............++++**#%%....               " << endl;
    cout << "              ... +%#***###*....  .....................:::::--=====--::::::...........................+++++*#%%....               " << endl;
    cout << "              ....+%*****##*..........................................................................******#%%....               " << endl;
    cout << "              ....=%%%%%%%%+..                                                                    ....+#%%%%%%%...                " << endl;
}

void Perintah::readConfig()
{
    // Deklarasi
    string folderName;
    bool valid = false;

    // Alur
    while (!valid)
    {
        try
        {
            cout << endl
                 << "Masukkan config yang ingin di-load (config harus terdapat pada folder config): ";
            cin >> folderName;
            config = ReadConfig(folderName);
            cout << "Config berhasil di-load" << endl
                 << endl;
            valid = true;
        }
        catch (FileNotOpen &e)
        {
            cerr << e.what() << '\n'
                 << "Masukkan config yang valid." << endl;
        }
    }
}

void Perintah::muatState()
{
    // Ambil Config
    Misc misc = config.getMisc();

    pair<int, char> sizeInventory = misc.getStorageSize();
    pair<int, char> sizeLahan = misc.getFieldSize();
    pair<int, char> sizePeternakan = misc.getFarmSize();

    int n_inventory = sizeInventory.first;
    char m_inventory = sizeInventory.second;

    int n_lahan = sizeLahan.first;
    char m_lahan = sizeLahan.second;

    int n_peternakan = sizePeternakan.first;
    char m_peternakan = sizePeternakan.second;

    // Pilihan Permainan
    string pilihan;
    cout << "Selamat datang di permainan ini!" << endl;
    cout << "Apakah Anda ingin memuat state? (y/n) ";
    cin >> pilihan;

    // Loop sampe dapet yang valid
    while (pilihan != "y" && pilihan != "n" && pilihan != "Y" && pilihan != "N")
    {
        cout << endl
             << "Pilihan tidak valid, silahkan masukkan yang benar (y/n): ";
        cin >> pilihan;
    }

    cout << endl
         << endl;

    // Mulai game tanpa muat state / muat game baru
    if (pilihan == "n" || pilihan == "N")
    {
        cout << "Anda memilih untuk memulai permainan baru." << endl;
        cout << "Pada permainan baru akan ada 3 player yang yaitu: " << endl;
        cout << "1. Username Petani1 (peran : Petani)" << endl;
        cout << "2. Username Peternak1 (peran : Peternak)" << endl;
        cout << "3. Username Walikota (peran : Walikota)" << endl;
        cout << "Pada awalnya, setiap pemain memiliki uang sebesar 50 gulden dan berat badan 40 kg" << endl;

        // Inisialisasi Player yang default
        Player *Petani1 = new Petani("Petani1", n_inventory, m_inventory, n_lahan, m_lahan);
        Player *Peternak1 = new Peternak("Peternak1", n_inventory, m_inventory, n_peternakan, m_peternakan);
        Player *Walikota1 = new Walikota("Walikota1", n_inventory, m_inventory);
    }

    // Muat game dari state.txt
    else
    {
        ifstream stateFile("../../../data/state.txt");
        if (!stateFile)
        {
            cerr << "File tidak bisa dibuka.";
            exit(1);
        }

        // Ambil jumlah pemain
        // N
        // <STATE PEMAIN 1> <STATE PEMAIN 2> … <STATE PEMAIN N>

        int numPlayers;
        stateFile >> numPlayers;

        // Looping untuk setiap pemain
        for (int i = 0; i < numPlayers; i++)
        {
            //<USERNAME> Petani <BERAT_BADAN> <UANG>
            // <USERNAME> Peternak <BERAT_BADAN> <UANG>
            // <USERNAME> Walikota <BERAT_BADAN> <UANG>

            // Baca data pemain
            string line;
            getline(stateFile, line);

            stringstream ss(line);

            // Atribut pemain
            string username, role;
            int weight;
            int money;

            ss >> username >> role >> weight >> money;

            Player *player;
            if (role == "Petani")
            {
                player = new Petani(username, n_inventory, m_inventory, n_lahan, m_lahan);
            }
            else if (role == "Peternak")
            {
                Player *player = new Peternak(username, n_inventory, m_inventory, n_peternakan, m_peternakan);
            }
            else if (role == "Walikota")
            {
                player = new Walikota(username, n_inventory, m_inventory);
            }

            // Baca banyak inventory
            // <JUMLAH_ITEM_INVENTORY_(M)>
            int numItems;
            stateFile >> numItems;

            // Looping untuk setiap item terus set ke inventory nya si player
            for (int j = 0; j < numItems; j++)
            {
                //<INVENTORY M>
                string itemName;
                stateFile >> itemName;
                Item *item = config.createItem(itemName);
                player->getInventory().setRandomValue(item);
            }

            // Spesial item untuk setiap orang
            // <JUMLAH_TANAMAN_DI_LADANG_(K)>
            // <JUMLAH_HEWAN_DI_PETERNAKAN_(K)>
            // Walikota gaada tambahan

            int numSpecializedItems;
            stateFile >> numSpecializedItems;

            if (role == "Petani")
            {
                for (int k = 0; k < numSpecializedItems; k++)
                {
                    // <LOKASI_TANAMAN_K> <NAMA_TANAMAN_K> <UMUR_TANAMAN_K>
                    string line2;
                    getline(stateFile, line2);

                    stringstream iss(line2);

                    string slot, plantName;
                    int agePlant;

                    iss >> slot >> plantName >> agePlant;

                    Plant plant = config.createItemPlant(plantName);
                    plant.setUmur(agePlant);

                    int row = slot[1] - '0';
                    char col = slot[0];

                    Petani *petani = dynamic_cast<Petani *>(player);
                    if (petani)
                    {
                        petani->addTanaman(plant, row, col);
                    }
                }
            }

            else if (role == "Peternak")
            {
                for (int k = 0; k < numSpecializedItems; k++)
                {
                    // <LOKASI_HEWAN_K> <NAMA_HEWAN_K> <BERAT_HEWAN_K>
                    string line2;
                    getline(stateFile, line2);

                    stringstream iss(line2);

                    string slot, animalName;
                    int beratAnimal;

                    iss >> slot >> animalName >> beratAnimal;

                    Animal animal = config.createItemAnimal(animalName);
                    animal.setBerat(beratAnimal);

                    int row = slot[1] - '0';
                    char col = slot[0];

                    Peternak *peternak = dynamic_cast<Peternak *>(player);
                    if (peternak)
                    {
                        peternak->addTernak(animal, row, col);
                    }
                }
            }

            else if (role == "Walikota")
            {
                // Do nothing
            }
        }
        int numItemToko;
        stateFile >> numItemToko;

        // <ITEM_1> <JUMLAH_ITEM_1>
        // <ITEM_2> <JUMLAH_ITEM_2>

        for (int k = 0; k < numItemToko; k++)
        {
            string line3;
            getline(stateFile, line3);

            stringstream iss(line3);

            string itemName;
            int jumlahItem;

            iss >> itemName >> jumlahItem;

            // Add the item to toko
            for (int j = 0; j < jumlahItem; j++)
            {
                // Create an Item object
                Item *item = config.createItem(itemName); // Use createItem to create the Item object

                // Add the item to toko
                if (item != nullptr)
                {
                    toko->addItemToko(item);
                }
            }
        }
    }
}

void Perintah::NEXT()
{
    if (Player::getWinner(config.getMisc()) == NULL)
    {
        if (Player::getCurrentPlayer()->getRole() == "Petani")
        {
            Player::getCurrentPlayer()->nextDay();
        }
        Player::nextPlayer();
        cout << "Sekarang adalah giliran " << Player::getCurrentPlayer()->getName() << endl;
    }
    else
    {
        cout << "Selamat " << Player::getWinner(config.getMisc())->getName() << " telah memenangkan permainan!" << endl;
        endGame = true;
    }
    cout << endl;
}
void Perintah::CETAK_PENYIMPANAN()
{
    Player::getCurrentPlayer()->getInventory().printInventory();
    cout << endl;
}
void Perintah::PUNGUT_PAJAK()
{
    try
    {
        if (Player::getCurrentPlayer()->getRole() != "Walikota")
        {
            throw BukanWalikotaExeption();
        }
        else
        {
            Player::getCurrentPlayer()->dapatPajak(config.getRecipe());
        }
        cout << endl;
    }
    catch (BukanWalikotaExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::CETAK_LADANG()
{
    try
    {
        dynamic_cast<Petani *>(Player::getCurrentPlayer())->getLadang().cetakLadang();
    }
    catch (bukanPetaniExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << endl;
}
void Perintah::CETAK_PETERNAKAN()
{
    try
    {

        if (Player::getCurrentPlayer()->getRole() != "Peternak")
        {
            throw BukanPeternakExeption();
        }
        dynamic_cast<Petani *>(Player::getCurrentPlayer())->getLadang().cetakLadang();
        cout << endl;
    }
    catch (BukanPeternakExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::TANAM()
{
    try
    {
        if (Player::getCurrentPlayer()->getRole() != "Petani")
        {
            throw bukanPetaniExeption();
        }
        Player::getCurrentPlayer()->tanam();
        cout << endl;
    }
    catch (bukanPetaniExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (BukanTanamanExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::TERNAK()
{
    try
    {

        if (Player::getCurrentPlayer()->getRole() != "Peternak")
        {
            throw BukanPeternakExeption();
        }
        Player::getCurrentPlayer()->ternak();
        cout << endl;
    }
    catch (BukanPeternakExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (BukanHewanException &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::BANGUN()
{
    try
    {

        if (Player::getCurrentPlayer()->getRole() != "Walikota")
        {
            throw BukanWalikotaExeption();
        }
        Player::getCurrentPlayer()->buatBangunan(config.getRecipe());
        cout << endl;
    }
    catch (BukanWalikotaExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::MAKAN()
{
    try
    {
        Player::getCurrentPlayer()->makan();
    }
    catch (noFoodInInventory &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (EmptyInventoryException &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << endl;
}
void Perintah::KASIH_MAKAN()
{
    try
    {

        if (Player::getCurrentPlayer()->getRole() != "Peternak")
        {
            throw BukanPeternakExeption();
        }
        Player::getCurrentPlayer()->feedTernak();
        cout << endl;
    }
    catch (BukanPeternakExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::BELI()
{
    // Call Player::buyItem with the Toko object
    Player::getCurrentPlayer()->buyItem(*toko); 
}

void Perintah::JUAL()
{
    // Call Player::sellItem with the Toko object
    Player::getCurrentPlayer()->sellItem(*toko);
}

void Perintah::PANEN()
{
    try
    {

        if (Player::getCurrentPlayer()->getRole() != "Petani")
        {
            throw bukanPetaniExeption();
        }
        Player::getCurrentPlayer()->panen(config.getProduct());
        cout << endl;
    }
    catch (bukanPetaniExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::SIMPAN()
{
    try
    {
        string path;
        cout << "Masukkan Masukkan lokasi berkas state : ";
        cin >> path;
        Player::saveState(path);
    }
    catch (FileNotFound &e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::TAMBAH_PEMAIN()
{
    try
    {

        if (Player::getCurrentPlayer()->getRole() != "Walikota")
        {
            throw BukanWalikotaExeption();
        }
        else
        {
            Player::getCurrentPlayer()->tambahPemain(config.getMisc());
        }
        cout << endl;
    }
    catch (BukanWalikotaExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}