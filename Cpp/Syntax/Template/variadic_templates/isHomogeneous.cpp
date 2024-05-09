#include <iostream>

template <typename T1, typename... TN>
constexpr bool isHomogeneous(T1, TN...)
{   
    // compare the type of the first argument with the rest of the arguments
    return (std::is_same<T1,TN>::value && ...); // since C++17
}

int main ()
{
    std::cout << std::boolalpha;
    std::cout << isHomogeneous(1, 2, 3, 4, 5) << std::endl; // true
    std::cout << isHomogeneous(1, 2, 3, 4, 5.0) << std::endl; // false
    std::cout << isHomogeneous(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl; // true

    return 0;
}