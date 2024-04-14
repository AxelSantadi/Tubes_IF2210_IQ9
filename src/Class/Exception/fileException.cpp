#include "fileException.hpp"

string FileNotFound::what()
{
    return "Lokasi berkas tidak valid";
}

string FileNotOpen::what()
{
    return "Gagal membuka file.";
}