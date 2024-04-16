#include "itemException.hpp"

string BukanMakananException::what()
{
    return "Apa yang kamu lakukan\?\?!! Kamu mencoba untuk memakan itu?!!";
}

string BukanMakananHewanException::what()
{
    return "Apa yang kamu lakukan\?\?!! Kamu mencoba untuk memberi makan itu?!!";
}

string BukanMakananHerbivore::what()
{
    return "Kamu mencoba untuk memberi makan herbivore dengan makanan yang salah.";
}

string BukanMakananCarnivore::what()
{
    return "Kamu mencoba untuk memberi makan carnivore dengan makanan yang salah.";
}

string BukanHewanException::what()
{
    return "Kamu mencoba untuk memelihara sesuatu yang bukan hewan.";
}

string BukanTanamanExeption::what()
{
    return "Kamu mencoba untuk menanam sesuatu yang bukan tanaman.";
}

string NegativeUmurException::what(){
    return "Umur tidak boleh negatif.";
}

string NegativeBeratException ::what()
{
    return "Berat tidak boleh negatif.";
}




