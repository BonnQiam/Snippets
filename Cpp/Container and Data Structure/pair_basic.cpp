#include <utility>
#include <iostream>

void test_pair_construct();     // Construct a pair

void test_first_second();       // Access first and second

void test_get();                // Access by get
void test_swap();               // Swap two pairs 

#define Print_pair(x) std::cout << "(" << x.first << ", " << x.second << ")" << std::endl;

int main()
{
//   test_pair_construct();
    
//    test_first_second();
    
//    test_get();
//    test_swap();

    return 0;
}

void test_pair_construct(){
    // 1. Default constructor
    std::pair<int, float> p1;
    // 2. Copy constructor
    std::pair<int, float> p2(p1);
    // 3. Move constructor
    std::pair<int, float> p3(std::move(p1));
    // 4. Copy assignment
    std::pair<int, float> p4 = p2;
    // 5. Move assignment
    std::pair<int, float> p5 = std::move(p2);
    // 6. Initializer list constructor
    std::pair<int, float> p6(1, 2.0);
    // 7. Initializer list assignment
    std::pair<int, float> p7 = {1, 2.0};
    // 8. Make pair
    auto p8 = std::make_pair(1, 2.0);
    // 9. Structured binding in C++17
//    auto [a, b] = p8;
}

void test_first_second(){
    std::pair<int, float> p1(1, 2.0);
    
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;

    p1.first = 3;
    p1.second = 4.0;
    Print_pair(p1);
}

void test_get(){
    std::pair<int, float> p1(1, 2.0);
    
    std::cout << std::get<0>(p1) << std::endl;
    std::cout << std::get<1>(p1) << std::endl;

    std::cout << std::get<int> (p1) << std::endl;
    std::cout << std::get<float> (p1) << std::endl;
}

void test_swap(){
    std::pair<int, float> p1(1, 2.0);
    std::pair<int, float> p2(3, 4.0);
    std::swap(p1, p2);

    Print_pair(p1);
    Print_pair(p2);
}