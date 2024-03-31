#include "Item.hpp"

Item::Item()
{
    this->id = 0;
    this->code = "";
    this->name = "";
    this->type = "";
}

Item::Item(int id, string code, string name, string type)
{
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
}

Item &Item::operator=(const Item &i)
{
    this->id = i.id;
    this->code = i.code;
    this->name = i.name;
    this->type = i.type;
    return *this;
}

Item::~Item() {}

// Getter and Setter
int Item::getId(){
    return id;
}

void Item::setId(int i){
    id = i;
}

string Item::getCode(){
    return code;
}

void Item::setCode(string c){
    code = c;
}

string Item::getName(){
    return name;
}

void Item::setName(string n){
    name = n;
}

string Item::getType(){
    return type;
}

void Item::setType(string t){
    type = t;
}

void Item::input(istream &is){
    is >> id;
    is >> code;
    is >> name;
    is >> type;
}

void Item::output(ostream &os){
    os << id << endl;
    os << code << endl;
    os << name << endl;
    os << type << endl;
}

// Operator Overloading
Item &Item::operator+=(int x){
    id += x;
    return *this;
}

Item &Item::operator-=(int x){
    id -= x;
    return *this;
}

Item &Item::operator+=(const Item &i){
    id += i.id;
    return *this;
}

Item &Item::operator-=(const Item &i){
    id -= i.id;
    return *this;

}

// Display item
void Item::display(){
    cout << "ID: " << id << endl;
    cout << "Code: " << code << endl;
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
}