#include <iostream>

using namespace std;

int main() {
    int id = 0;
    // without mutable, the compiler will complain that id is read-only
    auto f = [id]()mutable {
        cout << "id=" << id << endl;
        ++id;
    };

    id = 42;
    f();    // 0
    f();    // 1
    f();    // 2
    cout << id << endl;

    // 上述lambda就相当于
//    class Functor {
//    private:
//        int id;
//    public:
//        void operator() {
//            cout << "id=" << id << endl;
//            ++id;
//        }
//    };
//    Functor f;
}