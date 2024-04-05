#include "Exception.hpp"

string SlotKosongException::what()
{
    return "Kamu mengambil harapan kosong dari penyimpanan.";
}

string outOfBoundException::what()
{
    return "Kamu mencoba untuk mengakses indeks yang tidak ada.";
}

string BukanMakananException::what()
{
    return "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!";
}

string BukanTanamanExeption::what()
{
    return "Kamu mencoba untuk menanam sesuatu yang bukan tanaman.";
}

string penyimpananPenuhExeption::what()
{
    return "Penyimpanan penuh, kamu tidak bisa menambahkan barang lagi.";
}

string salahPanenExeption::what()
{
    return "Kamu salah memilih tanaman yang akan dipanen.";
}

string jumlahPanenExeption::what()
{
    return "Tanaman siap panen belum sebanyak itu.";
}

string salahPetakExeption::what()
{
    return "Kamu salah memilih petak.";
}

string petakTerisiExeption::what()
{
    return "Petak sudah terisi.";
}
