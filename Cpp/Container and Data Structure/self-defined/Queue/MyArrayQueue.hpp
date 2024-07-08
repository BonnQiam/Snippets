#ifndef CYCLEARRAY_HPP

#define CTCLEARRAY_HPP
#include "../Array/CycleArray.hpp"

#endif

template <typename E>
class MyArrayQueue {

private:
    CycleArray<E> array;
public:

    MyArrayQueue() { array = CycleArray<E>(); }

    void enqueue(const E& e) { array.addLast(e); }

    E dequeue() { return array.removeFirst(); }

    E getFront() { return array.getFirst(); }

    int getSize() { return array.getSize(); }

    bool isEmpty() { return array.isEmpty(); }
};