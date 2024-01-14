#include <tuple>
#include <string>
#include <iostream>

void test_tuple_construct();// Construct a tuple

#define Print_tuple(x) std::cout << x << std::endl;

int main()
{
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
    auto [d, e, f] = t9;
}