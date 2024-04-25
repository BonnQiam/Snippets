// Example of Meta-function to check if a type is a reference type.
#include<iostream>

template <typename T> struct is_reference      { static constexpr bool value = false; };    // #1
template <typename T> struct is_reference<T&>  { static constexpr bool value = true; };     // #2
template <typename T> struct is_reference<T&&> { static constexpr bool value = true; };     // #3

int main() {
    std::cout << is_reference<int>::value << std::endl;    // 0
    std::cout << is_reference<int&>::value << std::endl;   // 1
    std::cout << is_reference<int&&>::value << std::endl;  // 1
    
    // is_reference<int>::value is const rather than variable, so it can be used in constant expressions.
    static_assert(is_reference<int>::value == false, "Error: int is not a reference type");

    std::cout << "Assertion passed\n" << std::endl;

    return 0;
}