#include <iostream>
using namespace std;

void lambda_capture_by_value();
void lambda_capture_by_reference();
void lambda_capture_implicit();
void lambda_capture_hybrid();
void lambda_capture_this();

int main()
{
    lambda_capture_by_value();
    lambda_capture_by_reference();
    lambda_capture_implicit();
    lambda_capture_hybrid();
    lambda_capture_this();

    return 0;
}


void lambda_capture_by_value(){
    int a = 123;
    auto f = [a] { cout << a << endl; }; 
    a = 321;
    f(); // output 123
}

void lambda_capture_by_reference(){
    int a = 123;
    auto f = [&a] { cout << a << endl; }; 
    a = 321;
    f(); // output 321
}

void lambda_capture_implicit(){
    int a = 123;
    auto f = [=] { cout << a << endl; }; // [=] =表示默认以 by value 传递外部所有变量
    a = 321;
    f(); // output 123

    auto f = [&] { cout << a << endl; };    // [&] &表示默认以 by reference 传递外部所有变量
    a = 321;
    f(); // output 321
}

void lambda_capture_hybrid(){
    int id = 0;
    int id1 = 1;
    int id2 = 2;
    int param = 3;

    // 一部分传引用,其余传值
    cout << "id=" << id << endl;
    auto f4 = [=, &id]() {       // =不可以放在&id后面
        cout << "id=" << id << endl;
        id++;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f4();

    // 一部分传值,其余传引用
    cout << "id=" << id << endl;
    auto f5 = [&, id]() {       // &不可以放在id后面
        cout << "id=" << id << endl;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f5();
}

class X {
private:
    int __x, __y;
public:
    X(int x, int y) : __x(x), __y(y) {}

    int operator()(int a) { return a; }

    int f() {
        // 下列 lambda 的语境是成员函数 X::f
        // 对于[=]或[&]的形式，lambda 表达式可以直接使用 this 指针
        return [&]() -> int {
            return operator()(this->__x + __y); // X::operator()(this->x + (*this).y)
            // 拥有类型 X*
        }();
    }


    int ff() {
        return [this]() {
            return this->__x;
        }();
    }
};

void lambda_capture_this(){
    // this 指针
    X x_(1, 2);
    cout << "x_.f()=" << x_.f() << endl;   // 1+2=3
    cout << "x_.ff()=" << x_.ff() << endl; // 1
}

class UnNamedLocalFunction {
private:
    int localVar;
public:
    UnNamedLocalFunction(int var) : localVar(var) {}

    bool operator()(int val) {
        return val == localVar;
    }
};

void lambda_unnamed_local_function(){
    // 下面lambda函数等价于上述的UnNamedLocalFunction
    int tobefound = 5;
    
    auto lambda1 = [tobefound](int val) {
        return val == tobefound;
    };
    bool b1 = lambda1(5);
    
    UnNamedLocalFunction lambda2(tobefound);
    bool b2 = lambda2(5);
    
    cout << b1 << " " << b2 << endl;
}