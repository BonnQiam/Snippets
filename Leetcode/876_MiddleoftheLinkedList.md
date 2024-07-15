#Snippet 

# 链表的中间节点

力扣第 876 题「[链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/)」就是这个题目，问题的关键也在于我们无法直接得到单链表的长度 `n`，常规方法也是先遍历链表计算 `n`，再遍历一次得到第 `n / 2` 个节点，也就是中间节点。

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240713140900.png)

# Solution

如果想一次遍历就得到中间节点，也需要耍点小聪明，使用「**快慢指针**」的技巧：我们让两个指针 `slow` 和 `fast` 分别指向链表头结点 `head`。*每当慢指针 `slow` 前进一步，快指针 `fast` 就前进两步，这样，当 `fast` 走到链表末尾时，`slow` 就指向了链表中点*

```cpp
ListNode* middleNode(ListNode* head) {
    // 快慢指针初始化指向 head
    ListNode* slow = head;
    ListNode* fast = head;
    // 快指针走到末尾时停止
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针走一步，快指针走两步
        slow = slow->next;
        fast = fast->next->next;
    }
    // 慢指针指向中点
    return slow;
}
```

需要注意的是，如果链表长度为偶数，也就是说中点有两个的时候，我们这个解法返回的节点是靠后的那个节点。

> 另外，这段代码稍加修改就可以直接用到判断链表成环的算法题上 —— [[LinkedListCycle]]