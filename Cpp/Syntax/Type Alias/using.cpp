#include <iostream>

using int_ptr = int*; // int* is a pointer to int
using func_ptr = void (*)(int, int); // void is return type, (int, int) is parameter list

void add(int a, int b) {
    std::cout << a + b << std::endl;
}

int main() {
    int x = 5;
    int_ptr p = &x;
    std::cout << *p << std::endl; // 5

    // Function pointer
    func_ptr f = add;
    f(3, 4); // 7

    return 0;
}