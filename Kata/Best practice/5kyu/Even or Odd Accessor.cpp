// Create a function or callable object that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers. The function should also return "Even" or "Odd" when accessing a value at an integer index.
// For example:

//evenOrOdd(2); //'Even'
//evenOrOdd[2]; //'Even'
//evenOrOdd(7); //'Odd'
//evenOrOdd[7]; //'Odd'

#include <iostream>
#include <string>

class EvenOrOdd {
public:
    // Callable operator
    std::string operator()(int num) const {
        return num % 2 == 0 ? "Even" : "Odd";
    }

    // Array subscript operator
    std::string operator[](int num) const {
        return num % 2 == 0 ? "Even" : "Odd";
    }
};

int main() {
    EvenOrOdd evenOrOdd;

    // Usage examples
    std::cout << evenOrOdd(2) << std::endl; // 'Even'
    std::cout << evenOrOdd[2] << std::endl; // 'Even'
    std::cout << evenOrOdd(7) << std::endl; // 'Odd'
    std::cout << evenOrOdd[7] << std::endl; // 'Odd'

    return 0;
}
