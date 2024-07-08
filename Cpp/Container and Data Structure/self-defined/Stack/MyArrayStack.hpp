#ifndef MYARRAYSTACK_HPP

#define MYARRAYSTACK_HPP
#include "../Array/MyArrayList.hpp"

#endif // MYARRAYSTACK_HPP

template <typename E>
class MyArrayStack {

private:
    MyArray<E> array;

public:

    MyArrayStack() { array = MyArray<E>(); }

    void push(const E& e) { array.addLast(e); }

    E pop() { return array.removeLast(); }

    E peek() { return array.getLast(); }

    int getSize() { return array.getSize(); }
};