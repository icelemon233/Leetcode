/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
* Definition for singly-linked list.
* struct ListNode
* {
*    int val;
*    struct ListNode *next;
* };
**/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        //定义返回的单链表
        ListNode l3;

        //定义头指针
        ListNode *p = &l3;

        //定义相加结果及进位（复用）
        int count = 0;

        //当l1不空，l2不空，最后一项非进位时（类似9999+1的情况)
        while (l1 || l2 || count)
        {
            //l1不空或l2不空都进行计算
            if (l1)
            {
                count += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                count += l2->val;
                l2 = l2->next;
            }

            //单链表l3新建结点
            p = p->next = new ListNode();
            p->val = count % 10;

            //若count>10表明有进位，下次count必为1
            count /= 10;
        }
        return l3.next;
    }
};
