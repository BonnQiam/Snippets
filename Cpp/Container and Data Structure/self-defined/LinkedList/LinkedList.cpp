#include <iostream>
#include <stdexcept>

template <typename E>
class MyLinkedList2 {
private:
    struct Node {
        E val;
        Node* next;

        Node(E val) : val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    void checkElementIndex(int index) const {
        if (!isElementIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    void checkPositionIndex(int index) const {
        if (!isPositionIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    bool isElementIndex(int index) const {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) const {
        return index >= 0 && index <= size;
    }

    Node* getNode(int index) const {
        Node* p = head->next;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }

public:
    // size equals to 0 because head is a sentinel node
    MyLinkedList2() : head(new Node(E())), tail(head), size(0) {}

    ~MyLinkedList2() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addFirst(const E& e) {
        Node* newNode = new Node(e);
        newNode->next = head->next;
        head->next = newNode;// head is always a sentinel node
        if (size == 0) {
            tail = newNode;
        }
        size++;
    }

    void addLast(const E& e) {
        Node* newNode = new Node(e);
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void add(int index, const E& element) {
        checkPositionIndex(index);

        if (index == size) {
            addLast(element);
            return;
        }

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(element);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    E removeFirst() {
        if (isEmpty()) {
            throw std::out_of_range("No such element");
        }
        Node* first = head->next;
        head->next = first->next;
        if (size == 1) {
            tail = head;
        }
        E val = first->val;
        delete first;
        size--;
        return val;
    }

    E removeLast() {
        if (isEmpty()) {
            throw std::out_of_range("No such element");
        }

        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        E val = tail->val;
        delete tail;
        tail = prev;
        tail->next = nullptr;
        size--;
        return val;
    }

    E remove(int index) {
        checkElementIndex(index);

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
        if (index == size - 1) {
            tail = prev;
        }
        E val = nodeToRemove->val;
        delete nodeToRemove;
        size--;
        return val;
    }

    E getFirst() const {
        if (isEmpty()) {
            throw std::out_of_range("No such element");
        }
        return head->next->val;
    }

    E getLast() const {
        if (isEmpty()) {
            throw std::out_of_range("No such element");
        }
        return getNode(size - 1)->val;
    }

    E get(int index) const {
        checkElementIndex(index);
        return getNode(index)->val;
    }

    E set(int index, const E& element) {
        checkElementIndex(index);
        Node* p = getNode(index);

        E oldVal = p->val;
        p->val = element;

        return oldVal;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};