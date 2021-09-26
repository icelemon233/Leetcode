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
#include <queue>
using namespace std;
//如果在自定义类内重载运算符，那么这个函数作为成员函数，有一个隐式的参数this指针，无法实现双目运算符重载
//一个双目运算符重载应该类外定义，作为全局重载使用

class Solution
{
public:
    //注意这个是队列的struct，而链表本身的struct仍然是listnode
    struct reset_heap_seq
    {
        int val;
        ListNode *queueNext;
        //重载<变为>，const reset_heap_seq &rhs指任意一个结点
        //函数加上const后缀的作用是表明函数本身不会修改类成员变量，同时使得该函数可以被 const 对象所调用
        bool operator<(const reset_heap_seq &node) const
        {
            return val > node.val;
        }
    };

    priority_queue<reset_heap_seq> firstQueue;

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        //将目前list中非空的每个链表的第一个node push到优先队列中
        //自动调整为小根堆，即已经自动排序
        for (ListNode *node : lists)
        {
            if (node)
                firstQueue.push({node->val, node});
        }

        //定义返回的链表数组和头结点
        ListNode *resList = new ListNode();
        ListNode *head = resList;

        //如果队列非空，则pop第一个数（最小值）
        //注意分清楚queue的每一个元素是一个链表，而resList是一个链表指针
        //多想想就不难理解 first.queueNext->next->val 是什么意思
        while (!firstQueue.empty())
        {
            //定义first为队列top元素，避免编写过于复杂
            auto first = firstQueue.top();
            //弹出队列top元素
            firstQueue.pop();
            //接上队列元素下一个
            resList->next = first.queueNext;
            resList = resList->next;
            //查找下一个队列里的元素，如果非空，将当前元素所在链表的下一个元素push进队列
            if (first.queueNext->next)
                firstQueue.push({first.queueNext->next->val, first.queueNext->next});
        }
        return head->next;
    }
};
// @lc code=end
