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

using namespace std;
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        //定义一个头指针指向头结点
        ListNode *preHead = new ListNode();
        preHead->next = head;

        //定义中间结点
        ListNode *temp = preHead;

        //还是以1和2、3和4这样两两分组
        //后两个结点均不是空
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            //p是该组第一个结点，q是该组第二个结点
            ListNode *p = temp->next;
            ListNode *q = temp->next->next;
            //temp指向该组第二个结点
            temp->next = q;

            //p（第一个结点）的下一个结点应该是q的下一个结点（也就是第二组的第一个结点，不要破坏下一组的结构）
            p->next = q->next;
            //q（第二个结点）的下一个结点就是他前面的结点p
            q->next = p;
            //p（第一个结点）此时已经换成第二个结点，此时temp指向p，那么temp->next就可以指向下一组结点
            temp = p;
        }

        //返回一开始的头结点即可
        return preHead->next;
    }
};

// @lc code=end
