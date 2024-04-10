#include "Exception.hpp"

string FileNotFound::what()
{
    return "Lokasi berkas tidak valid";
}

string FileNotOpen::what()
{
    return "Gagal membuka file.";
}

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



string BukanMakananException::what()
{
    return "Apa yang kamu lakukan\?\?!! Kamu mencoba untuk memakan itu?!!";
}

string BukanHewanException::what()
{
    return "Kamu mencoba untuk memelihara sesuatu yang bukan hewan.";
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

string belumPanenExeption::what()
{
    return "Tanaman belum siap panen.";
}

string bukanPetaniExeption::what()
{
    return "Kamu bukan petani, kamu tidak bisa menggunakan perintah ini.";
}

string BukanWalikotaExeption::what()
{
    return "Kamu bukan walikota, kamu tidak bisa menggunakan perintah ini.";
}

string BukanPeternakExeption::what()
{
    return "Kamu bukan Peternak, kamu tidak bisa menggunakan perintah ini.";
}