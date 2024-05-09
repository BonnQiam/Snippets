#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){
    list<int> l{1, 2, 3};
    
    //=================range-based for statement=========================
    // (1)
    cout << "range-based for statement (1)" << endl;
    for (auto elem:l) // pass by value
        cout << elem << endl;
    
    cout << "range-based for statement (2)" << endl;
    // C++2.0 之前 (2) 编译器会把(1)转换为(2)或(3)
    for (auto _pos = l.begin(), _end = l.end(); _pos != _end; ++_pos)
        cout << *_pos << " ";
    cout << endl;

    // (3)
    // C++2.0之后 全局函数 begin(container)与 end(container) 可以接受容器
    cout << "range-based for statement (3)" << endl;
    for (auto _pos = begin(l), _end = end(l); _pos != _end; ++_pos)
        cout << *_pos << " ";
    cout << endl;

    // (4)
    cout << "range-based for statement (4)" << endl;
    for (auto &elem:l) // pass by reference
        elem *= 3;

    // (5) 编译器会把(4)转换为(5)
    cout << "range-based for statement (5)" << endl;
    for (auto _pos = l.begin(), _end = l.end(); _pos != _end; ++_pos) {
        auto &elem = *_pos;
        elem *= 3;
    }
    cout << endl;

    return 0;
}