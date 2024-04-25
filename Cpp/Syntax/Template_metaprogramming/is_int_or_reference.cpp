// another metafunction implemented by inheritance.
#include <iostream>
#include "Non-type_Metadata.hpp"

template <typename T> struct is_reference      : public false_type {}; // inherit from false_type
template <typename T> struct is_reference<T&>  : public true_type {};
template <typename T> struct is_reference<T&&> : public true_type {};

template <typename T> struct is_int_or_reference : public is_reference<T> {};// inherit from is_reference
template <> struct is_int_or_reference<int> : public true_type {};

int main(){
    // metafunction call
    std::cout << is_int_or_reference<int>::value << std::endl;   // 1
    std::cout << is_int_or_reference<int>() << std::endl;       // 1
    std::cout << is_int_or_reference<int>()() << std::endl;     // 1
    
    return 0;
}