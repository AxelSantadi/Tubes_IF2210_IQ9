#ifndef MISC_HPP
#define MISC_HPP

#include <iostream>
class Misc {
private:
    int winning_money;
    int winning_weight;
    std::pair<int, int> storage_size;
    std::pair<int, int> field_size;
    std::pair<int, int> farm_size;
    
public:
    Misc();
    Misc(int winning_money, int winning_weight, std::pair<int, int> storage_size, std::pair<int, int> field_size, std::pair<int, int> farm_size);

    int getWinningMoney() const;
    int getWinningWeight() const;
    std::pair<int, int> getStorageSize() const;
    std::pair<int, int> getFieldSize() const;
    std::pair<int, int> getFarmSize() const;

    friend std::ostream& operator<<(std::ostream& os ,Misc& m);
};

#endif
