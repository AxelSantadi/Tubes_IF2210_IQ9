#include "Player.hpp"

Player::Player(string name, int n, int m) : name(name), weight(DEFAULT_WEIGHT), money(DEFAULT_MONEY), inventory(n, m) {}

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

Product Player::getItem(int i, int j) const 
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
    inventory.setValue(i, j, Product()); 
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