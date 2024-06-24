#include <iostream>
#include <vector>

using namespace std;

void what_is_rvalue();
void rvalue_reference_1();

int main(){
    //what_is_rvalue();
    rvalue_reference_1();

    return 0;
}

int foo() { return 5; }

void what_is_rvalue(){
    string s1("hello");
    string s2("world");
    
    s1 + s2 = s2;// means (s1 + s2) = s2, which is invalid
    // s1 + s2 is an rvalue, which is a temporary object

    string() = "ok";// means string() = "ok", which is invalid
    // string() is an rvalue, which is a temporary object

    int x = foo();// means x = foo(), which is valid
    // foo() is an rvalue, which is a temporary object

//    int *p=&foo(); //error!  Rvalue不可以取地址
//    foo()=7;  // error
}


// 判断调用哪一个函数
void process(int &i) {
    cout << "Left value" << endl;
}

void process(int &&i) {
    cout << "Right value" << endl;
}

void rvalue_reference_1(){
    int aa = 1;
    process(aa);            // L
    process(1);             // R
    process(move(aa));      // R
}