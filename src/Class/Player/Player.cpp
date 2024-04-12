#include "Player.hpp"

vector<Player *> Player::players;
int Player::idxCurrentPlayer = 0;

bool Player::comparePlayers(const Player *a, const Player *b)
{
    return a->name < b->name;
}

Player::Player(string name, int n, char m) : name(name), weight(DEFAULT_WEIGHT), money(DEFAULT_MONEY), inventory(n, m)
{
    players.push_back(this);
    sort(players.begin(), players.end(), [](const Player *a, const Player *b)
         { return a->name < b->name; });
}

Player::Player(string name, int n, char m, int weight, int money) : name(name), weight(weight), money(money), inventory(n, m)
{
    players.push_back(this);
    sort(players.begin(), players.end(), [](const Player *a, const Player *b)
         { return a->name < b->name; });
}

Player::~Player()
{
    // cout << "Player " << name << " has been deleted" << endl;
}

vector<Player *> Player::getPlayers()
{
    return players;
}

void Player::dealocatePlayer()
{
    for (int i = 0; i < players.size(); i++)
    {
        delete players[i];
    }
    players.clear();
}

void Player::nextPlayer()
{
    idxCurrentPlayer = (idxCurrentPlayer + 1) % players.size();
}

Player *Player::getCurrentPlayer()
{
    return players[idxCurrentPlayer];
}

Player *Player::getWinner(Misc m)
{
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i]->getWeight() >= m.getWinningWeight() && players[i]->getMoney() >= m.getWinningMoney())
        {
            return players[i];
        }
    }
    return NULL;
}

void Player::saveState(string path, Toko* toko)
{
    ofstream file;
    file.open(path);
    if (file.is_open())
    {
        file << players.size() << endl;
        for (int i = 0; i < players.size(); i++)
        {
            players[i]->saveStatePlayer(file);
        }
        toko->saveStatetoko(file);
        file.close();
    }
    else
    {
        throw FileNotFound();
    }
}

void Player::saveStatePlayer(ofstream &file) const
{
    // Playernya
    file << this->name << " " << this->getRole() << " " << this->weight << " " << this->money << endl;
    file << this->inventory.countNotEmpty() << endl;

    // Inventorynya
    for (auto it : this->inventory.getData())
    {
        file << it.second->getName() << endl;
    }
}

string Player::getName() const
{
    return name;
}

int Player::getWeight() const
{
    return weight;
}

int Player::getMoney() const
{
    return money;
}

Inventory Player::getInventory() const
{
    return inventory;
}

Inventory &Player::getInventoryPointer()
{
    return inventory;
}

Item *Player::getItem(int i, char j) const
{
    return inventory.getValue(i, j);
}

void Player::setName(string name)
{
    this->name = name;
}

void Player::setWeight(int weight)
{
    this->weight = weight;
}

void Player::setMoney(int money)
{
    this->money = money;
}

void Player::setInventory(Inventory inventory)
{
    this->inventory = inventory;
}

void Player::addItem(Item *item, int i, char j)
{
    inventory.setValue(i, j, item);
}

void Player::removeItem(int i, char j)
{
    inventory.removeValue(i, j);
}

void Player::addMoney(int money)
{
    this->money += money;
}

void Player::useMoney(int money)
{
    this->money -= money;
}

void Player::addWeight(int weight)
{
    this->weight += weight;
}

void Player::removeWeight(int weight)
{
    this->weight -= weight;
}

void Player::makan()
{
    bool success = false;
    string slot;
    if (inventory.isEmpty())
    {
        throw EmptyInventoryException();
    }
    else if (inventory.noFood())
    {
        throw noFoodInInventory();
    }
    else
    {
        std::cout << "Pilih makanan dari peyimpanan" << endl;
        inventory.print();
        while (!success)
        {
            try
            {
                std::cout << "Slot: ";
                std::cin >> slot;
                char col = slot[0];
                int row = stoi(slot.substr(1));
                std::cout << inventory.getRows() << " " << row << " " << inventory.getCols() << " " << col << endl;
                if (inventory.isExist(row, col))
                {
                    Item *p = inventory.getValue(row, col);
                    if (p->isMakanan())
                    {
                        addWeight(p->getAddedWeight());
                        removeItem(row, col);
                        std::cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                        std::cout << "Alhasil, berat badan kamu naik menjadi " << getWeight() << endl
                                  << endl;
                        success = true;
                    }
                    else
                    {
                        throw BukanMakananException();
                    }
                }
                else if (inventory.getRows() < row || 1 < row || inventory.getCols() < col || 'A' < col)
                {
                    throw outOfBoundException();
                }
                else
                {
                    throw SlotKosongException();
                }
            }
            catch (BukanMakananException &e)
            {
                std::cerr << e.what() << endl
                          << "Silahkan masukan slot yang berisi makanan.\n\n";
            }
            catch (outOfBoundException &e)
            {
                std::cerr << e.what() << endl
                          << "Silahkan masukan slot yang benar.\n\n";
            }
            catch (SlotKosongException &e)
            {
                std::cerr << e.what() << endl
                          << "Silahkan masukan slot yang berisi makanan.\n\n";
            }
        }
    }
}

