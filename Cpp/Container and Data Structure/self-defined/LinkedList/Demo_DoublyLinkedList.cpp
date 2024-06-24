#include <vector>
#include <iostream>

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

DoublyListNode* createDoublyLinkedList(std::vector<int>& arr) {
    // 当数组为空或者长度为0, 返回nullptr
    if (arr.empty()) {
        return nullptr;
    }
    DoublyListNode* head = new DoublyListNode(arr[0]);
    DoublyListNode* cur = head;
    // for 循环迭代创建双链表
    for (int i = 1; i < arr.size(); i++) {
        DoublyListNode* newNode = new DoublyListNode(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
};

void test_TraverseDoublyLinkedList();
void test_AddFirst();
void test_AddLast();
void test_InsertAfter(int index, int val);
void test_DeleteNode(int index);
void test_DeleteFirst();
void test_DeleteLast();

int main() {
    //test_TraverseDoublyLinkedList();
    //test_AddFirst();
    //test_AddLast();
    //test_InsertAfter(2, 6);
    //test_DeleteNode(2);
    test_DeleteFirst();
    std::cout << std::endl;
    test_DeleteLast();

    return 0;
}

void test_TraverseDoublyLinkedList() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }

    DoublyListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    std::cout << std::endl;

    for (DoublyListNode* cur = tail; cur != nullptr; cur = cur->prev) {
        std::cout << cur->val << " -> ";
    }
}

void test_AddFirst() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    DoublyListNode* newNode = new DoublyListNode(0);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }
}

void test_AddLast() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    DoublyListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    DoublyListNode* newNode = new DoublyListNode(6);
    tail->next = newNode;
    newNode->prev = tail;

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }
}

void test_InsertAfter(int index, int val) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    DoublyListNode* cur = head;
    for (int i = 0; i < index-1; i++) {
        cur = cur->next;
    }

    DoublyListNode* newNode = new DoublyListNode(val);
    newNode->next = cur->next;
    cur->next->prev = newNode;
    cur->next = newNode;
    newNode->prev = cur;

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }
}

void test_DeleteNode(int index) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    DoublyListNode* cur = head;
    for (int i = 0; i < index-2; i++) {
        cur = cur->next;
    }

    DoublyListNode* delNode = cur->next;
    cur->next = delNode->next;
    delNode->next->prev = cur;
    delete delNode;

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }
}

void test_DeleteFirst() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    DoublyListNode* delNode = head;
    head = head->next;
    head->prev = nullptr;
    delete delNode;

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }
}

void test_DeleteLast() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedList(arr);

    DoublyListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    DoublyListNode* delNode = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete delNode;

    for (DoublyListNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val << " -> ";
    }
}