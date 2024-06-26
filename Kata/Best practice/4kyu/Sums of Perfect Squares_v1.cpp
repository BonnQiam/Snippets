#include <iostream>
#include <cmath>

// Helper function to check if a number is a perfect square
bool isSquare(int n) {
    int sq_root = static_cast<int>(std::sqrt(n));
    return sq_root * sq_root == n;
}

// Function to find the length of the smallest list of perfect squares
int numSquares(int n) {
    if (isSquare(n)) {
        return 1;
    }

    // Check if the number can be expressed as a sum of two squares
    for (int i = 1; i * i <= n; ++i) {
        if (isSquare(n - i * i)) {
            return 2;
        }
    }

    // Check if the number can be expressed as a sum of three squares
    // Based on the condition that n != 4^a(8b + 7)
    int reduced_n = n;
    while (reduced_n % 4 == 0) {
        reduced_n /= 4;
    }
    if (reduced_n % 8 != 7) {
        return 3;
    }

    // If none of the above, it must be four squares
    return 4;
}

int main() {
    int n = 23;
    std::cout << "The length of the smallest list of perfect squares which add up to " << n << " is " << numSquares(n) << "." << std::endl;
    return 0;
}
