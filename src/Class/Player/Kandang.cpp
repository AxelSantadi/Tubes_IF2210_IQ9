#include "Kandang.hpp"
#include "../Data/pcolor.hpp"

Kandang::Kandang(int panjang, char lebar) : MatrixMap<Animal>(panjang,lebar){}

void Kandang::cetakKandang(){
    cout << endl;
    cout << "================[ Peternakan ]=================" << endl;
    print();
    cout << endl << endl;
}

void Kandang::cetakKandangPanen(){
    cout << endl;
    cout << "================[ Peternakan ]=================" << endl;
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
                    cout << " ";
                    for (int k = 0; k < text.length(); k++)
                    {
                        print_green(text[k]);
                    }
                    cout <<" |";
                } else {
                    Animal p = getValue(i,j);
                    string text = p.getCode();
                    cout << " ";
                    for (int k = 0; k < text.length(); k++)
                    {
                        print_red(text[k]);
                    }
                    cout <<" |";
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
    
    for (int i = 1; i <= getRows(); i++)
    {
        for(char j= 'A' ; j <= getCols(); j++)
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
    
    for(int i = 1; i <= getRows(); i++)
    {
        for (char j = 'A'; j <= getCols(); j++ )
        {
            if (isExist(i,j))
            {   
                string position = "";
                position += j;
                if(i < 10)
                {
                    position += "0" + to_string(i);
                } else {
                    position += to_string(i);
                }
                result[position] = getValue(i,j).getName();
            }
        }
    }
    for (auto it = result.begin(); it != result.end(); it++){
        cout <<"- "<< it->first << " : " << it->second << endl;
    }
}


vector<string> Kandang::ambilPanenhewan(string code, int n){
    vector <string> result;
    int i = 0;

    while (n > 0)
    {
        try
        {
            cout << "petak ke-"<< i+1 <<" : ";
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
                }else{
                    removeValue(b,a);
                    n--;
                    i++;
                    result.push_back(rslot);
                }
            } else 
            {
                throw salahPetakExeption();
            }
        }catch(salahPetakExeption &e)
        {
            cerr << e.what() << endl;
        }catch(belumPanenExeption &e)
        {
            cerr << e.what() << endl;
        }
    }
    return result;
}