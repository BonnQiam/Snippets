#include <iostream>
#include <utility>

void an_orther_fun(int a, int& b)
{
    std::cout << "in an_orther_fun(): a = " << a << ", b = " << ++b << std::endl;
}

template <typename F, typename T1, typename T2>
void transmit(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

int main()
{
    int a = 2, b = 3;

    std::cout << " before transmit(): a = " << a << ", b = " << b << std::endl;
    
    transmit(an_orther_fun, a, b);
    
    std::cout << "  after transmit(): a = " << a << ", b = " << b << std::endl;
    
    return 0;
}