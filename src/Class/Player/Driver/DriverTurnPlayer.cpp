#include "Toko.hpp"
#include "Toko.cpp"

#include "../Items/Item.hpp"
#include "../Items/Item.cpp"

#include "../Items/Plant.hpp"
#include "../Items/Plant.cpp"

#include "../Items/Animal.hpp"
#include "../Items/Animal.cpp"

#include "Player.hpp"
#include "Player.cpp"

#include "Inventory.hpp"
#include "Inventory.cpp"

#include "../Items/Product.hpp"
#include "../Items/Product.cpp"

#include "MatrixMap.hpp"

#include "../Data/Exception.cpp"
int main()
{
    Player* p1 = new Player("Player 1", 3, 'D');
    Player* p2 = new Player("Player 2", 3, 'D');
    Player* p3 = new Player("Player 3", 3, 'D');
    
    // Menampilkan pemain yang sedang aktif saat ini
    cout << "Player yang sedang aktif: " << Player::getCurrentPlayer()->getName() << endl;

    // Beralih ke pemain berikutnya
    Player::nextPlayer();

    // Menampilkan pemain yang sedang aktif setelah beralih
    cout << "Player yang sedang aktif sekarang: " << Player::getCurrentPlayer()->getName() << endl;

    Player::nextPlayer();
    Player::nextPlayer();
    cout << "Player yang sedang aktif sekarang: " << Player::getCurrentPlayer()->getName() << endl;
    return 0;
}