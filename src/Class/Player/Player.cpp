#include "Player.hpp"

vector<Player> Player::players;
int Player::currentPlayer = 0;

Player::Player(string name, int n, int m) : name(name), weight(DEFAULT_WEIGHT), money(DEFAULT_MONEY), inventory(n, m)
{
    players.push_back(*this);
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

Item Player::getItem(int i, int j) const
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

void Player::addItem(Product item, int i, int j)
{
    inventory.setValue(i, j, item);
}

void Player::removeItem(int i, int j)
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

/*
void Player::makan()
{
    cout << "Pilih makanan dari peyimpanan" << endl;
    inventory.print();
    bool success = false;
    string slot;
    while (!success)
    {
        try
        {
            cout << "Slot: ";
            cin >> slot;
            char col = slot[0];
            int row = stoi(slot.substr(1));
            if (inventory.isExist(row, col))
            {
                if (Product *p = dynamic_cast<Product *>(&inventory.getValue(row, col)))
                {
                    if (p->getAddedWeight() > 0)
                    {
                        addWeight(p->getAddedWeight());
                        removeItem(row, col);
                        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                        cout << "Alhasil, berat badan kamu naik menjadi " << getWeight() << endl;
                        success = true;
                    }
                    else
                    {
                        throw BukanMakananException();
                    }
                }
                else
                {
                    throw BukanMakananException();
                }
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
        catch (SlotKosongException &e)
        {
            cerr << e.what() << endl
                 << "Silahkan masukan slot yang berisi makanan.\n\n";
        }
    }
}
*/

void Player::nextPlayer()
{
    currentPlayer = (currentPlayer + 1) % players.size();
}

void Player::buyItem(Toko &toko)
{
    int itemNumber;
    int quantity;

    toko.displayToko();
    std::cout << "Uang Anda: " << money << std::endl;
    std::cout << "Slot penyimpanan yang tersedia: " << endl
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
        Item item = toko.getItemToko(itemName);
        for (int i = 0; i < quantity; ++i)
        {
            this->money -= price;
            toko.removeItemToko(itemName);
        }
        std::cout << "Selamat Anda berhasil membeli " << quantity << " " << itemName << ". Uang Anda tersisa " << this->money << " gulden." << std::endl;
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
