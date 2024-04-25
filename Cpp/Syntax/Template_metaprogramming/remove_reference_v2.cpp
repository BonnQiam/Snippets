#include <iostream>
#include "type_identity.hpp"

// with type_identity, we can implement remove_reference like this:
template <typename T> struct remove_reference      : type_identity<T> {};// inherit from type_identity
template <typename T> struct remove_reference<T&>  : type_identity<T> {};
template <typename T> struct remove_reference<T&&> : type_identity<T> {};

int main(){
    int&& i = 0;
    remove_reference<decltype(i)>::type j = i; 

    // check if remove_reference<int&&>::type is not reference type
    static_assert(
            !std::is_reference<remove_reference<decltype(i)>::type>::value, 
            "Error: remove_reference<int&&>::type is a reference type");
    std::cout << "Assertion passed\n" << std::endl;

    return 0;
}