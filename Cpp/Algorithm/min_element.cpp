// std::min_element: Returns an iterator to the smallest element in a range defined by `[first, last)`.
// Complexity: Linear.

#include <algorithm>
#include <vector>
#include <iostream>

void test_min_element(); // Finds the smallest element in the range
void test_min_element_policy(); // Finds the smallest element in the range with a policy
void test_min_element_policy_reference(); // Finds the smallest element in the range with a policy using reference

int main()
{
//    test_min_element();

//    test_min_element_policy();

    test_min_element_policy_reference();

    return 0;
}

void test_min_element()
{
    std::vector<int> vec = {3, -1, 2, 10, 4};

    auto smallestIt = std::min_element(vec.begin(), vec.end()); 
    // prints -1
    std::cout << "The smallest element is " << *smallestIt << '\n';
}

void test_min_element_policy()
{
    std::vector<int> vec = {3, -1, 2, 10, 4};

    auto smallestIt = std::min_element(vec.begin(), vec.end(), [](int a, int b) { return a < b; }); 
    // prints 10
    std::cout << "The smallest element is " << *smallestIt << '\n';
}
// Explain the policy of `[](int a, int b)`:
// - The lambda expression is a function object that can be called just like a regular function. 
// - The lambda expression `[](int a, int b) { return a > b; }` is a function object that takes two arguments `a` and `b` and returns `a > b`. 
// The `min_element` function will use this function object to compare two elements in the range. If the function object returns `true`, then the first element is considered smaller than the second element. Otherwise, the second element is considered smaller than the first element.

void test_min_element_policy_reference()
{
    std::vector<int> vec = {3, -1, 2, 10, 4};

    int baseline = 0;
    int* baselinePtr = &baseline;
    
    // using min_element to get the smallest element which is greater than the baseline
    auto smallestIt = std::min_element(vec.begin(), vec.end(), [baseline](int a, int b) { return a < b && a > baseline; });
    
    // prints 2
    std::cout << "The smallest element is " << *smallestIt << '\n';
    
    // using min_element to get the smallest element which is greater than the baseline
    smallestIt = std::min_element(vec.begin(), vec.end(), [&baselinePtr](int a, int b) { return a < b && a > *baselinePtr; });

    // prints 2
    std::cout << "The smallest element is " << *smallestIt << '\n';
}