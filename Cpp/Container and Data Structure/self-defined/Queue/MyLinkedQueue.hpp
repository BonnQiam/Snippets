#ifndef DOUBLYLINKEDLIST_HPP

#define DOUBLYLINKEDLIST_HPP
#include "../LinkedList/DoublyLinkedList.hpp"

#endif

template <typename E>
class MyLinkedQueue {

private:
    MyLinkedList<E> list;

public:
    MyLinkedQueue() {list = MyLinkedList<E>();}

    void addFirst(const E& e) {list.addFirst(e);}// complexity: O(1)
    void addLast(const E& e) {list.addLast(e);}// complexity: O(1)

    void removeFirst() {
        if (list.isEmpty())
            throw std::out_of_range("Queue is empty");
        list.removeFirst();
    }// complexity: O(1)

    void removeLast() {
        if (list.isEmpty())
            throw std::out_of_range("Queue is empty");
        list.removeLast();
    }// complexity: O(1)

    E peekFirst() {
        if (list.isEmpty())
            throw std::out_of_range("Queue is empty");
        return list.getFirst();
    }// complexity: O(1)

    E peekLast() {
        if (list.isEmpty())
            throw std::out_of_range("Queue is empty");
        return list.getLast();
    }// complexity: O(1)

};