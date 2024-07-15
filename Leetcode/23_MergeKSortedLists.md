#Snippet 

# 合并 K 个升序链表

看下力扣第 23 题「[合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)」：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240710102807.png)

函数签名如下

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists);
```

合并 `k` 个有序链表的逻辑类似合并两个有序链表，难点在于，如何快速得到 `k` 个节点中的最小节点，接到结果链表上？

# Solution

> 使用到 [优先级队列（二叉堆）](https://labuladong.online/algo/data-structure-basic/binary-heap-implement/)  / [[二叉堆]] 这种数据结构，把链表节点放入一个最小堆，就可以每次获得 `k` 个节点中的最小节点：

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	    if (lists.empty()) return nullptr;
	    // 虚拟头结点
	    ListNode* dummy = new ListNode(-1);
	    ListNode* p = dummy;
	    // 优先级队列，最小堆
	    priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(
	        [] (ListNode* a, ListNode* b) { return a->val > b->val; });
	    // 将 k 个链表的头结点加入最小堆
	    for (auto head : lists) {
	        if (head != nullptr) {
	            pq.push(head);
	        }
	    }
	
	    while (!pq.empty()) {
	        // 获取最小节点，接到结果链表中
	        ListNode* node = pq.top();
	        pq.pop();
	        p->next = node;
	        if (node->next != nullptr) {
	            pq.push(node->next);
	        }
	        // p 指针不断前进
	        p = p->next;
	    }
	    return dummy->next;
    }
};
```

## 算法复杂度

这个算法是面试常考题，它的时间复杂度是多少呢？
- 优先队列 `pq` 中的元素个数最多是 `k`，所以一次 `poll` 或者 `add` 方法的时间复杂度是 `O(logk)`；
- 所有的链表节点都会被加入和弹出 `pq`，*所以算法整体的时间复杂度是 $O(N\log k)$，其中  $k$ 是链表的条数，$N$ 是这些链表的节点总数*。
