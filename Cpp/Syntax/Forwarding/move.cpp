#include <iostream>
#include <vector>

using namespace std;

void rvalue_reference_1();

class Foo {
public:
    Foo() = default;

    Foo(const Foo &foo) = default;
    Foo& operator=(const Foo &foo) = default; // 添加这一行 —— 在类 Foo 中声明了一个移动构造函数，但是没有声明一个复制赋值运算符。当你声明了一个移动构造函数或移动赋值运算符时，编译器不会自动生成复制赋值运算符。你需要手动声明一个。

    Foo(Foo &&foo) noexcept {}
};

void rvalue_reference_1(){
    vector<Foo> vec;
    vec.insert(vec.begin(), Foo());// move constructor is called

    //  原先是下面这个
    //  iterator insert(const_iterator __position, const value_type& __x);
    // 调用下面这个 Move Semantics
    //  iterator insert(const_iterator __position, value_type&& __x)        // 然后转交给Foo(Foo&& foo)
    //  { return emplace(__position, std::move(__x)); }
    // Foo()这个临时对象为右值交给insert的move assignment然后再交给Foo的move ctor。中间有可能会丢失一些信息。
}