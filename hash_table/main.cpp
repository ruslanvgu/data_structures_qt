#include <iostream>
#include <string>
#include <cstring>
class Person
{
    public:
    std::string name;
    std::string phone;
    Person *next;

    Person(std::string name="", std::string phone="")
    {
        this->name =  name;
        this->phone = phone;
        next = nullptr;
    }
};

class HashTable
{
    Person table[100];
public:
    HashTable(){

    }
    ~HashTable(){

    }
    int hash (char  k[]) {
        int hashsum, i;
        for (hashsum = i = 0; k[i]; i++)
            hashsum = ((hashsum * 31) ^ k[i])%100;
        return hashsum;
    }
    int push(Person value)
    {
        int n = value.name.length();
            char char_array[n + 1];
            strcpy(char_array, value.name.c_str());

        int rezult = hash(char_array);
        table[rezult] = value;

        return 0;
    }
    Person * find(std::string name)
    {
        int n = name.length();
            char char_array[n + 1];
            strcpy(char_array, name.c_str());

        int rezult = hash(char_array);

        return &table[rezult];
    }
};

int main(int argc, char *argv[])
{
    HashTable tab;
    Person p1("aaaaa","2323131");
    Person p2("bbbbb","2323131");
    tab.push(p1);
    tab.push(p2);

    std::cout << tab.find(p1.name)->phone<<std::endl;
    return 0;
}
