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
#include <stack>
using namespace std;
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //新建一个头指针保存头结点
        ListNode *headpointer = new ListNode();
        headpointer->next = head;

        //栈STL
        stack<ListNode *> stk;

        //放入所有的元素，再依次退出N个元素
        ListNode *cur = headpointer;
        while (cur)
        {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i)
        {
            stk.pop();
        }

        //此时顶部就是被删除元素的前一个，直接执行删除操作即可
        ListNode *prev = stk.top();
        prev->next = prev->next->next;

        //new用完释放，记得新建一个结点保存一下头结点
        ListNode *resnode = headpointer->next;
        delete headpointer;

        //返回头指针，注意这里不能直接headpointer->next，new了一定要delete
        return resnode;
    }
};
// @lc code=end
