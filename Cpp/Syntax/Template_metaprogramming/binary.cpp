#include<iostream>

template <int N>
struct binary {
  static constexpr int value = binary<N / 10>::value << 1 | N % 10;
};

template <>
struct binary<0> {
  static constexpr int value = 0;
};

int main(){
    std::cout << binary<101>::value << std::endl;       // Equivalent to: std::cout << 5 << std::endl;
    std::cout << binary<1110>::value << std::endl;      // Equivalent to: std::cout << 14 << std::endl;
    std::cout << binary<10110>::value << std::endl;     // Equivalent to: std::cout << 22 << std::endl;

    /*
    binary<x>::value is const rather than variable, so it can be used in constant expressions.
    */
   static char array[binary<101>::value];     // Equivalent to: static char array[5]

   for (int i = 0; i < binary<101>::value; i++) {
       array[i] = 'a' + i;
   }

   std::cout << array << std::endl;    // Output: abcde

    return 0;

}