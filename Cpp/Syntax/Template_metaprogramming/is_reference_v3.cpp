// Example of Meta-function to check if a type is a reference type.
#include <iostream>
#include "Non-type_Metadata.hpp"

template <typename T> struct is_reference      : public false_type {}; // inherit from false_type
template <typename T> struct is_reference<T&>  : public true_type {};
template <typename T> struct is_reference<T&&> : public true_type {};

int main(){
    std::cout << is_reference<int>::value << std::endl;;  // 0
    std::cout << is_reference<int&>::value << std::endl;; // 1
    std::cout << is_reference<int&&>::value << std::endl;;// 1

    // check if is_reference<int>::value is const rather than variable
    static_assert(is_reference<int>::value == false, "Error: int is not a reference type");
    std::cout << "Assertion passed\n" << std::endl;

    return 0;
}