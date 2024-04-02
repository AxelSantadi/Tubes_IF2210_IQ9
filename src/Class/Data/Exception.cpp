#include "Exception.hpp"

string SlotKosongException::what()
{
    return "Kamu mengambil harapan kosong dari penyimpanan.";
}

string BukanMakananException::what()
{
    return "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!";
}