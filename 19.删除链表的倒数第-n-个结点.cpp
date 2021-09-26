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
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //新建一个头指针保存头结点
        ListNode *headpointer = new ListNode();
        headpointer->next = head;
        /*也可以ListNode *headpointer = new ListNode(0,head);*/

        int Listlen = getLength(head);

        //头指针副本
        ListNode *hp = headpointer;
        for (int i = 1; i < Listlen - n + 1; i++)
        {
            hp = hp->next;
        }

        //删除操作
        hp->next = hp->next->next;

        //new用完请释放，记得新建一个结点保存一下头结点
        ListNode *resnode = headpointer->next;
        delete headpointer;

        //返回头指针，注意这里不能直接headpointer->next，new了一定要delete
        return resnode;
    }
};
// @lc code=end
