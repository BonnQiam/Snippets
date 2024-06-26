#include <type_traits>
#include <iostream>

#include "Peano numbers.hpp"

// Test cases for Peano operations

// Test Addition
using AddTest1 = Add<Zero, Zero>::type;                         // Should be Zero
using AddTest2 = Add<Succ<Zero>, Zero>::type;                   // Should be Succ<Zero>
using AddTest3 = Add<Zero, Succ<Zero>>::type;                   // Should be Succ<Zero>
using AddTest4 = Add<Succ<Succ<Zero>>, Succ<Succ<Zero>>>::type; // Should be Succ<Succ<Succ<Succ<Zero>>>>

#if 0

// Test Subtraction
using SubTest1 = Sub<Zero, Zero>::type; // Should be Zero
using SubTest2 = Sub<Succ<Zero>, Zero>::type; // Should be Succ<Zero>
using SubTest3 = Sub<Succ<Succ<Zero>>, Succ<Zero>>::type; // Should be Succ<Zero>
using SubTest4 = Sub<Succ<Succ<Zero>>, Succ<Succ<Zero>>>::type; // Should be Zero
using SubTest5 = Sub<Zero, Succ<Zero>>::type; // Should be Negative

// Test Multiplication
using MulTest1 = Mul<Zero, Zero>::type; // Should be Zero
using MulTest2 = Mul<Succ<Zero>, Zero>::type; // Should be Zero
using MulTest3 = Mul<Zero, Succ<Zero>>::type; // Should be Zero
using MulTest4 = Mul<Succ<Succ<Zero>>, Succ<Succ<Zero>>>::type; // Should be Succ<Succ<Succ<Succ<Zero>>>>

// Test Division
using DivTest1 = Div<Zero, Succ<Zero>>::type; // Should be Zero
using DivTest2 = Div<Succ<Succ<Zero>>, Succ<Zero>>::type; // Should be Succ<Succ<Zero>>
using DivTest3 = Div<Succ<Succ<Succ<Zero>>>, Succ<Succ<Zero>>>::type; // Should be Succ<Zero>
using DivTest4 = Div<Succ<Zero>, Zero>::type; // Should be Infinity

// Test Even/Odd
using EvenTest1 = Even<Zero>::type; // Should be True
using EvenTest2 = Even<Succ<Zero>>::type; // Should be False
using EvenTest3 = Even<Succ<Succ<Zero>>>::type; // Should be True
using OddTest1 = Odd<Zero>::type; // Should be False
using OddTest2 = Odd<Succ<Zero>>::type; // Should be True
using OddTest3 = Odd<Succ<Succ<Zero>>>::type; // Should be False

// Test Comparison
using CompareTest1 = Compare<Zero, Zero>::type; // Should be EQ
using CompareTest2 = Compare<Succ<Zero>, Zero>::type; // Should be GT
using CompareTest3 = Compare<Zero, Succ<Zero>>::type; // Should be LT
using CompareTest4 = Compare<Succ<Succ<Zero>>, Succ<Zero>>::type; // Should be GT
using CompareTest5 = Compare<Succ<Succ<Zero>>, Succ<Succ<Zero>>>::type; // Should be EQ

#endif

// Utility to print test results
template <typename T>
void print_result(const char *test_name)
{
    if constexpr (std::is_same_v<T, Zero>)
    {
        std::cout << test_name << ": Zero" << std::endl;
    }
    else if constexpr (std::is_same_v<T, Succ<Zero>>)
    {
        std::cout << test_name << ": Succ<Zero>" << std::endl;
    }
    else if constexpr (std::is_same_v<T, Succ<Succ<Zero>>>)
    {
        std::cout << test_name << ": Succ<Succ<Zero>>" << std::endl;
    }
    else if constexpr (std::is_same_v<T, Succ<Succ<Succ<Zero>>>>)
    {
        std::cout << test_name << ": Succ<Succ<Succ<Zero>>>" << std::endl;
    }
    else if constexpr (std::is_same_v<T, Negative>)
    {
        std::cout << test_name << ": Negative" << std::endl;
    }
    else if constexpr (std::is_same_v<T, Infinity>)
    {
        std::cout << test_name << ": Infinity" << std::endl;
    }
    else if constexpr (std::is_same_v<T, True>)
    {
        std::cout << test_name << ": True" << std::endl;
    }
    else if constexpr (std::is_same_v<T, False>)
    {
        std::cout << test_name << ": False" << std::endl;
    }
    else if constexpr (std::is_same_v<T, EQ>)
    {
        std::cout << test_name << ": EQ" << std::endl;
    }
    else if constexpr (std::is_same_v<T, GT>)
    {
        std::cout << test_name << ": GT" << std::endl;
    }
    else if constexpr (std::is_same_v<T, LT>)
    {
        std::cout << test_name << ": LT" << std::endl;
    }
    else
    {
        std::cout << test_name << ": Unknown type" << std::endl;
    }
}

// using gcc
// Compile with g++ -std=c++17 -o Peano_numbers Peano\ numbers.cpp
int main()
{
    // Addition tests
    print_result<AddTest1>("AddTest1");
    print_result<AddTest2>("AddTest2");
    print_result<AddTest3>("AddTest3");
    print_result<AddTest4>("AddTest4");

#if 0
    // Subtraction tests
    print_result<SubTest1>("SubTest1");
    print_result<SubTest2>("SubTest2");
    print_result<SubTest3>("SubTest3");
    print_result<SubTest4>("SubTest4");
    print_result<SubTest5>("SubTest5");

    // Multiplication tests
    print_result<MulTest1>("MulTest1");
    print_result<MulTest2>("MulTest2");
    print_result<MulTest3>("MulTest3");
    print_result<MulTest4>("MulTest4");

    // Division tests
    print_result<DivTest1>("DivTest1");
    print_result<DivTest2>("DivTest2");
    print_result<DivTest3>("DivTest3");
    print_result<DivTest4>("DivTest4");

    // Even/Odd tests
    print_result<EvenTest1>("EvenTest1");
    print_result<EvenTest2>("EvenTest2");
    print_result<EvenTest3>("EvenTest3");
    print_result<OddTest1>("OddTest1");
    print_result<OddTest2>("OddTest2");
    print_result<OddTest3>("OddTest3");

    // Comparison tests
    print_result<CompareTest1>("CompareTest1");
    print_result<CompareTest2>("CompareTest2");
    print_result<CompareTest3>("CompareTest3");
    print_result<CompareTest4>("CompareTest4");
    print_result<CompareTest5>("CompareTest5");
#endif

    return 0;
}
