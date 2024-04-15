#include "playerException.hpp"

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

string bukanPetanidanPeternakExeption::what()
{
    return "Kamu bukan Petani atau Peternak, kamu tidak bisa menggunakan perintah ini.";
}

string ItemNotFoundException::what()
{
    return "Item tidak ditemukan.";
}

string NumberOutOfRangeException::what()
{
    return "Nomor barang yang diingini tidak valid.";
}

string takAdaResep::what()
{
    return "Kamu tidak punya resep bangunan tersebut!";
}

string FullKandgangException::what()
{
    return "Kandang sudah penuh.";
}

string FullLadangException::what()
{
    return "Ladang sudah penuh.";
}

string TidakPunyaHewanException::what()
{
    return "Kamu tidak punya hewan di Invetory.";
}

string TidakPunyaTanamanException::what()
{
    return "Kamu tidak punya tanaman di Invetory.";
}

string jumlahPanenTernakException::what()
{
    return "Hewan yang siap panen belum sebanyak itu.";
}

