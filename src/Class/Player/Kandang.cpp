#include "Kandang.hpp"

Kandang::Kandang(int panjang, char lebar) : MatrixMap<Animal>(panjang,lebar){}

void Kandang::cetakKandang(){
    cout << endl;
    cout << "================[ Kandang ]=================" << endl;
    print();
    cout << endl << endl;
}

void Kandang::cetakKandangPanen(){
    cout << endl;
    cout << "================[ Kandang ]=================" << endl;
    cout << "     ";
    for (char i = 'A'; i <= getCols(); i++)
    {
        cout << "  "<< i <<"   ";
    }
    cout << endl << "    ";
    for (char i = 'A'; i <= getCols(); i++)
    {
        cout << "+-----";
    }
    cout << "+" <<endl;
    for (int i = 1; i <= getRows(); i++)
    {
        if (i < 10)
        {
            cout << " 0"<<i<<" |";
        }
        else
        {
            cout << " "<<i<<" |";
        }
        
        for (char j = 'A'; j <= getCols(); j++)
        {
            if (isExist(i, j))
            {
                if (getValue(i, j).getBerat() >= getValue(i, j).getWeightToHarvest())
                {
                    Animal p = getValue(i,j);
                    string text = p.getCode();
                    string coloredText = "\x1b[32m"+ text + "\x1b[0m";
                    cout << " " << coloredText<< " |";
                }
                else
                {
                    Animal p = getValue(i,j);
                    string text = p.getCode();
                    string coloredText = "\x1b[31m"+ text + "\x1b[0m";
                    cout << " " << coloredText << " |";
                }
            }
            else
            {
                cout << "     |";
            }
        }
        cout << endl << "    ";
        for (char i = 'A'; i <= getCols(); i++)
        {
            cout << "+-----";
        }
        cout << "+" <<endl;
    }

    cout << endl << endl;
}

Animal Kandang::getAnimal(int x, char a) const{
    return getValue(x,a);
}

unordered_map<string, int> Kandang::countPanen() {
    unordered_map<string, int> result;
    
    for (int i = 1; i < getRows(); i++)
    {
        for(char j= 'A' ; j < getCols(); j++)
        {
            if (isExist(i,j))
            {
                if(getValue(i,j).getBerat() >= getValue(i,j).getWeightToHarvest()){
                    string code = getValue(i,j).getCode();
                    result[code]++;
                }
            }
        }
    }
    return result;
}


void Kandang::cetakJenisHewan(){
    map<string,string> result;
    
    for(int i = 1; i < getRows(); i++)
    {
        for (char j = 'A'; j< getCols(); j++ )
        {
            if (isExist(i,j))
            {
                string code = getValue(i,j).getCode();
                result[code] = getValue(i,j).getName();
            }
        }
    }
    for (auto it = result.begin(); it != result.end(); it++){
        cout <<"- "<< it->first << " : " << it->second << endl;
    }
}


vector<string> Kandang::ambilPanen(string code, int n){
    vector <string> result;
    int i = 0;

    while (n > 0)
    {
        try
        {
            cout << "petak ke-"<< i+1 <<" :" << endl;
            string slot;
            cin >> slot;
            char a;
            int b;
            a = slot[0];
            string rslot = slot;
            slot = slot.substr(1, slot.length()-1);
            b = stoi(slot);
            Animal p = getValue(b,a);
            if (isExist(b,a) && p.getCode() == code)
            {
                if (getValue(b,a).getBerat() < getValue(b,a).getWeightToHarvest())
                {
                    throw belumPanenExeption();
                }
                removeValue(b,a);
                n--;
                i++;
                result.push_back(slot);
            } else 
            {
                throw salahPetakExeption();
            }
        }catch(salahPetakExeption e)
        {
            cerr << e.what() << endl;
        }catch(belumPanenExeption e)
        {
            cerr << e.what() << endl;
        }
    }
    return result;
}