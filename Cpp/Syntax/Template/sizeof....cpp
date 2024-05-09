#include <iostream>

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << sizeof...(Types) << '\n'; // print number of remaining types
    std::cout << sizeof...(args) << '\n';  // print number of remaining args
}

int main()
{
    print(7.5, "hello", std::string("world"));
    return 0;
}