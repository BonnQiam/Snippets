#include <iostream>
#include <utility>

void an_orther_fun(int a, int&& b)
{
    std::cout << "in an_orther_fun(): a = " << a << ", b = " << b << std::endl;
}

void transmit(int a, int&& b)
{
    an_orther_fun(a, b);  
}

int main()
{
    int a = 2;

    transmit(a, 3); // a is lvalue, 3 is rvalue
    
    return 0;
}