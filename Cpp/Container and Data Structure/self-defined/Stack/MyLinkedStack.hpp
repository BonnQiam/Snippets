#ifndef DOUBLYLINKEDLIST_HPP

#define DOUBLYLINKEDLIST_HPP
#include "../LinkedList/DoublyLinkedList.hpp"

#endif


template <typename E>
class MyLinkedStack {
private:
    MyLinkedList<E> list;
public:
    MyLinkedStack() {list = MyLinkedList<E>();}

    void push(const E& e) {list.addFirst(e);}

    E pop() {
        if (list.isEmpty())
            throw std::out_of_range("Stack is empty");
        return list.removeLast();
    }

    E peek() {
        if (list.isEmpty())
            throw std::out_of_range("Stack is empty");
        return list.getLast();
    }

    int size() {return list.size();}
};