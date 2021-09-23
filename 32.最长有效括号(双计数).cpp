/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        //思想：从左到右和从右到左分别检查一次
        //检查：left和right两个计数器分别记录两种括号，当括号数相等时记录对应长度
        //tip1：从左到右要保证左括号比右括号多，否则重置计数，另一边则相反
        //tip2:从左到右和从右到左各检查一次，保证了某一边可能判断错误的情况下，另一边能够纠正
        //如(()，从左到右只能检查为0（括号数不相等），但从右到左则是2
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
            {
                maxlength = max(maxlength, 2 * right);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
            {
                maxlength = max(maxlength, 2 * left);
            }
            else if (left > right)
            {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
