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
