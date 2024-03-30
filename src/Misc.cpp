#include "Misc.hpp"

Misc::Misc(int winning_money, int winning_weight, std::pair<int, int> storage_size, std::pair<int, int> field_size, std::pair<int, int> farm_size)
    : winning_money(winning_money), winning_weight(winning_weight), storage_size(storage_size), field_size(field_size), farm_size(farm_size) {}

int Misc::getWinningMoney() const {
    return winning_money;
}

int Misc::getWinningWeight() const {
    return winning_weight;
}

std::pair<int, int> Misc::getStorageSize() const {
    return storage_size;
}

std::pair<int, int> Misc::getFieldSize() const {
    return field_size;
}

std::pair<int, int> Misc::getFarmSize() const {
    return farm_size;
}

std::ostream& operator<<(std::ostream& os ,Misc& m) {
    os << m.getWinningMoney() << std::endl;
    os << m.getWinningWeight() << std::endl;
    os << m.getStorageSize().first << " " << m.getStorageSize().second << std::endl;
    os << m.getFieldSize().first << " " << m.getFieldSize().second << std::endl;
    os << m.getFarmSize().first << " " << m.getFarmSize().second << std::endl;
    return os;
}