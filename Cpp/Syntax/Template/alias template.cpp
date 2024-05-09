#include <iostream>
#include <vector>

using namespace std;

template<typename T>
using Vec=vector<T, allocator<T>>;  // using新用法：alias template

//# define Vec<T> template<typename T> vector<T, allocator<T>> // error
//typedef vector<int, allocator<int>> Vec; // error

int main() {
    Vec<int> col; // vector<int, allocator<int>> col;

    // if using macro, it will be replaced as template<typename int> vector<int, allocator<int>>  error not what we want

    // if using typedef, it will be replaced as vector<int, allocator<int>> col; error not what we want

    return 0;
}