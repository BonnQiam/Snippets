#Snippet 

# 单链表的倒数第 k 个节点

从前往后寻找单链表的第 `k` 个节点很简单，一个 `for` 循环遍历过去就找到了，但是如何寻找从后往前数的第 `k` 个节点呢？

那你可能说，假设链表有 `n` 个节点，倒数第 `k` 个节点就是正数第 `n - k + 1` 个节点，不也是一个 `for` 循环的事儿吗？是的，但是算法题一般只给你一个 `ListNode` 头结点代表一条单链表，你*不能直接得出这条链表的长度* `n`，而需要先遍历一遍链表算出 `n` 的值，然后再遍历链表计算第 `n - k + 1` 个节点。也就是说，这个解法需要*遍历两次链表*才能得到出倒数第 `k` 个节点。

> 那么，我们能不能*只遍历一次链表*，就算出倒数第 `k` 个节点？可以做到的

这个解法就比较巧妙了，假设 `k = 2`，思路如下：

- 首先，我们先让一个指针 `p1` 指向链表的头节点 `head`，然后走 `k` 步：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/1.jpeg)

- 现在的 `p1`，只要再走 `n - k` 步，就能走到链表末尾的空指针了。趁这个时候，再用一个指针 `p2` 指向链表头节点 `head`：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/2.jpeg)

- 接下来就很显然了，让 `p1` 和 `p2` 同时向前走，`p1` 走到链表末尾的空指针时前进了 `n - k` 步，`p2` 也从 `head` 开始前进了 `n - k` 步，停留在第 `n - k + 1` 个节点上，即恰好停链表的倒数第 `k` 个节点上（因此实际上不需要知道 `n-k` 的值）：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/3.jpeg)

这样，只遍历了一次链表，就获得了倒数第 `k` 个节点 `p2`。上述逻辑的代码如下：

```cpp,nums,{10}
// 返回链表的倒数第 k 个节点
ListNode* findFromEnd(ListNode* head, int k) {
    ListNode* p1 = head;
    // p1 先走 k 步
    for (int i = 0; i < k; i++) {
        p1 = p1 -> next;
    }
    ListNode* p2 = head;
    // p1 和 p2 同时走 n - k 步
    while (p1 != nullptr) {
        p2 = p2 -> next;
        p1 = p1 -> next;
    }
    // p2 现在指向第 n - k + 1 个节点，即倒数第 k 个节点
    return p2;
}
```

当然，如果用 big O 表示法来计算时间复杂度，无论遍历一次链表和遍历两次链表的时间复杂度都是 `O(N)`，但上述这个算法更有技巧性。

# 删除链表的倒数第 N 个结点

很多链表相关的算法题都会用到这个技巧，比如说力扣第 19 题「[删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)」：


![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240711094005.png)

我们直接看解法代码：

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	    ListNode* dummy = new ListNode(-1);
	    dummy->next = head;
	    ListNode* x = findFromEnd(dummy, n + 1);
	    x->next = x->next->next;
	    return dummy->next;
    }
};
    
ListNode* findFromEnd(ListNode* head, int k) {
    // 代码见上文
}
```

- 这个逻辑就很简单了，要删除倒数第 `n` 个节点，就得获得倒数第 `n + 1` 个节点的引用，可以用我们实现的 `findFromEnd` 来操作（参考 [[19_RemoveNthNodeFromEndofList#单链表的倒数第 k 个节点]]）。
- 不过注意我们又使用了**虚拟头结点**的技巧，也是为了防止出现空指针的情况，比如说链表总共有 5 个节点，题目就让你删除倒数第 5 个节点，也就是第一个节点，那按照算法逻辑，应该首先找到倒数第 6 个节点。但第一个节点前面已经没有节点了，这就会出错。但有了我们虚拟节点 `dummy` 的存在，就避免了这个问题，能够对这种情况进行正确的删除。