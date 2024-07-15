#Snippet 

扩展参考 [[26_RemoveDuplicatesfromSortedArray]]

# 删除排序链表中的重复元素

力扣第 83 题「[删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)」，如果给你一个有序的单链表，如何去重呢？

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240715092940.png)

# Solution

其实和数组去重 / [[26_RemoveDuplicatesfromSortedArray]] 是一模一样的，唯一的区别是把数组赋值操作变成操作指针而已，你对照着之前的代码来看：

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
	ListNode* deleteDuplicates(ListNode* head) {
	    if (head == nullptr) return nullptr;
	    ListNode* slow = head;  // 当前元素
	    ListNode* fast = head;  // 下一个元素
	    while (fast != nullptr) {
	        if (fast->val != slow->val) {
	            // 当前元素的下一个元素设置为下一个不相等的元素
	            slow->next = fast;
	            // 当前元素向后移动
	            slow = slow->next;
	        }
	        // 下一个元素向后移动
	        fast = fast->next;
	    }
	    // 断开与后面重复元素的连接
	    slow->next = nullptr;
	    return head;
	}
};
```

算法执行的过程请看下面这个 GIF：

![](https://labuladong.online/algo/images/%E6%95%B0%E7%BB%84%E5%8E%BB%E9%87%8D/2.gif)

> 注 —— 这里可能有读者会问，链表中那些重复的元素并没有被删掉，就让这些节点在链表上挂着，合适吗？
> 
> 这就要探讨不同语言的特性了，像 Java/Python 这类带有垃圾回收的语言，可以帮我们自动找到并回收这些「悬空」的链表节点的内存，而像 C++ 这类语言没有自动垃圾回收的机制，确实需要我们编写代码时手动释放掉这些节点的内存。
> 
> 不过话说回来，就算法思维的培养来说，我们只需要知道这种快慢指针技巧即可。