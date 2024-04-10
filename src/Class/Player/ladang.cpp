#include "ladang.hpp"

Ladang::Ladang(int panjang, char lebar) : MatrixMap<Plant>(panjang,lebar){}

void Ladang::cetakLadang(){
    cout << endl;
    cout << "================[ Ladang ]=================" << endl;
    print();
    
    cout << endl << endl;
}

void Ladang::cetakLadangPanen(){
    cout << endl;
    cout << "================[ Ladang ]=================" << endl;
    cout << "     ";
    for (char i = 'A'; i <= cols; i++)
    {
        cout << "  "<< i <<"   ";
    }
    cout << endl << "    ";
    for (char i = 'A'; i <= cols; i++)
    {
        cout << "+-----";
    }
    cout << "+" <<endl;
    for (int i = 1; i <= rows; i++)
    {
        if (i < 10)
        {
            cout << " 0"<<i<<" |";
        }
        else
        {
            cout << " "<<i<<" |";
        }
        
        for (char j = 'A'; j <= cols; j++)
        {
            if (isExist(i, j))
            {
                if (getValue(i, j).getUmur() >= getValue(i, j).getHarvestDuration())
                {
                    Plant p = getValue(i,j);
                    string text = p.getCode();
                    string coloredText = "\x1b[32m"+ text + "\x1b[0m";
                    cout << " " << coloredText<< " |";
                }
                else
                {
                    Plant p = getValue(i,j);
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
        for (char i = 'A'; i <= cols; i++)
        {
            cout << "+-----";
        }
        cout << "+" <<endl;
    }
    
    cout << endl << endl;
}

Plant Ladang::getPlant(int x, char a) const{
    Plant plant = getValue(x , a);
    return plant;
}

unordered_map<string, int> Ladang::countPanen() {
    unordered_map<string, int> result;
    
    for (int i = 1; i < getRows(); i++)
    {
        for(char j= 'A' ; j < getCols(); j++)
        {
            if (isExist(i,j))
            {
                if(getValue(i,j).getUmur() >= getValue(i,j).getHarvestDuration()){
                    string code = getValue(i,j).getCode(); 
                    result[code]++;
                }
            }
        }
    }
    return result;
}

void Ladang::cetakJenisTanaman(){
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

vector<string> Ladang::ambilPanen(string code, int n){
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
            Plant p = getValue(b,a);
            if (isExist(b,a) && p.getCode() == code)
            {
                if (getValue(b,a).getUmur() < getValue(b,a).getHarvestDuration())
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

void Ladang::nextUmur(){
    for (int i = 1; i < getRows(); i++)
    {
        for (char j = 'A'; j < getCols(); j++)
        {
            if (isExist(i,j))
            {
                Plant p = getValue(i,j);
                p.tambahUmur();
                removeValue(i,j);
                Plant * plant = new Plant(p);
                setValue(i,j,p);
            }
        }
    }
}