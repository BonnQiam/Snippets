// Example of Meta-function to check if a type is a reference type.
#include <iostream>
#include "Non-type_Metadata.hpp"

template <typename T> struct is_reference      { using type = false_type; }; // #1
template <typename T> struct is_reference<T&>  { using type = true_type; };  // #2
template <typename T> struct is_reference<T&&> { using type = true_type; };  // #3

int main(){
    std::cout << is_reference<int>::type::value << std::endl;;  // 0
    std::cout << is_reference<int>::type() << std::endl;;       // 0, implicit cast: false_type --> bool
    std::cout << is_reference<int>::type()() << std::endl;;     // 0

    // check if is_reference<int>::type::value is const rather than variable
    static_assert(is_reference<int>::type::value == false, "Error: int is not a reference type");
    std::cout << "Assertion passed\n" << std::endl;

    return 0;
}