#include <iostream>
#include <stdexcept>

template <typename E>
class MyLinkedList {
private:
    // Node structure for the doubly linked list
    struct Node {
        E val;
        Node* next;
        Node* prev;
        Node(E val) : val(val), next(nullptr), prev(nullptr) {}
    };

    // Sentinel nodes for head and tail
    Node* head;
    Node* tail;
    int size;

    // Check if the index is within the valid range
    void checkElementIndex(int index) {
        if (!isElementIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    // Check if the index is a valid position for insertion
    void checkPositionIndex(int index) {
        if (!isPositionIndex(index))
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }

    // Check if the index is within the range of existing elements
    bool isElementIndex(int index) {
        return index >= 0 && index < size;
    }

    // Check if the index is within the range of valid positions for insertion
    bool isPositionIndex(int index) {
        return index >= 0 && index <= size;
    }

    // Get the node at the specified index
    Node* getNode(int index) {
        checkElementIndex(index);
        Node* p = head->next;
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        return p;
    }

public:
    // Constructor to initialize the linked list
    MyLinkedList() {
        head = new Node(E()); // Sentinel head node
        tail = new Node(E()); // Sentinel tail node
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Destructor to clean up allocated memory
    ~MyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Add an element at the end of the list
    void addLast(E e) {
        Node* x = new Node(e);
        Node* temp = tail->prev;
        temp->next = x;
        x->prev = temp;
        x->next = tail;
        tail->prev = x;
        ++size;
    }//complexity: O(1)

    // Add an element at the beginning of the list
    void addFirst(E e) {
        Node* x = new Node(e);
        Node* temp = head->next;
        temp->prev = x;
        x->next = temp;
        head->next = x;
        x->prev = head;
        ++size;
    }//complexity: O(1)

    // Add an element at the specified index
    void add(int index, E element) {
        checkPositionIndex(index);
        if (index == size) {
            addLast(element);
            return;
        }
        Node* p = getNode(index);
        Node* temp = p->prev;
        Node* x = new Node(element);
        p->prev = x;
        temp->next = x;
        x->prev = temp;
        x->next = p;
        ++size;
    }//complexity: O(n)

    // Remove the first element from the list
    E removeFirst() {
        if (size < 1) {
            throw std::out_of_range("No elements to remove");
        }
        Node* x = head->next;
        Node* temp = x->next;
        head->next = temp;
        temp->prev = head;
        E val = x->val;
        delete x;
        --size;
        return val;
    }//complexity: O(1)

    // Remove the last element from the list
    E removeLast() {
        if (size < 1) {
            throw std::out_of_range("No elements to remove");
        }
        Node* x = tail->prev;
        Node* temp = x->prev;
        tail->prev = temp;
        temp->next = tail;
        E val = x->val;
        delete x;
        --size;
        return val;
    }//complexity: O(1)

    // Remove the element at the specified index
    E remove(int index) {
        checkElementIndex(index);
        Node* x = getNode(index);
        Node* prev = x->prev;
        Node* next = x->next;
        prev->next = next;
        next->prev = prev;
        E val = x->val;
        delete x;
        --size;
        return val;
    }// complexity: O(n)

    // Get the element at the specified index
    E get(int index) {
        checkElementIndex(index);
        Node* p = getNode(index);
        return p->val;
    }// complexity: O(n)

    // Get the first element
    E getFirst() {
        if (size < 1) {
            throw std::out_of_range("No elements in the list");
        }
        return head->next->val;
    }// complexity: O(1)

    // Get the last element
    E getLast() {
        if (size < 1) {
            throw std::out_of_range("No elements in the list");
        }
        return tail->prev->val;
    }// complexity: O(1)

    // Set the element at the specified index
    E set(int index, E val) {
        checkElementIndex(index);
        Node* p = getNode(index);
        E oldVal = p->val;
        p->val = val;
        return oldVal;
    }// complexity: O(n)

    // Get the size of the list
    int size() const {
        return size;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Display the elements of the list
    void display() const {
        std::cout << "size = " << size << std::endl;
        for (Node* p = head->next; p != tail; p = p->next) {
            std::cout << p->val << " -> ";
        }
        std::cout << "null" << std::endl;
        std::cout << std::endl;
    }
};