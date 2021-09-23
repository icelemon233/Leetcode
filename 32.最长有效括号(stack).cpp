/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int max_bk_length = 0;
        stack<int> bk;
        //先把-1入栈，方便下标计算
        bk.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            //左括号直接入栈
            if (s[i] == '(')
            {
                bk.push(i);
            }
            else
            {
                //右括号直接出栈
                bk.pop();
                //空栈证明没有和这个右括号对应的左括号
                //把这个括号入栈作为新的计算起点
                if (bk.empty())
                {
                    bk.push(i);
                }
                //出栈一个括号后栈仍然非空
                //证明栈顶元素是与当前右括号对应的左括号位置
                //那么用当前位置减去栈顶元素，并更新最大值
                else
                {
                    max_bk_length = max(max_bk_length, i - bk.top());
                }
            }
        }
        return max_bk_length;
    }
};
// @lc code=end
