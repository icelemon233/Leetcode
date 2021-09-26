/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //新建一个头指针保存头结点
        ListNode *headpointer = new ListNode();
        headpointer->next = head;

        //快慢指针
        ListNode *fastptr = head;
        ListNode *slowptr = headpointer;

        //快指针先移到 N 的位置，此时快慢指针相隔就是N个结点（如慢0快3，中间隔了1和2两个结点）
        for (int i = 0; i < n; i++)
        {
            fastptr = fastptr->next;
        }

        //慢指针和快指针一起动，到快指针指向nullptr时退出
        while (fastptr)
        {
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }

        //此时慢指针就在倒数第N个位置，删除即可
        slowptr->next = slowptr->next->next;

        //new用完释放，记得新建一个结点保存一下头结点
        ListNode *resnode = headpointer->next;
        delete headpointer;

        //返回头指针，注意这里不能直接headpointer->next，new了一定要delete
        return resnode;
    }
};
// @lc code=end
