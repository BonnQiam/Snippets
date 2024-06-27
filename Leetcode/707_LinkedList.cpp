/*
你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针 / 引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

*/
#include <string>
#include <stdexcept>

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val): val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;


    bool isPositionIndex(int index) {
        return index >= 0 && index <= size;
    }

    bool isElementIndex(int index) {
        return index >= 0 && index < size;
    }

public:
    MyLinkedList() {
        head = new Node(0);
        tail = head;
        size = 0;
    }

    //? add ~MyLinkedList() to delete all nodes
    ~MyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    int get(int index) {

        if(isElementIndex(index) == false) {
            return -1;
        }

        Node* current = head->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;// head is always a sentinel node

        // if size is 0, tail should be updated
        if (size == 0) {
            tail = newNode;
        }

        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (isPositionIndex(index) == false) {
            return;
        }

        // if add at tail
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (isElementIndex(index) == false) {
            return;
        }

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* toDelete = prev->next;
        prev->next = toDelete->next;

        // if delete the last element, update tail
        if (index == size - 1) {
            tail = prev;
        }

        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */