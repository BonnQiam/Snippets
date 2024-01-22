// using global namespace

#include <iostream>

// Define a namespace named sys
namespace sys {
    int xx = 42;
}

int main() {
    // Accessing the variable xx from the sys namespace using ::
    std::cout << "Value of sys::xx: " << ::sys::xx << std::endl; // "::" before sys is optional, meaning global namespace

    return 0;
}
