#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <algorithm>
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
    static vector<Player*> getPlayers();
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
    Inventory& getInventoryPointer();

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

    bool comparePlayers(const Player* a, const Player* b);
    virtual int getPajak(vector<Recipe> resep) = 0;

    // Method petani
    virtual void addTanaman(Plant plant , int i, char j);
    virtual void tanam();
    virtual void panen(vector<Product> product);
    virtual void nextDay();

    // Method peternak
    virtual void addTernak(Animal animal , int i, char j);
    virtual void ternak();
    virtual void feedTernak();
    virtual void panenTernak(vector<Product> product);
    virtual void jualTernak();

    // Method Walkot
    virtual void removeBahan(string namaBahan, int jumlah);
    virtual void removeBahan(string namaBahan, int jumlah, Inventory inven);
    virtual void buatBangunan(vector<Recipe> resep);
    virtual void buatBangunan(vector<Recipe> resep, Inventory inven);
    virtual void dapatPajak(vector<Recipe> resep);
    virtual void tambahPemain(Misc misc);
};

#endif