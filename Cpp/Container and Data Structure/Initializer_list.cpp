#include <iostream>

using namespace std;

// 参数type相同的max
int max(initializer_list<int> initializerList) {
    int res = *initializerList.begin();
    for (auto elem:initializerList)
        res = max(res, elem);
    return res;
}

// initializer_list<int> initializerList = {57, 48, 60, 100, 20, 18};

int main() {
    cout << max({57, 48, 60, 100, 20, 18}) << endl;
}