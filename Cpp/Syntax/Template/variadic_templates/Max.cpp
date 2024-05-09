#include <iostream>

using namespace std;

// 参数type相同的maximum
int maximum(int n) {
    return n;
}

template<typename ...Args>
int maximum(int n, Args...args) {
    return std::max(n, maximum(args...));
    // 当参数包为空时，递归调用会调用 maximum(int n) 这个函数
}

int main() {
    cout << maximum(57, 48, 60, 100, 20, 18) << endl;
}