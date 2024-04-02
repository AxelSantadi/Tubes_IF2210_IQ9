#include "ladang.hpp"

Ladang::Ladang(int panjang, int lebar) : MatrixMap<Plant>(panjang,lebar){}

void Ladang::cetakLadang(){
    cout << "================[ Ladang ]=================" << endl;
    print();
    cout << endl << endl;
}

unordered_map<string, int> Ladang::countPanen() {
    unordered_map<string, int> result;
    
    for (int i = 0; i < getRows(); i++)
    {
        for(char j= 'A' ; j < getCols(); j++)
        {
            if (isExist(i,j))
            {
                string code = getValue(i,j).getCode();
                result[code]++;
            }
        }
    }
    return result;
}

void Ladang::cetakJenisTanaman(){
    map<string,string> result;
    
    for(int i = 0; i < getRows(); i++)
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

vector<string> Ladang::ambilPanen(string code, int n){
    vector <string> result;
    int i = 0;

    while (n > 0)
    {
        try
        {
            cout << "petak ke-"<< i <<" :" << endl;
            string slot;
            cin >> slot;
            char a;
            int b;
            a = slot[0];
            slot = slot.substr(1, slot.length()-1);
            b = stoi(slot);
            if (isExist(b,a) && getValue(b,a).getCode() == code)
            {
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
        }  
    }
    return result;
}

void Ladang::tambahUmur(){
    for (int i = 0; i < getRows(); i++)
    {
        for (char j = 'A'; j < getCols(); j++)
        {
            if (isExist(i,j))
            {
                getValue(i,j).setHarvestDuration(getValue(i,j).getHarvestDuration() - 1);
            }
        }
    }
}







