#include "Non-type_Metadata.hpp"
#include<iostream>

template <typename T, typename U>
struct is_same : false_type {}; // is_same inherits from false_type

template <typename T>
struct is_same<T, T> : true_type {}; // is_same inherits from true_type

int main(){
    int i = 0;
    std::cout << is_same<decltype(i), int>::value << std::endl;    // 1
    std::cout << is_same<decltype(i), int>::value << std::endl;    // 1, implicit cast: true_type --> bool

    return 0;
}