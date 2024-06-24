#include <iostream>
#include <functional>

using std::function; // std::function is a general-purpose polymorphic function wrapper.

void Lambda_simple();
void Lambda_return_lambda_or_function();
void Lambda_capture();

int main(){
    Lambda_simple();
    Lambda_return_lambda_or_function();
    Lambda_capture();

    std::function<void(int x)> f_display_42 = [](int x) {std::cout << x << std::endl;};
    f_display_42(44);
}

void Lambda_simple(){
    int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
    std::cout << "m:" << m << std::endl;//output m:16
    
    std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << std::endl;//output n:9
}

void Lambda_return_lambda_or_function(){
    auto gFunc = [](int x) -> function<int(int)> { return [=](int y) { return x + y; }; };
    auto lFunc = gFunc(4);
    std::cout << lFunc(5) << std::endl;

    auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
    auto a = hFunc(gFunc(7), 8);
    std::cout << a << std::endl;
}

void Lambda_capture(){
    int a1 = 111, b = 222;
    auto func = [=, &b]()mutable { a1 = 22; b = 333; std::cout << "a:" << a1 << " b:" << b << std::endl; };
    
    func();
    std::cout << "a:" << a1 << " b:" << b << std::endl;

    a1 = 333;
    auto func2 = [=, &a1] { a1 = 444; std::cout << "a:" << a1 << " b:" << b << std::endl; };
    
    func2();
    std::cout << "a:" << a1 << " b:" << b << std::endl;
}