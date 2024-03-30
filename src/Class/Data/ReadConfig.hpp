#ifndef READCONFIG_HPP
#define READCONFIG_HPP

#include <fstream>
#include <istream>
#include "Misc.hpp"

#include <iostream>
using namespace std;

class ReadConfig
{

public:
    ReadConfig(string filename) : m()
    {
        int duitMenang , beratMenang , n_inventory , m_inventory , n_lahan , m_lahan , n_peternakan , m_peternakan;
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Gagal membuka file " << filename << endl;
        }

        file >> duitMenang >> beratMenang >> n_inventory >> m_inventory >> n_lahan >> m_lahan >> n_peternakan >> m_peternakan;

        file.close();
        pair<int, int> sizeInventory(n_inventory, m_inventory);
        pair<int, int> sizeLahan(n_lahan, m_lahan);
        pair<int, int> sizePeternakan(n_peternakan, m_peternakan);
        Misc x(duitMenang, beratMenang, sizeInventory, sizeLahan, sizePeternakan);
        m = x;
    }
    Misc getMisc() const
    {
        return m;
    }
private:
    Misc m;

};

#endif