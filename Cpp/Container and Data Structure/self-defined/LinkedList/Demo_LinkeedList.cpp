#include <vector>
#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 输入一个数组，转换为一条单链表
ListNode* createLinkedList(std::vector<int>& arr) 
{
    if (arr.empty()) 
    {
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) 
    {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
};

void test_TraverseLinkedList();
void test_AddFirst();
void test_AddLast();
void test_InsertNode(int index, int val);
void test_DeleteNode(int index);
void test_DeleteFirst();
void test_DeleteLast();

int main(){
    //test_TraverseLinkedList();
    //test_AddFirst();
    //test_AddLast();
    //test_InsertNode(2, 6);
    //test_DeleteNode(2);
    //test_DeleteFirst();
    test_DeleteLast();

    return 0;
}

void test_TraverseLinkedList()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}

void test_AddFirst()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    head = newHead;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}

void test_AddLast()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    ListNode* newTail = new ListNode(6);
    ListNode* cur = head;
    while (cur->next != nullptr) 
    {
        cur = cur->next;
    }
    cur->next = newTail;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}

void test_InsertNode(int index, int val)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    ListNode* newNode = new ListNode(val);
    ListNode* pre = head;
    for (int i = 0; i < index - 1; i++) 
    {
        pre = pre->next;
    }
    newNode->next = pre->next;
    pre->next = newNode;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}

void test_DeleteNode(int index)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    ListNode* pre = head;
    for (int i = 0; i < index - 1; i++) 
    {
        pre = pre->next;
    }
    ListNode* delNode = pre->next;
    pre->next = delNode->next;
    delete delNode;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}

void test_DeleteFirst()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    ListNode* delNode = head;
    head = head->next;
    delete delNode;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}

void test_DeleteLast()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    ListNode* pre = head;
    while (pre->next->next != nullptr) 
    {
        pre = pre->next;
    }
    ListNode* delNode = pre->next;
    pre->next = nullptr;
    delete delNode;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) 
    {
        std::cout << cur->val << " -> ";
    }
}