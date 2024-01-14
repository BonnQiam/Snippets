// std::sort: Sorts the elements in the range

#include <algorithm>
#include <vector>
#include <iostream>

void test_sort(); // Sorts the elements in the range
void test_sort_policy(); // Sorts the elements in the range with a policy

int main()
{
//    test_sort();

    test_sort_policy();

    return 0;
}

void test_sort()
{
    std::vector<int> vec = {3, -1, 2, 10, 4};

    std::sort(vec.begin(), vec.end()); 
    // prints -1
    std::cout << "The smallest element is " << vec[0] << '\n';
}

void test_sort_policy()
{
    std::vector<int> vec = {3, -1, 2, 10, 4};

    std::sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; }); 
    // prints -1
    std::cout << "The smallest element is " << vec[0] << '\n';
}