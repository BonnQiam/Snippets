#include <iostream>
#include <functional> // provides std::function, which is a general-purpose polymorphic function wrapper.

#include <list>
#include <algorithm>
#include <vector>


using namespace std;

void test_auto_1();
void test_auto_2();
void test_auto_3();

int main() {
    //test_auto_1();
    //test_auto_2();
    test_auto_3();

    return 0;
}

void test_auto_1(){
    auto ll1 = [](int x) -> int {
        return x + 10;
    };
    // lambda 匿名函数
    function<int(int x)> ll = [](int x) -> int {
        return x + 10;
    };

    cout << ll1(10) << endl;
    cout << ll(10) << endl;
}

void test_auto_2(){
    list<int> l{1, 2, 3};
    list<int>::iterator iterator;

    iterator = find(l.begin(), l.end(), 10);
    auto ite = find(l.begin(), l.end(), 11);    // auto 关键字

    // check if iterator == ite
    if (iterator == ite)
        cout << "iterator == ite" << endl;
    else
        cout << "iterator != ite" << endl;
}

void test_auto_3(){
    vector<string> vs = {"hello", "world"};

    // 加了 explicit就不能转了 error
    //    for (const C &elem:vs) {
    //    }
    // auto 不利：降低代码可读性、可能得不到你预想的类型、配合 decltype 有意想不到的结果
    // auto可能得不到你预想的类型，如 vector<bool>[]的返回类型。
    
    vector<bool> v(true);
    
    auto var = v.at(0);
    cout<< typeid(var).name()<<endl;
}