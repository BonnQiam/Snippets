#include <iostream>

using namespace std;

// 判断调用哪一个函数
void process(int &i) {
    cout << "Left value" << endl;
}

void process(int &&i) {
    cout << "right value" << endl;
}

void UnPerfectForward(int &&i) {
    cout << "forward(int&& i)" << endl;
    process(i);
}
// std::forward()实现就是下面这样
void PerfectForward(int &&i) {
    cout << "forward(int&& i)" << endl;
    process(static_cast<int&&>(i));
}

int main() {

    int aa = 1;

    UnPerfectForward(2); // 希望通过转交调用的是右值传入函数,可是调用的是左值传入 这就是个Unperfect Forwarding
    UnPerfectForward(move(aa));  // 同上

    // 那如何设计Perfect Forwarding?
    // 为传递加上static_cast<int &&>强转或者直接使用std::forward()
    PerfectForward(2);
    PerfectForward(move(aa));

    return 0;
}