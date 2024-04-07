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

    // Alur 3
    cout << "Urutan giliran permainan berdasarkan urutan leksikografis dari username pemain." << endl;
    cout << "Selamat bermain!" << endl << endl;

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
            cout << endl << "Masukkan config yang ingin di-load (config harus terdapat pada folder config): ";
            cin >> folderName;
            config = ReadConfig(folderName);
            cout << "Config berhasil di-load" << endl << endl;
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
    string pilihan;
    cout << "Selamat datang di permainan ini!" << endl;
    cout << "Apakah Anda ingin memuat state? (y/n) ";
    cin >> pilihan;
    while (pilihan != "y" && pilihan != "n" && pilihan != "Y" && pilihan != "N")
    {
        cout << endl
             << "Pilihan tidak valid, silahkan masukkan yang benar (y/n): ";
        cin >> pilihan;
    }
    cout << endl << endl;
    if (pilihan == "n" || pilihan == "N")
    {
        cout << "Anda memilih untuk memulai permainan baru." << endl;
        cout << "Pada permainan baru akan ada 3 player yang yaitu: " << endl;
        cout << "1. Username Petani1 (peran : Petani)" << endl;
        cout << "2. Username Peternak1 (peran : Peternak)" << endl;
        cout << "3. Username Walikota (peran : Walikota)" << endl;
        cout << "Pada awalnya, setiap pemain memiliki uang sebesar 50 gulden dan berat badan 40 kg" << endl;
        Player *Petani1 = new Player("Petani1", config.getMisc().getStorageSize().first, config.getMisc().getStorageSize().second);
        Player *Peternak1 = new Player("Peternak1", config.getMisc().getStorageSize().first, config.getMisc().getStorageSize().second);
        Player *Walikota = new Player("Walikota", config.getMisc().getStorageSize().first, config.getMisc().getStorageSize().second);
    }
    else
    {
        // chris
    }
}

void Perintah::NEXT()
{
    if (Player::getWinner(config.getMisc()) == NULL)
    {
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
}
void Perintah::CETAK_LADANG()
{
}
void Perintah::CETAK_PETERNAKAN()
{
}
void Perintah::TANAM()
{
}
void Perintah::TERNAK()
{
}
void Perintah::BANGUN()
{
}
void Perintah::MAKAN()
{
    try
    {
        Player::getCurrentPlayer()->makan();
    }
    catch(noFoodInInventory &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(EmptyInventoryException &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << endl;
}
void Perintah::KASIH_MAKAN()
{
}
void Perintah::BELI()
{
}
void Perintah::JUAL()
{
}
void Perintah::PANEN()
{
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
    catch(FileNotFound& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void Perintah::TAMBAH_PEMAIN()
{
}