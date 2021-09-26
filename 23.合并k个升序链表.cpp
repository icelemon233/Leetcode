/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
#include <vector>
using namespace std;
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int listslength = lists.size();
        ListNode *reslist = nullptr;
        for (int i = 0; i < listslength; i++)
        {
            reslist = mergeTwoLists(reslist, lists[i]);
        }
        return reslist;
    }

    //这个方法可以照搬 21.合成两个有序链表 来使用
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //一旦有哪个链表元素遍历完了，直接返回另外一个链表即可
        if (l1 == nullptr || l2 == nullptr)
        {
            return l1 ? l1 : l2;
        }
        //l1比l2小，所以下一个元素应该从 "l1->next" 和 "l2" 这两个结点开头的两个链表里选
        //意思很明显了，就是l1要顺位指向下一个结点
        //else同理
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        //最后不需要再写return，上面两端if的判断说明：如果l1->val < l2->val，最后一定是执行return l1
        //否则，最后一定是执行return l2，均符合题目要求（小的结点当头头）
    }
};
// @lc code=end
