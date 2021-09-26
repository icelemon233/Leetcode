/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
//utility在一些比较常用的vector、iostream等头文件中都有包含，此处仅说明pair包含在utility头文件中
#include <utility>
//tie同上
#include <tuple>
using namespace std;
class Solution
{
public:
    // 翻转一个子链表，并且返回新的头与尾
    //此部分用图形画出展示会更清楚
    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail)
    {
        ListNode *prevptr = tail->next;
        ListNode *ptr = head;
        while (prevptr != tail)
        {
            ListNode *nextptr = ptr->next;
            ptr->next = prevptr;
            prevptr = ptr;
            ptr = nextptr;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //定义一个头指针指向头结点，最后返回的时候用
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        //复制一份，因为preHead也是要改的，就用这份movehead来改
        ListNode *movehead = preHead;

        while (head)
        {
            //定义前一组结点的尾巴（比如第二组的456，前一组的3就是tail指向的结点）
            ListNode *tail = movehead;
            //既然都定义了，就先找到tail结点
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                {
                    return preHead->next;
                }
            }
            //这一步原本是有的，但是reverse那里已经做了，就不要重复了
            //那么顺带下面有关nexthead的也不需要用到了
            //找到了tail，待会tail要被替换顺序的，现在先存好下一组的头结点
            //ListNode *nexthead = tail->next;

            //现在可以开始反转结点了
            tie(head, tail) = myReverse(head, tail);

            // 把子链表重新接回原链表
            // 记得，现在的head是原来的tail，已经反过来了
            //现在，做两项工作，使得下一次循环是正确的
            //1. 连接前后两组子链表：头指针接上原来的尾巴，原来的尾巴接到下一组第一个头结点上
            movehead->next = head;
            // tail->next = nexthead;

            //2.改movehead位置：头指针指向这一组的最后一个，使得next就是下一组第一个头结点
            //改head位置，使得head永远在movehead后一个
            movehead = tail;
            head = tail->next;
        }

        //跳出循环证明结束了，返回头结点即可
        return preHead->next;
    }
};
// @lc code=end
