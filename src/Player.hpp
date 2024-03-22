#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Inventory.hpp"
#include <iostream>
using namespace std;

#define DEFAULT_MONEY 50
#define DEFAULT_WEIGHT 40

class Player
{
    protected:
        string name;
        int weight;
        int money;
        Inventory inventory;
    
    public:
        Player(string name, int n, int m);

        string getName() const;
        int getWeight() const;
        int getMoney() const;
        Inventory getInventory() const;
        Product getItem(int i, int j) const;

        void setName(string name);
        void setWeight(int weight);
        void setMoney(int money);
        void setInventory(Inventory inventory);

        void addItem(Product item, int i, int j);
        void removeItem(int i, int j);
        
        void addMoney(int money);
        void useMoney(int money);

        void addWeight(int weight);
        void removeWeight(int weight);
};

#endif