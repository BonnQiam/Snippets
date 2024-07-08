#ifndef CYCLEARRAY_HPP

#define CTCLEARRAY_HPP
#include "../Array/CycleArray.hpp"

#endif

template <typename E>
class MyArrayDeque
{

private:
    CycleArray<E> array;

public:
    MyArrayDeque() { array = CycleArray<E>(); }

    void addFirst(const E &e) { array.addFirst(e); }//complexity: O(1) amortized

    void addLast(const E &e) { array.addLast(e); }//complexity: O(1) amortized

    E removeFirst() { return array.removeFirst(); }//complexity: O(1) amortized

    E removeLast() { return array.removeLast(); }//complexity: O(1) amortized

    E getFirst() { return array.getFirst(); }//complexity: O(1)

    E getLast() { return array.getLast(); }//complexity: O(1)

    int getSize() { return array.getSize(); }

    bool isEmpty() { return array.isEmpty(); }
};