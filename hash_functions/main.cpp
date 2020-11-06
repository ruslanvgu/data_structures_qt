#include <iostream>
#include <string>

std::string hash_fubction(std::string value)
{
    std::string rezult;
    for(int i=0; i < value.length(); i++)
    {
        value[i]=value[i]>>1;
    }
    return value;
}

int main(int argc, char *argv[])
{
    std::cout << hash_fubction("hello")<<std::endl;

    return 0;
}
