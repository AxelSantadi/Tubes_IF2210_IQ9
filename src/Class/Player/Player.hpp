#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include "Inventory.hpp"
#include "../Data/Exception.hpp"
#include "../Data/Misc.hpp"
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
    Player(string name, int n, char m, int weight, int money);

    // Destructor
    ~Player();

    // Static Method
    static void dealocatePlayer();
    static void nextPlayer();
    static Player* getCurrentPlayer();
    static Player* getWinner(Misc m);
    
    // Save State
    static void saveState(string path);
    virtual void saveStatePlayer(ofstream &file) const;

    // Getters
    string getName() const;
    int getWeight() const;
    int getMoney() const;
    Inventory getInventory() const;
    Item* getItem(int i, char j) const;
    virtual string getRole() const; // nanti dibuat pure virtual

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

    void buyItem(Toko &toko);
    void sellItem(Toko &toko);

    // virtual int getPajak();
};

#endif