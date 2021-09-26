/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
    ListNode *swapPairs(ListNode *head)
    {
        //链表没有结点或者只有一个结点
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        //以1和2、3和4这样两两分组
        //定义第二个结点作为newHead
        ListNode *newHead = head->next;

        //递归，完成后面组的交换
        head->next = swapPairs(newHead->next);

        //2后面接上1，完成第一组的交换
        newHead->next = head;
        return newHead;
    }
};

// @lc code=end
