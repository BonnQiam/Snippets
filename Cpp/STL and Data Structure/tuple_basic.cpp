#include <tuple>
#include <string>
#include <iostream>

void test_tuple_construct();// Construct a tuple

void test_get();            // Access by get

#define Print_tuple(x) std::cout << "(" << std::get<0>(x) << ", " << std::get<1>(x) << ", " << std::get<2>(x) << ")" << std::endl;

void test_swap();           // Swap two tuples

int main()
{
//    test_tuple_construct();

//    test_get();

    test_swap();

    return 0;
}

void test_tuple_construct()
{
    // 1. Default constructor
    std::tuple<int, float, std::string> t1;
    // 2. Copy constructor
    std::tuple<int, float, std::string> t2(t1);
    // 3. Move constructor
    std::tuple<int, float, std::string> t3(std::move(t1));
    // 4. Copy assignment
    std::tuple<int, float, std::string> t4 = t2;
    // 5. Move assignment
    std::tuple<int, float, std::string> t5 = std::move(t2);
    // 6. Initializer list constructor
    std::tuple<int, float, std::string> t6(1, 2.0, "3");
    // 7. Initializer list assignment
    std::tuple<int, float, std::string> t7 = {1, 2.0, "3"};
    // 8. Make tuple
    auto t8 = std::make_tuple(1, 2.0, "3");
    // 9. Tie
    int a = 1;
    float b = 2.0;
    std::string c = "3";
    auto t9 = std::tie(a, b, c);
    // 10. Structured binding
//    auto [d, e, f] = t9;
}

void test_get()
{
    std::tuple<int, float, std::string> t1(1, 2.0, "3");

    std::cout << std::get<0>(t1) << std::endl;
    std::cout << std::get<1>(t1) << std::endl;
    std::cout << std::get<2>(t1) << std::endl;

    std::get<0>(t1) = 4;
    std::get<1>(t1) = 5.0;
    std::get<2>(t1) = "6";

    Print_tuple(t1);
}

void test_swap()
{
    std::tuple<int, float, std::string> t1(1, 2.0, "3");
    std::tuple<int, float, std::string> t2(4, 5.0, "6");

    std::swap(t1, t2);

    Print_tuple(t1);
    Print_tuple(t2);
}