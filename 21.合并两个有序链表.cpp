/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //新建一个虚拟的头结点，并复制一份作为可移动的指针
        ListNode *preNode = new ListNode;
        // prev的作用：代表了当前新链表的最后一个结点，新建这样一个结点保留了l1和l2，便于操作
        ListNode *prev = preNode;
        while (l1 != nullptr && l2 != nullptr)
        {
            //l1比l2小，所以prev的next指针指向l1(此时prev是最后一个结点的前一个)，然后l1顺位指向下一个结点
            //else同理
            if (l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            //每次检查结束后，prev就会是真正的“最后一个结点”
            prev = prev->next;
        }
        //注意跳出循环后，那个短链表指针已经指到nullptr处
        //检查是哪个链表还未合并完，直接指向即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preNode->next;
    }
};
// @lc code=end
