#Snippet 

# 环形链表 I

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240713141316.png)

## Solution

> 判断链表是否包含环属于经典问题了，解决方案也是用**快慢指针**：

每当慢指针 `slow` 前进一步，快指针 `fast` 就前进两步。

如果 `fast` 最终能正常走到链表末尾，说明链表中没有环；如果 `fast` 走着走着竟然和 `slow` 相遇了，那肯定是 `fast` 在链表中转圈了，说明链表中含有环 —— 只需要把寻找链表中点的代码 / [[876_MiddleoftheLinkedList]] 稍加修改就行了：

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 初始化快慢指针，指向头结点
	    ListNode* slow = head;
	    ListNode* fast = head;
	    // 快指针到尾部时停止
	    while (fast && fast->next) {
	        // 慢指针走一步，快指针走两步
	        slow = slow->next;
	        fast = fast->next->next;
	        // 快慢指针相遇，说明含有环
	        if (slow == fast) {
	            return true;
	        }
	    }
	    // 不包含环
	    return false;
    }
};
```

# 环形链表 II

> 力扣第 142 题「[环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)」：如果链表中含有环，如何计算这个环的起点？

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240713141831.png)

为了避免读者迷惑，举个例子，环的起点是指下面这幅图中的节点 2：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/circularlinkedlist.png)

## Solution

这里先直接看一下寻找环起点的解法代码：

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
	    ListNode* slow = head;
	    while (fast != nullptr && fast->next != nullptr) {
	        fast = fast->next->next;
	        slow = slow->next;
	        if (fast == slow) break;
	
	
	    }
	    // 上面的代码类似 hasCycle 函数
	    if (fast == nullptr || fast->next == nullptr) {
	        // fast 遇到空指针说明没有环
	        return nullptr;
	    }
	
	    // 重新指向头结点
	    slow = head;
	
	
	    // 快慢指针同步前进，相交点就是环起点
	    while (slow != fast) {
	        fast = fast->next;
	        slow = slow->next;
	    }
	    return slow;
    }
};
```

> 可以看到，当快慢指针相遇时，让其中任一个指针指向头节点，然后让它俩以相同速度前进，再次相遇时所在的节点位置就是环开始的位置。

为什么要这样呢？这里简单说一下其中的原理。我们假设快慢指针相遇时，慢指针 `slow` 走了 `k` 步，那么快指针 `fast` 一定走了 `2k` 步：

![](https://labuladong.online/algo/images/%E5%8F%8C%E6%8C%87%E9%92%88/3.jpeg)

`fast` 一定比 `slow` 多走了 `k` 步，这多走的 `k` 步其实就是 `fast` 指针在环里转圈圈，所以 `k` 的值就是环长度的「整数倍」。

假设相遇点距环的起点的距离为 `m`，那么结合上图的 `slow` 指针，环的起点距头结点 `head` 的距离为 `k - m`，也就是说如果从 `head` 前进 `k - m` 步就能到达环起点。

巧的是，如果从相遇点继续前进 `k - m` 步，也恰好到达环起点。因为结合上图的 `fast` 指针，从相遇点开始走k步可以转回到相遇点，那走 `k - m` 步肯定就走到环起点了：

![](https://labuladong.online/algo/images/%E5%8F%8C%E6%8C%87%E9%92%88/2.jpeg)

所以，只要我们把快慢指针中的任一个重新指向 `head`，然后两个指针同速前进，`k - m` 步后一定会相遇，相遇之处就是环的起点了。