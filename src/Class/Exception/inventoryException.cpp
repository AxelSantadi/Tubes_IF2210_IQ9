#include "inventoryException.hpp"

string EmptyInventoryException::what()
{
    return "Penyimpanan kamu kosong.";
}

string SlotKosongException::what()
{
    return "Kamu mengambil harapan kosong dari penyimpanan.";
}

string outOfBoundException::what()
{
    return "Kamu mencoba untuk mengakses indeks yang tidak ada.";
}

string noFoodInInventory::what()
{
    return "Tidak ada makanan di penyimpanan.";
}

string penyimpananPenuhExeption::what()
{
    return "Penyimpanan penuh, kamu tidak bisa menambahkan barang lagi.";
}