#include <iostream>
#include <utility>

void an_orther_fun(int a, int& b)
{
    std::cout << "in an_orther_fun(): a = " << a << ", b = " << ++b << std::endl;
}

//void transmit(int a, int b)
void transmit(int a, int& b)
{
    an_orther_fun(a, b);
}

int main()
{
    int a = 2, b = 3;

    std::cout << " before transmit(): a = " << a << ", b = " << b << std::endl;
    
    transmit(a, b);
    
    std::cout << "  after transmit(): a = " << a << ", b = " << b << std::endl;
    
    return 0;
}