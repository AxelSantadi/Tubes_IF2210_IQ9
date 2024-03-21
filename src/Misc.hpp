#include <iostream>

class Misc {
public:
    Misc(int winning_money, int winning_weight, std::pair<int, int> storage_size, std::pair<int, int> field_size, std::pair<int, int> farm_size)
        : winning_money(winning_money), winning_weight(winning_weight), storage_size(storage_size), field_size(field_size), farm_size(farm_size) {}

    int getWinningMoney() const { return winning_money; }
    int getWinningWeight() const { return winning_weight; }
    std::pair<int, int> getStorageSize() const { return storage_size; }
    std::pair<int, int> getFieldSize() const { return field_size; }
    std::pair<int, int> getFarmSize() const { return farm_size; }

private:
    int winning_money;
    int winning_weight;
    std::pair<int, int> storage_size;
    std::pair<int, int> field_size;
    std::pair<int, int> farm_size;
};