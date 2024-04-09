#include "Player.hpp"

vector<Player *> Player::players;
int Player::idxCurrentPlayer = 0;


bool Player::comparePlayers(const Player* a, const Player* b) {
    return a->name < b->name;
}

Player::Player(string name, int n, char m) : name(name), weight(DEFAULT_WEIGHT), money(DEFAULT_MONEY), inventory(n, m)
{
    players.push_back(this);
    sort(players.begin(), players.end(), [](const Player* a, const Player* b) 
    {
        return a->name < b->name;
    });
}

Player::Player(string name, int n, char m, int weight, int money) : name(name), weight(weight), money(money), inventory(n, m)
{
    players.push_back(this);
    sort(players.begin(), players.end(), [](const Player* a, const Player* b) 
    {
        return a->name < b->name;
    });
}

Player::~Player()
{
    cout << "Player " << name << " has been deleted" << endl;
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

void Player::saveState(string path)
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

Inventory& Player::getInventoryPointer() {
    return inventory;
}


Item *Player::getItem(int i, char j) const
{
    return inventory.getValue(i, j);
}

string Player::getRole() const
{
    return "Player";
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
        cout << "Pilih makanan dari peyimpanan" << endl;
        inventory.print();
        while (!success)
        {
            try
            {
                cout << "Slot: ";
                cin >> slot;
                char col = slot[0];
                int row = stoi(slot.substr(1));
                cout << inventory.getRows() << " " << row << " " << inventory.getCols() << " " << col << endl;
                if (inventory.isExist(row, col))
                {
                    Item *p = inventory.getValue(row, col);
                    if (p->isMakanan())
                    {
                        addWeight(p->getAddedWeight());
                        removeItem(row, col);
                        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                        cout << "Alhasil, berat badan kamu naik menjadi " << getWeight() << endl
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
                cerr << e.what() << endl
                     << "Silahkan masukan slot yang berisi makanan.\n\n";
            }
            catch (outOfBoundException &e)
            {
                cerr << e.what() << endl
                     << "Silahkan masukan slot yang benar.\n\n";
            }
            catch (SlotKosongException &e)
            {
                cerr << e.what() << endl
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
    cout << endl;
    std::cout << "Uang Anda: " << money << std::endl;
    std::cout << "Slot penyimpanan yang tersedia: " << inventory.countEmpty() << endl
              << endl;

    std::cout << "Nomor barang yang ingin dibeli : ";
    std::cin >> itemNumber;
    cout << endl;

    std::cout << "Kuantitas : ";
    std::cin >> quantity;
    cout << endl;

    string itemName = toko.getItemNameByNumber(itemNumber);
    int price = toko.getItemPrice(itemName) * quantity;
    if (money >= price)
    {
        Item *item = toko.getItemToko(itemName);
        for (int i = 0; i < quantity; ++i)
        {
            this->money -= price;
            toko.removeItemToko(itemName);
        }
        std::cout << "Selamat Anda berhasil membeli " << quantity << " " << itemName << ". Uang Anda tersisa " << this->money << " gulden." << std::endl
                  << endl;
        std::cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << std::endl;
        this->inventory.printInventory();
        std ::cout << endl;

        string slot;
        for (int i = 0; i < quantity; ++i)
        {
            std::cout << "Petak Slot: ";
            std::cin >> slot;
            this->inventory.storeItemInSlot(item, slot);
        }
    }

    else
    {
        std::cout << "Uang tidak cukup" << std::endl;
    }
}

void Player::sellItem(Toko &toko)
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    this->inventory.printInventory();
    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    string slot;
    cout << "Petak : ";
    cin >> slot;

    Item *item = this->inventory.getValue(std::stoi(slot.substr(1)), slot[0]);

    // Remove the item from the inventory
    this->inventory.removeValue(std::stoi(slot.substr(1)), slot[0]);

    // Add the item to the store's inventory
    toko.addItemToko(item); // Pass the pointer to the item

    // Give the player money for the item
    this->money += item->getPrice();

    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << item->getPrice() << " gulden!" << endl;
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
void Player::panenTernak(vector<Product> product) {}
void Player::jualTernak() {}

// Walkot
void Player::removeBahan(string namaBahan, int jumlah) {}
void Player::buatBangunan(vector<Recipe> resep) {}
void Player::dapatPajak(vector<Recipe> resep) {}
void Player::tambahPemain(Misc misc) {}