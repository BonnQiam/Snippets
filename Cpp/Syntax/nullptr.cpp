#include <iostream>
using namespace std;

void f(int i) {
   cout<<"void f(int i)" <<endl;
}

void f(void *p) {
    cout<<"void f(void *p)" <<endl;
}

int main() {
    f(0);

    // #ifndef __cplusplus
    // #define NULL ((void *)0)
    // #else   /* C++ */
    // #define NULL 0

    //  c语言中将 NULL定义为空指针，而在c++中直接定义为 0，这是因为 C++是强类型的，void *是不能隐式转换成其他指针类型的。

    if(NULL==0)  cout<<"NULL==0"<<endl;
    // f(NULL); // ambiguous,因为 NULL==0 所以存在二义性 指针也可以是个 int 的地址
    // c++11 空指针 nullptr
    f(nullptr); // typedef decltype(nullptr)	nullptr_t;
    // nullptr_t 为 nullptr的类型
    nullptr_t  nl;  // 使用 nullptr_t 定义的任何变量都具有 nullptr 一样的行为
    f(nl);

    return 0;
}
