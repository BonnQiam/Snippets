#Snippet 

# 合并两个有序链表

这是最基本的链表技巧，力扣第 21 题「[合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)」就是这个问题：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240710100713.png)

给你输入两个有序链表，请你把他俩合并成一个新的有序链表，函数签名如下：

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
```

# Motivation

基于 `while` 循环每次比较 `p1` 和 `p2` 的大小，把较小的节点接到结果链表上，看如下 GIF：

![](https://labuladong.online/algo/images/%E9%93%BE%E8%A1%A8%E6%8A%80%E5%B7%A7/1.gif)

形象地理解，这个算法的逻辑类似于拉拉链，`l1, l2` 类似于拉链两侧的锯齿，指针 `p` 就好像拉链的拉索，将两个有序链表合并；或者说这个过程像蛋白酶合成蛋白质，`l1, l2` 就好比两条氨基酸，而指针 `p` 就好像蛋白酶，将氨基酸组合成蛋白质。

# Solution

> 代码中还用到一个链表的算法题中是很常见的「虚拟头结点」技巧 / [[单链表#虚拟头尾节点]]，也就是 `dummy` 节点

你可以试试，如果不使用 `dummy` 虚拟节点，代码会复杂一些，需要额外处理指针 `p` 为空的情况。而有了 `dummy` 节点这个占位符，可以避免处理空指针的情况，降低代码的复杂性。

```cpp
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
// 两个链表的节点数目范围是 [0, 50]
// -100 <= Node.val <= 100
// list1 和 list2 均按 非递减顺序 排列

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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 虚拟头结点
        ListNode *dummy = new ListNode(-1), *p = dummy;
        ListNode *p1 = l1, *p2 = l2;

        while (p1 != NULL && p2 != NULL)
        {

            // 比较 p1 和 p2 两个指针
            // 将值较小的的节点接到 p 指针
            if (p1->val > p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
            }
            // p 指针不断前进
            p = p->next;
        }

        if (p1 != NULL)
        {
            p->next = p1;
        }

        if (p2 != NULL)
        {
            p->next = p2;
        }

        return dummy->next;
    }
};
```