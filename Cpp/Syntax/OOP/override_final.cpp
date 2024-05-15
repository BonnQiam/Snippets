#include <iostream>

void test_override();
void test_final();

int main(){
    return 0;
}

void test_override(){
    class Base {
    public:
        virtual void Show(int x); // 虚函数
    };

    class Derived : public Base {
    public:
        //virtual void Show(int x) const override; // error: const 属性不一样，新的虚函数
        virtual void Show(int x) override;
    };
}

void test_final(){
    class Base {
    public:
        virtual void Show(int x) final; // 虚函数
    };

    class Derived : public Base {
    public:
        //virtual void Show(int x) override; //error: 重写提示错误  
    };
}