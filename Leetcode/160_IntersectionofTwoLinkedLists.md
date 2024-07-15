#Snippet 

# 两个链表是否相交

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240713142135.png)

这个问题有意思，也是力扣第 160 题「[相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)」函数签名如下：

```cpp
ListNode getIntersectionNode(ListNode headA, ListNode headB);
```

给你输入两个链表的头结点 `headA` 和 `headB`，这两个链表可能存在相交。

如果相交，你的算法应该返回相交的那个节点；如果没相交，则返回 null。

比如题目给我们举的例子，如果输入的两个链表如下图：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/4.png)

那么我们的算法应该返回 `c1` 这个节点。

# Solution 1

这个题直接的想法可能是用 `HashSet` 记录一个链表的所有节点，然后和另一条链表对比，但这就需要额外的空间。

如果不用额外的空间，只使用两个指针，你如何做呢？

难点在于，由于两条链表的长度可能不同，两条链表之间的节点无法对应：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/5.jpeg)

如果用两个指针 `p1` 和 `p2` 分别在两条链表上前进，并不能**同时**走到公共节点，也就无法得到相交节点 `c1`。

**解决这个问题的关键是，通过某些方式，让 `p1` 和 `p2` 能够同时到达相交节点 `c1`**。

所以，我们可以让 `p1` 遍历完链表 `A` 之后开始遍历链表 `B`，让 `p2` 遍历完链表 `B` 之后开始遍历链表 `A`，这样相当于「逻辑上」两条链表接在了一起。

如果这样进行拼接，就可以让 `p1` 和 `p2` 同时进入公共部分，也就是同时到达相交节点 `c1`：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/6.jpeg)

那你可能会问，如果说两个链表没有相交点，是否能够正确的返回 null 呢？

这个逻辑可以覆盖这种情况的，相当于 `c1` 节点是 null 空指针嘛，可以正确返回 null。

按照这个思路，可以写出如下代码：

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	    // p1 指向 A 链表头结点，p2 指向 B 链表头结点
	    ListNode *p1 = headA, *p2 = headB;
	    while (p1 != p2) {
	        // p1 走一步，如果走到 A 链表末尾，转到 B 链表
	        if (p1 == nullptr) p1 = headB;
	        else               p1 = p1->next;
	        // p2 走一步，如果走到 B 链表末尾，转到 A 链表
	        if (p2 == nullptr) p2 = headA;
	        else               p2 = p2->next;
	    }
	    return p1; // 返回交点
    }
};
```

这样，这道题就解决了，空间复杂度为 `O(1)`，时间复杂度为 `O(N)`。

# Solution 2

如果把两条链表首尾相连，那么「寻找两条链表的交点」的问题转换成了前面讲的「寻找环起点」的问题：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/7.png)

说实话我没有想到这种思路，不得不说这是一个很巧妙的转换！不过需要注意的是，这道题说不让你改变原始链表的结构，所以你把题目输入的链表转化成环形链表求解之后记得还要改回来，否则无法通过。

另外，还有读者提到，既然「寻找两条链表的交点」的核心在于让 `p1` 和 `p2` 两个指针能够同时到达相交节点 `c1`，那么可以通过预先计算两条链表的长度来做到这一点，具体代码如下：

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = 0, lenB = 0;
    // 计算两条链表的长度
    for (ListNode *p1 = headA; p1 != nullptr; p1 = p1->next) {
        lenA++;
    }
    for (ListNode *p2 = headB; p2 != nullptr; p2 = p2->next) {
        lenB++;
    }
    // 让 p1 和 p2 到达尾部的距离相同
    ListNode *p1 = headA, *p2 = headB;
    if (lenA > lenB) {
        // p1 先走过 lenA-lenB 步
        for (int i = 0; i < lenA - lenB; i++) {
            p1 = p1->next;
        }
    } else {
        // p2 先走过 lenB-lenA 步
        for (int i = 0; i < lenB - lenA; i++) {
            p2 = p2->next;
        }
    }
    // 看两个指针是否会相同，p1 == p2 时有两种情况：
    // 1、要么是两条链表不相交，他俩同时走到尾部空指针
    // 2、要么是两条链表相交，他俩走到两条链表的相交点
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;  
    }
    return p1;
}
```

虽然代码多一些，但是时间复杂度是还是 `O(N)`，而且会更容易理解一些。

总之，我的解法代码并不一定就是最优或者最正确的，鼓励大家在评论区多多提出自己的疑问和思考，我也很高兴和大家探讨更多的解题思路~