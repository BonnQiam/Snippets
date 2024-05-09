#include <iostream>

// Simplest form of typedef
typedef int* IntPtr; // int* is a pointer to int

// typedef for function pointer
typedef void (*FuncPtr)(int, int); // void is return type, (int, int) is parameter list

void add(int a, int b) {
    std::cout << a + b << std::endl;
}

int main() {
    int x = 5;
    IntPtr p = &x;
    std::cout << *p << std::endl; // 5

    // Function pointer
    FuncPtr f = add;
    f(3, 4); // 7

    return 0;
}