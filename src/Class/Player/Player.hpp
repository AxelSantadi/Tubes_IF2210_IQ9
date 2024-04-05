#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Inventory.hpp"
#include "../Data/Exception.hpp"
#include "Toko.hpp"

using namespace std;

#define DEFAULT_MONEY 50
#define DEFAULT_WEIGHT 40

class Player
{
protected:
    static vector<Player*> players;
    static int idxCurrentPlayer;
    string name;
    int weight;
    int money;
    Inventory inventory;

public:
    // Constructor
    Player(string name, int n, char m);

    // Destructor
    ~Player();

    // Static Method
    static void dealocatePlayer();
    static void nextPlayer();
    static Player* getCurrentPlayer();
    
    // Getters
    string getName() const;
    int getWeight() const;
    int getMoney() const;
    Inventory getInventory() const;
    Item* getItem(int i, char j) const;

    // Setters
    void setName(string name);
    void setWeight(int weight);
    void setMoney(int money);
    void setInventory(Inventory inventory);

    // Methods
    void addItem(Item* item, int i, char j);
    void removeItem(int i, char j);

    void addMoney(int money);
    void useMoney(int money);

    void addWeight(int weight);
    void removeWeight(int weight);

    void makan();

    //virtual int hitungPajak() = 0;  // Dibikin komen dulu biar bisa di compile

    void buyItem(Toko &toko);
    void sellItem(Toko &toko);
};

#endif