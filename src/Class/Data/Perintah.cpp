#include "Perintah.hpp"

Perintah::Perintah()
{
    // Deklarasi
    string folderName, pilihan, perintah;
    endGame = false;

    // Inisialisasi
    initilization();

    // Alur 1
    readConfig();
    toko = new Toko(config);

    // Alur 2
    muatState();

    // Alur 3
    cout << "Urutan giliran permainan berdasarkan urutan leksikografis dari username pemain." << endl;
    cout << "Selamat bermain!" << endl
         << endl;

    // Alur 4
    bool walkotSudahAmbilPajak = false;
    cout << "Sekarang adalah giliran " << Player::getCurrentPlayer()->getName() << endl;
    while (!endGame)
    {
        cout << "Masukkan perintah: ";
        cin >> perintah;
        cin.ignore();
        if (perintah == "NEXT")
        {
            NEXT();
            walkotSudahAmbilPajak = false;
        }
        else if (perintah == "CETAK_PENYIMPANAN")
        {
            CETAK_PENYIMPANAN();
        }
        else if (perintah == "PUNGUT_PAJAK" && !walkotSudahAmbilPajak)
        {
            PUNGUT_PAJAK();
            walkotSudahAmbilPajak = true;
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
        else if (perintah == "PUNGUT_PAJAK" && walkotSudahAmbilPajak)
        {
            cout<< "Cieeee, mau korupsi ya? :D. Karena kamu nakal, ini ada isi dari UU Nomor 20 Tahun 2001 Tindak Pidana Korupsi pasal demi pasal, begini isinya:" << endl
                << "Pasal 2" << endl
                << "    ayat 1"<<endl
                << "        Setiap orang yang secara melawan hukum melakukan perbuatan memperkaya diri sendiri atau orang lain atau suatu korporasi yang dapat merugikan keuangan negara atau perekonornian negara, dipidana dengan pidana penjara seumur hidup atau pidana penjara paling singkat 4 tahun dan paling lama 20 (dua puluh) tahun dan denda paling sedikit Rp 200.000.000,00 (dua ratus juta rupiah) dan paling banyak Rp 1.000.000.000,00 (satu miliar rupiah)." << endl
                << "    ayat 2" << endl
                << "        Dalam hal tindak pidana korupsi sebagaimana dimaksud dalam ayat (1) dilakukan dalam keadaan tertentu, pidana mati dapat dijatuhkan." << endl
                << "Pasal 3" << endl
                << "    Setiap orang yang dengan tujuan menguntungkan diri sendiri atau orang lain atau suatu korporasi, menyalahgunakan kewenangan, kesempatan atau sarana yang ada padanya karena jabatan atau kedudukan yang dapat merugikan kouangan negara atau perekonomian negara, dipidana dengan pidana penjara seumur hidup atau pidana penjara paling singkat 1 tahun dan paling lama 20 tahun dan atau denda paling sedikit Rp 50.000.000,00 (lima puluh juta rupiah) dan paling banyak Rp 1.000.000.000,00 (satu miliar rupiah)." << endl
                << "Pasal 5" << endl
                << "    ayat 1"<<endl
                << "        Dipidana dengan pidana penjara paling singkat 1 tahun dan paling lama 5 tahundan atau pidana denda paling sedikit Rp 50.000.000,00 (lima puluh juta rupiah) dan paling banyak Rp 250.000.000,00 (dua ratus lima puluh juta rupiah) setiap orang yang: memberi atau menjanjikan sesuatu kepada pegawai negeri atau penyelenggara negara dengan maksud supaya pegawai negeri atau penyelenggara negara tersebut berbuat atau tidak berbuat sesuatu dalam jabatannya, yang bertentangan dengan kewajibannya; atau memberi sesuatu kepada pegawai negeri atau penyelenggara negara karena atau berhubungan dengan sesuatu yang bertentangan dengan kewajiban, dilakukan atau tidak dilakukan dalam jabatannya." << endl
                << "    ayat 2" << endl
                << "        Bagi pegawai negeri atau penyelenggara negara yang menerima pemberian atau janji sebagaimana dimaksud dalam ayat (1) huruf a atau huruf b, dipidana dengan pidana yang sama sebagaimana dimaksud dalam ayat (1)."<<endl
                << "Pasal 6" << endl
                << "    ayat 1"<<endl
                << "        Dipidana dengan pidana penjara paling singkat 3 tahun dan paling lama 15 tahundan pidana denda paling sedikit Rp 150.000.000,00 (seratus lima puluh juta rupiah) dan paling banyak Rp 750.000.000,00 (tujuh ratus lima puluh juta rupiah) setiap orang yang: memberi atau menjanjikan sesuatu kepada hakim dengan maksud untuk mempengaruhi putusan perkara yang diserahkan kepadanya untuk diadili; atau memberi atau menjanjikan sesuatu kepada seseorang yang menurut ketentuan peraturan perundang-undangan ditentukan menjadi advokat untuk menghadiri sidang pengadilan dengan maksud untuk mempengaruhi nasihat atau pendapat yang akan diberikan berhubung dengan perkara yang diserahkan kepada pengadilan untuk diadili." << endl
                << "    ayat 2" << endl
                << "        Bagi hakim yang menerima pemberian atau janji sebagaimana dimaksud dalam ayat (1) huruf a atau advokat yang menerima pemberian atau janji sebagaimana dimaksud dalam ayat (1) huruf b, dipidana dengan pidana yang sama sebagaimana dimaksud dalam ayat (1)." << endl
                << "Pasal 7" << endl
                << "    ayat 1"<<endl
                << "        Dipidana dengan pidana penjara paling singkat 2 tahun dan paling lama 7 tahundan atau pidana denda paling sedikit Rp 100.000.000,00 (seratus juta rupiah) dan paling banyak Rp 350.000.000,00 (tiga ratus lima puluh juta rupiah): pemborong, ahli bangunan yang pada waktu membuat bangunan, atau penjual bahan bangunan yang pada waktu menyerahkan bahan bangunan, melakukan perbuatan curang yang dapat membahayakan keamanan orang atau barang, atau keselamatan negara dalam keadaan perang; setiap orang yang bertugas mengawasi pembangunan atau penyerahan bahan bangunan, sengaja membiarkan perbuatan curang sebagaimana dimaksud dalam huruf a setiap orang yang pada waktu menyerahkan barang keperluan Tentara Nasional Indonesia dan atau Kepolisian Negara Republik Indonesia melakukan perbuatan curang yang dapat membahayakan keselamatan negara dalam keadaan perang; atau setiap orang yang bertugas mengawasi penyerahan barang keperluan Tentara Nasional Indonesia dan atau Kepolisian Negara Republik Indonesia dengan sengaja membiarkan perbuatan curang sebagaimana dimaksud dalam huruf c." << endl
                << "    ayat 2" << endl
                << "        Bagi orang yang menerima penyerahan bahan bangunan atau orang yang menerima penyerahan barang keperluan Tentara Nasional Indonesia dan atau Kepolisian Negara Republik Indonesia dan membiarkan perbuatan curang sebagaimana dimaksud dalam ayat (1) huruf a atau huruf c, dipidana dengan pidana yang sama sebagaimana dimaksud dalam ayat (1)." << endl
                << "Pasal 8" << endl
                << "    Dipidana dengan pidana penjara paling singkat 3 tahun dan paling lama 15 tahun dan pidana denda paling sedikit Rp 150.000.000,00 (seratus lima puluh juta rupiah) dan paling banyak Rp 750.000.000,00 (tujuh ratus lima puluh juta rupiah), pegawai negeri atau orang selain pegawai negeri yang ditugaskan menjalankan suatu jabatan umum secara terus menerus atau untuk sementara waktu, dengan sengaja menggelapkan uang atau surat berharga yang disimpan karena jabatannya, atau membiarkan uang atau surat berharga tersebut diambil atau digelapkan oleh orang lain, atau membantu dalam melakukan perbuatan tersebut." << endl
                << "Pasal 9" << endl
                << "    Dipidana dengan pidana penjara paling singkat 1 tahun dan paling lama 5 tahun dan pidana denda paling sedikit Rp 50.000.000,00 (lima puluh juta rupiah) dan paling banyak Rp 250.000.000,00 (dua ratus lima puluh juta rupiah) pegawai negeri atau orang selain pegawai negeri yang diberi tugas menjalankan suatu jabatan umum secara terus menerus atau untuk sementara waktu, dengan sengaja memalsu buku-buku atau daftar-daftar yang khusus untuk pemeriksaan administrasi." << endl
                << "Pasal 10" << endl
                << "    Dipidana dengan pidana penjara paling singkat 2 tahun dan paling lama 7 tahundan pidana denda paling sedikit Rp 100.000.000,00 (seratus juta rupiah) dan paling banyak Rp 350.000.000,00 (tiga ratus lima puluh juta rupiah) pegawai negeri atau orang selain pegawai negeri yang diberi tugas menjalankan suatu jabatan umum secara terus menerus atau untuk sementara waktu, dengan sengaja: menggelapkan, menghancurkan, merusakkan, atau membuat tidak dapat dipakai barang, akta, surat, atau daftar yang digunakan untuk meyakinkan atau membuktikan di muka pejabat yang berwenang, yang dikuasai karena jabatannya; atau membiarkan orang lain menghilangkan, menghancurkan, merusakkan, atau membuat tidak dapat dipakai barang, akta, surat, atau daftar tersebut; atau membantu orang lain menghilangkan, menghancurkan, merusakkan, atau membuat tidak dapat dipakai barang, akta, surat, atau daftar tersebut." << endl
                << "Pasal 11" << endl
                << "    Dipidana dengan pidana penjara paling singkat 1 tahun dan paling lama 5 tahun dan atau pidana denda paling sedikit Rp 50.000.000,00 (lima puluh juta rupiah) dan paling banyak Rp 250.000.000,00 (dua ratus lima puluh juta rupiah) pegawai negeri atau penyelenggara negara yang menerima hadiah atau janji padahal diketahui atau patut diduga, bahwa hadiah atau janji tersebut diberikan karena kekuasaan atau kewenangan yang berhubungan dengan jabatannya, atau yang menurut pikiran orang yang memberikan hadiah atau janji tersebut ada hubungan dengan jabatannya." << endl
                << "Pasal 12" << endl
                << "    Dipidana dengan pidana penjara seumur hidup atau pidana penjara paling singkat 4 tahun dan paling lama 20 tahun dan pidana denda paling sedikit Rp 200.000.000,00 (dua ratus juta rupiah) dan paling banyak Rp 1.000.000.000,00 (satu miliar rupiah):" << endl
                << "      a. pegawai negeri atau penyelenggara negara yang menerima hadiah atau janji, padahal diketahui atau patut diduga bahwa hadiah atau janji tersebut diberikan untuk menggerakkan agar melakukan atau tidak melakukan sesuatu dalam jabatannya, yang bertentangan dengan kewajibannya;" << endl
                << "      b. pegawai negeri atau penyelenggara negara yang menerima hadiah, padahal diketahui atau patut diduga bahwa hadiah tersebut diberikan sebagai akibat atau disebabkan karena telah melakukan atau tidak melakukan sesuatu dalam jabatannya yang bertentangan dengan kewajibannya;" << endl
                << "      c. hakim yang menerima hadiah atau janji, padahal diketahui atau patut diduga bahwa hadiah atau janji tersebut diberikan untuk mempengaruhi putusan perkara yang diserahkan kepadanya untuk diadili;" << endl
                << "      d. seseorang yang menurut ketentuan peraturan perundang-undangan ditentukan menjadi advokat untuk menghadiri sidang pengadilan, menerima hadiah atau janji, padahal diketahui atau patut diduga bahwa hadiah atau janji tersebut untuk mempengaruhi nasihat atau pendapat yang akan diberikan, berhubung dengan perkara yang diserahkan kepada pengadilan untuk diadili;" << endl
                << "      e. pegawai negeri atau penyelenggara negara yang dengan maksud menguntungkan diri sendiri atau orang lain secara melawan hukum, atau dengan menyalahgunakan kekuasaannya memaksa seseorang memberikan sesuatu, membayar, atau menerima pembayaran dengan potongan, atau untuk mengerjakan sesuatu bagi dirinya sendiri;" << endl
                << "      f. pegawai negeri atau penyelenggara negara yang pada waktu menjalankan tugas, meminta, menerima, atau memotong pembayaran kepada pegawai negeri atau penyelenggara negara yang lain atau kepada kas umum, seolah-olah pegawai negeri atau penyelenggara negara yang lain atau kas umum tersebut mempunyai utang kepadanya, padahal diketahui bahwa hal tersebut bukan merupakan utang;" << endl
                << "      g. pegawai negeri atau penyelenggara negara yang pada waktu menjalankan tugas, meminta atau menerima pekerjaan, atau penyerahan barang, seolah-olah merupakan utang kepada dirinya, padahal diketahui bahwa hal tersebut bukan merupakan utang;" << endl
                << "      h. pegawai negeri atau penyelenggara negara yang pada waktu menjalankan tugas, telah menggunakan tanah negara yang di atasnya terdapat hak pakai, seolah-olah sesuai dengan peraturan perundang-undangan, telah merugikan orang yang berhak, padahal diketahuinya bahwa perbuatan tersebut bertentangan dengan peraturan perundangundangan; atau" << endl
                << "      i. pegawai negeri atau penyelenggara negara baik langsung maupun tidak langsung dengan sengaja turut serta dalam pemborongan, pengadaan, atau persewaan, yang pada saat dilakukan perbuatan, untuk seluruh atau sebagian ditugaskan untuk mengurus atau mengawasinya." << endl
                << endl << "Demikianlah isi dari UU Nomor 20 Tahun 2001 Tindak Pidana Korupsi pasal demi pasal, sekarang kamu sudah mengetahui hukum korupsi di Indonesia. Semoga kamu tidak mencoba melakukan tindakan korupsi lagi ya! (｡•̀ᴗ-)✧" << endl;
        }
        else
        {
            cout << "Perintah Tidak Valid Masukan lagi yang benar." << endl;
        }
    }
}

Perintah::~Perintah()
{
    Player::dealocatePlayer();
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
        string path;
        bool valid = false;
        ifstream stateFile;
        while (!valid)
        {
            try
            {
                cout << "Masukkan lokasi berkas state : ";
                cin >> path;
                ifstream stateFile(path);
                if (!stateFile)
                {
                    throw FileNotFound();
                }
                int numPlayers;
                string dummy;
                stateFile >> numPlayers;

                getline(stateFile, dummy);

                // Looping untuk setiap pemain
                for (int i = 0; i < numPlayers; i++)
                {
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
                        player = new Petani(username, n_inventory, m_inventory, weight, money, n_lahan, m_lahan);
                    }
                    else if (role == "Peternak")
                    {
                        player = new Peternak(username, n_inventory, m_inventory, weight, money, n_peternakan, m_peternakan);
                    }
                    else if (role == "Walikota")
                    {
                        player = new Walikota(username, n_inventory, m_inventory, weight, money);
                    }

                    int numItems;
                    stateFile >> numItems;

                    // Looping untuk setiap item terus set ke inventory nya si player
                    for (int j = 0; j < numItems; j++)
                    {
                        string itemName;
                        stateFile >> itemName;
                        Item *item = config.createItem(itemName);
                        player->getInventoryPointer().setRandomValue(item);
                    }

                    stateFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (player->getRole() == "Petani" || player->getRole() == "Peternak")
                    {
                        int numSpecializedItems;
                        stateFile >> numSpecializedItems;
                        getline(stateFile, dummy);

                        if (player->getRole() == "Petani")
                        {
                            for (int k = 0; k < numSpecializedItems; k++)
                            {
                                string line2;
                                getline(stateFile, line2);

                                stringstream iss(line2);

                                string slot, plantName;
                                int agePlant;

                                iss >> slot >> plantName >> agePlant;

                                Plant plant = config.createItemPlant(plantName);
                                try
                                {
                                    plant.setUmur(agePlant);
                                }
                                catch (NegativeUmurException &e)
                                {
                                    cerr << e.what() << '\n';
                                }

                                string rowStr = slot.substr(1);
                                int row = stoi(rowStr);
                                char col = slot[0];

                                Petani *petani = dynamic_cast<Petani *>(player);
                                if (petani)
                                {
                                    petani->addTanaman(plant, row, col);
                                }
                            }
                        }
                        else if (player->getRole() == "Peternak")
                        {
                            for (int k = 0; k < numSpecializedItems; k++)
                            {
                                string line2;
                                getline(stateFile, line2);

                                stringstream iss(line2);

                                string slot, animalName;
                                int beratAnimal;

                                iss >> slot >> animalName >> beratAnimal;

                                Animal animal = config.createItemAnimal(animalName);
                                try
                                {
                                    animal.setBerat(beratAnimal);
                                }
                                catch (NegativeBeratException &e)
                                {
                                    cerr << e.what() << '\n';
                                }
                                
                                string rowStr = slot.substr(1);
                                int row = stoi(rowStr);
                                char col = slot[0];

                                Peternak *peternak = dynamic_cast<Peternak *>(player);
                                if (peternak)
                                {
                                    peternak->addTernak(animal, row, col);
                                }
                            }
                        }
                    }
                }
                cout << "State berhasil dimuat" << endl;
                string line;

                int numItemToko;
                stateFile >> numItemToko;

                cout << "Jumlah item di toko: " << numItemToko << endl;

                getline(stateFile, dummy);

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

                        else
                        {
                            cout << "Item " << itemName << "tidak ditemukan pada config :(" << endl;
                            return;
                        }
                    }
                }
                valid = true;
            }
            catch (FileNotFound &e)
            {
                cerr << e.what() << '\n';
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
        if (Player::getCurrentPlayer()->getRole() != "Petani")
        {
            throw bukanPetaniExeption();
        }
        dynamic_cast<Petani *>(Player::getCurrentPlayer())->getLadang().cetakLadangPanen();
        dynamic_cast<Petani *>(Player::getCurrentPlayer())->getLadang().cetakJenisTanaman();
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
        dynamic_cast<Peternak *>(Player::getCurrentPlayer())->getKandang().cetakKandangPanen();
        dynamic_cast<Peternak *>(Player::getCurrentPlayer())->getKandang().cetakJenisHewan();
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
        if (Player::getCurrentPlayer()->getInventory().noPlant())
        {
            throw TidakPunyaTanamanException();
        }
        if (dynamic_cast<Petani *>(Player::getCurrentPlayer())->getLadang().isFull())
        {
            throw FullLadangException();
        }
        Player::getCurrentPlayer()->tanam();
        cout << endl;
    }
    catch (bukanPetaniExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (FullLadangException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (TidakPunyaTanamanException &e)
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
        if (Player::getCurrentPlayer()->getInventory().noAnimal())
        {
            throw TidakPunyaHewanException();
        }
        if (dynamic_cast<Peternak *>(Player::getCurrentPlayer())->getKandang().isFull())
        {
            throw FullKandgangException();
        }
        Player::getCurrentPlayer()->ternak();
        cout << endl;
    }
    catch (BukanPeternakExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (TidakPunyaHewanException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (FullKandgangException &e)
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
    if (Player::getCurrentPlayer()->getInventoryPointer().isFull())
    {
        std::cout << "Penyimpanan sudah penuh, pembelian tidak dapat dilakukan." << std::endl;
        return;
    }

    // Call Player::buyItem with the Toko object
    Player::getCurrentPlayer()->buyItem(*toko);
}

void Perintah::JUAL()
{
    if (Player::getCurrentPlayer()->getInventoryPointer().isEmpty())
    {
        std::cout << "Penyimpanan kosong, penjualan tidak dapat dilakukan." << std::endl;
        return;
    }

    // Call Player::sellItem with the Toko object
    Player::getCurrentPlayer()->sellItem(*toko);
}

void Perintah::PANEN()
{
    try
    {
        if (Player::getCurrentPlayer()->getRole() != "Petani" && Player::getCurrentPlayer()->getRole() != "Peternak")
        {
            throw bukanPetanidanPeternakExeption();
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
        Player::saveState(path, toko);
        cout << "State berhasil disimpan." << endl;
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