/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        //奇数个符号一定无效
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }

        //初始化存放括号的栈
        stack<char> brackets;

        //分析：必须以正确的顺序闭合，这就说明括号成对挨着出现才是有效的，且左括号一定在右括号左边
        //用map类型就可以实现“对应”
        //规则：左括号直接入栈；对于右括号，如果栈顶可匹配，则左括号出栈，继续检查下个括号；如果栈顶不匹配，直接返回无效。
        //408中基本的栈应用的例子

        //建立map，注意key-value顺序
        unordered_map<char, char> brackets_pairs = {{')', '('}, {']', '['}, {'}', '{'}};

        //按照规则检查
        for (char ch : s)
        {
            //count是找key的，而key都是右括号，所以如果count返回1，那么当前括号一定是右括号，否则是左括号
            if (brackets_pairs.count(ch))
            {
                //匹配则弹出左括号
                if (!brackets.empty() && brackets.top() == brackets_pairs[ch])
                {
                    brackets.pop();
                }
                else //否则返回无效
                {
                    return false;
                }
            }
            else //左括号直接入栈
            {
                brackets.push(ch);
            }
        }
        //栈空证明匹配成功有效，不空则无效
        return brackets.empty();
    }
};
// @lc code=end
