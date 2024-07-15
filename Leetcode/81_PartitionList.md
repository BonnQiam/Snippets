#Snippet 

# 分隔链表

直接看下力扣第 86 题「[分隔链表](https://leetcode.cn/problems/partition-list/)」：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240710101222.png)

# Motivation

在合并两个有序链表 / [[21_MergeTwoSortedLists]] 时让你合二为一，而这里需要分解让你把原链表一分为二 —— 具体来说，我们可以把原链表分成两个小链表，一个链表中的元素大小都小于 `x`，另一个链表中的元素都大于等于 `x`，最后再把这两条链表接到一起，就得到了题目想要的结果。

# Solution

```cpp,nums,{37-42}
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
    ListNode *partition(ListNode *head, int x)
    {
        // 存放小于 x 的链表的虚拟头结点
        ListNode *dummy1 = new ListNode(-1);
        // 存放大于等于 x 的链表的虚拟头结点
        ListNode *dummy2 = new ListNode(-1);
        // p1, p2 指针负责生成结果链表
        ListNode *p1 = dummy1, *p2 = dummy2;
        // p 负责遍历原链表，类似合并两个有序链表的逻辑
        // 这里是将一个链表分解成两个链表
        ListNode *p = head;
        while (p != NULL)
        {
            if (p->val >= x)
            {
                p2->next = p;
                p2 = p2->next;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
            }
            // 不能直接让 p 指针前进，
            // p = p.next
            // 断开原链表中的每个节点的 next 指针
            ListNode *temp = p->next;
            p->next = NULL;
            p = temp;
        }
        // 连接两个链表
        p1->next = dummy2->next;

        return dummy1->next;
    }
};
```

> line 19 -24 —— 如果你不断开原链表中的每个节点的 `next` 指针，那么就会出错，因为结果链表中会包含一个环
> 
> 总的来说，如果我们需要把原链表的节点接到新链表上，而不是 `new` 新节点来组成新链表的话，那么*断开节点和原链表之间的链接可能是必要的*。那其实我们可以养成一个好习惯，但凡遇到这种情况，就把原链表的节点断开，这样就不会出错了

e.g.

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240712102108.png)

<center>
正确的情况
</center>

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240712102251.png)

<center>
出现环的错误情况
</center>