void Player::buyItem(Toko &toko)
{
    int itemNumber;
    int quantity;

    toko.displayToko();
    std::cout << endl;
    std::cout << "Uang Anda: " << money << std::endl;
    std::cout << "Slot penyimpanan yang tersedia: " << inventory.countEmpty() << endl
              << endl;

    std::cout << "Nomor barang yang ingin dibeli : ";
    std::cin >> itemNumber;
    std::cout << endl;

    std::cout << "Kuantitas : ";
    std::cin >> quantity;
    std::cout << endl;

    string itemName;
    try
    {
        itemName = toko.getItemNameByNumber(itemNumber);
    }
    catch (NumberOutOfRangeException &e)
    {
        std::cerr << e.what() << endl
                  << "Silahkan masukkan nomor barang yang benar." << endl;
        return;
    }

    int price;
    try
    {
        price = toko.getItemPrice(itemName) * quantity;
    }
    catch (ItemNotFoundException &e)
    {
        std::cerr << e.what() << endl
                  << "Silahkan masukkan nomor barang yang ada di toko." << endl;
        return;
    }

    if (money < price)
    {
        std::cout << "Uang tidak cukup." << std::endl;
        return;
    }

    if (inventory.countEmpty() < quantity)
    {
        std::cout << "Penyimpanan inventory tidak cukup." << std::endl;
        return;
    }

    Item *item;

    try
    {
        item = toko.getItemToko(itemName);
    }
    catch (ItemNotFoundException &e)
    {
        std::cerr << e.what() << endl
                  << "Silahkan masukkan nomor barang yang benar." << endl;
        return;
    }

    if (getRole() == "Walikota" && item->getJenis() == "Bangunan")
    {
        std::cout << "Walikota tidak dapat membeli bangunan." << endl;
        return;
    }

    for (int i = 0; i < quantity; ++i)
    {
        try
        {
            toko.removeItemToko(itemName);
        }
        catch (ItemNotFoundException &e)
        {
            std::cerr << e.what() << endl
                      << "Barang yang ingin dibeli sudah habis dari toko / Kuantitas barang yang ingin dibeli melebihi supply yang di toko." << endl;
            return;
        }
        this->money -= price;
    }

    std::cout << "Selamat Anda berhasil membeli " << quantity << " " << itemName << ". Uang Anda tersisa " << this->money << " gulden." << std::endl
              << endl;
    std::cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << std::endl;
    this->inventory.printInventory();
    std ::cout << endl;

    string slots;
    std::cout << "Petak : ";
    std::cin.ignore(); // Ignore the newline character in the input buffer
    std::getline(std::cin, slots);

    std::istringstream ss(slots);
    std::string slot;
    while (std::getline(ss, slot, ',') && quantity > 0)
    {
        // Remove leading and trailing spaces
        slot.erase(0, slot.find_first_not_of(' ')); // leading
        slot.erase(slot.find_last_not_of(' ') + 1); // trailing

        this->inventory.storeItemInSlot(item, slot);
        --quantity;
    }
    std::cout << item->getName() << " berhasil disimpan dalam penyimpanan!" << std::endl;
}

void Player::sellItem(Toko &toko)
{
    int tempMoney = 0;
    std::cout << "Berikut merupakan penyimpanan Anda" << endl;
    this->inventory.printInventory();
    std::cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;

    string slots;
    std::cout << "Petak : ";
    std::getline(std::cin, slots);

    std::istringstream ss(slots);
    std::string slot;
    while (std::getline(ss, slot, ','))
    {
        slot.erase(0, slot.find_first_not_of(' ')); // leading
        slot.erase(slot.find_last_not_of(' ') + 1); // trailing

        int row = std::stoi(slot.substr(1));
        char col = slot[0];

        Item *item = this->inventory.getValue(row, col);

        if ((getRole() == "Petani" || getRole() == "Peternak") && item->getJenis() == "Bangunan")
        {
            std::cout << "Petani dan Peternak tidak dapat menjual bangunan." << endl;
            continue;
        }

        int itemPrice = item->getPrice();

        // Remove the item from the inventory
        this->inventory.removeValue(row, col);

        // Add the item to the store's inventory
        toko.addItemToko(item); // Pass the pointer to the item

        // Give the player money for the item
        tempMoney += itemPrice;
    }
    this->money += tempMoney;
    std::cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << tempMoney << " gulden!" << endl;
}

// Petani
void Player::addTanaman(Plant plant, int i, char j) {}
void Player::tanam() {}
void Player::panen(vector<Product> product) {}
void Player::nextDay() {}

// Peternak
void Player::addTernak(Animal animal, int i, char j) {}
void Player::ternak() {}
void Player::feedTernak() {}
void Player::jualTernak() {}

// Walkot
void Player::removeBahan(string namaBahan, int jumlah) {}
void Player::removeBahan(string namaBahan, int jumlah, Inventory inven) {}
void Player::buatBangunan(vector<Recipe> resep) {}
void Player::buatBangunan(vector<Recipe> resep, Inventory inven) {}
void Player::dapatPajak(vector<Recipe> resep) {}
void Player::tambahPemain(Misc misc) {}