#ifndef DOUBLYLINKEDLIST_HPP

#define DOUBLYLINKEDLIST_HPP
#include "../LinkedList/DoublyLinkedList.hpp"

#endif

template <typename E>
class MyLinkedDeque {
private:
    MyDoublyLinkedList<E> list;
public:
    MyLinkedDeque() {list = MyDoublyLinkedList<E>();}

    void addFirst(const E& e) {list.addFirst(e);}// complexity: O(1)
    void addLast(const E& e) {list.addLast(e);}// complexity: O(1)

    void removeFirst() {
        if (list.isEmpty())
            throw std::out_of_range("Deque is empty");
        list.removeFirst();
    }// complexity: O(1)

    void removeLast() {
        if (list.isEmpty())
            throw std::out_of_range("Deque is empty");
        list.removeLast();
    }// complexity: O(1)
    
    E peekFirst() {
        if (list.isEmpty())
            throw std::out_of_range("Deque is empty");
        return list.getFirst();
    }// complexity: O(1)

    E peekLast() {
        if (list.isEmpty())
            throw std::out_of_range("Deque is empty");
        return list.getLast();
    }// complexity: O(1)
};