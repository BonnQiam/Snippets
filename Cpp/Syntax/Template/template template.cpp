#include <iostream>
#include <list>

using namespace std;
// A template template parameter is a template parameter for a class template that is itself a class template.
template<typename T,
        template<typename U> class Container>
class XCls {
private:
    Container<T> c;
};
// c of XCls is a container of T, and the container is specified by the template template parameter Container.

// alias template
template<typename T>
using Lst = list<T>;

int main() {
//    XCls<string, list> mylist1;   // error
    XCls<string, Lst> mylist2;

    return 0;
}
