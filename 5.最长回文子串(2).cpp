/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //字符串长度，最大子串长度，最大子串
        int slength = s.size();
        int maxlength = 0;
        string res = s.substr(0, 1);

        //特殊情况直接处理
        if (slength < 2)
        {
            return s;
        }

        //定义dp二维数组（表格）
        vector<vector<bool>> dp(slength);
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i].resize(slength);
        }

        //先把对角线填成true（单个字符一定是回文）
        for (int j = 0; j < slength; j++)
        {
            dp[j][j] = true;
        }

        //开始填表，按列，从上到下，从左到右（这里有4种合法顺序）
        //合法的意思是dp[i][j]有时候需要参照dp[i+1][j-1]的值
        //举例：dp[1][4]是true，代表位置1和4字符相等，但还需要2和3相等，从1到4这一串才是回文串
        for (int rp = 1; rp < slength; rp++)
        {
            for (int lp = 0; lp < rp; lp++)
            {
                //不相等，那么从lp到rp这串子串一定不是回文串
                if (s[lp] != s[rp])
                {
                    dp[lp][rp] = false;
                }

                //相等，那么从lp到rp这串子串可能是回文串，要继续检查里面的
                else
                {
                    //子串长度不超过4，也就是0~3，可以直接判定是回文串
                    if (rp - lp + 1 < 4)
                    {
                        dp[lp][rp] = true;
                    }
                    //如果子串长度不能判定，就要取决于内层那一对是不是回文
                    else
                    {
                        dp[lp][rp] = dp[lp + 1][rp - 1];
                    }
                }

                //如果这次dp判定为true，就与最大值进行比较，如果更大，就进行记录
                if (dp[lp][rp])
                {
                    if (rp - lp + 1 > maxlength)
                    {
                        maxlength = rp - lp + 1;
                        res = s.substr(lp, rp - lp + 1);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
