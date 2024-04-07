#ifndef MISC_HPP
#define MISC_HPP

#include <iostream>
class Misc {
private:
    int winning_money;
    int winning_weight;
    std::pair<int, char> storage_size;
    std::pair<int, char> field_size;
    std::pair<int, char> farm_size;
    
public:
    Misc();
    Misc(int winning_money, int winning_weight, std::pair<int, char> storage_size, std::pair<int, char> field_size, std::pair<int, char> farm_size);

    int getWinningMoney() const;
    int getWinningWeight() const;
    std::pair<int, char> getStorageSize() const;
    std::pair<int, char> getFieldSize() const;
    std::pair<int, char> getFarmSize() const;

    friend std::ostream& operator<<(std::ostream& os ,Misc& m);
};

#endif

