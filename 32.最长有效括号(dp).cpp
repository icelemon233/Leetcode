/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        //定义返回值
        int max_bk_length = 0;

        //创建一个dp数组，并且值全为0
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++)
        {
            //只有当前检查的s[i] == ')'时才进行计算，否则左括号对应位置的dp值一定是0
            if (s[i] == ')')
            {
                //如果前一个s[i - 1] == '('
                if (s[i - 1] == '(')
                {
                    //如果i>=2，那么这一组（i-1，i）有效，并且前面有括号，加上位置最靠后的i-2的dp值
                    //如果i<2，那么这个括号只可能下标为1，dp值直接加2
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                }
                //如果前一个s[i - 1] == ')'，并且对应括号的i - dp[i - 1] - 1这个位置存在（不小于0）
                //那么就检查这个括号是不是'('，是则+2
                else
                {
                    int corres_bk = i - dp[i - 1] - 1;       // 对应括号位置
                    int corres_bk_front = i - dp[i - 1] - 2; //对应括号前一个位置的dp值
                    if (corres_bk >= 0 && s[corres_bk] == '(')
                    {
                        //类似上面的操作
                        dp[i] = dp[i - 1] + (corres_bk_front >= 0 ? dp[corres_bk_front] : 0) + 2;
                    }
                    else
                    {
                        continue;
                    }
                }

                //每轮都更新为最大的dp值
                max_bk_length = max(max_bk_length, dp[i]);
            }
        }
        return max_bk_length;
    }
};
// @lc code=end