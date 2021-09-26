/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
private:
    string centerSpread(string s, int lp, int rp)
    {
        // left = right 的时候，此时回文中心是一个空隙，向两边扩散得到的回文子串的长度是奇数
        // right = left + 1 的时候，此时回文中心是一个字符，向两边扩散得到的回文子串的长度是偶数
        int slength = s.size();
        while (lp >= 0 && rp < slength)
        {
            //回文则继续，不是则停止
            if (s[lp] == s[rp])
            {
                lp--;
                rp++;
            }
            else
            {
                break;
            }
        }
        // 注意这里的取值，跳出while时lp已经小于0，要补回一个1
        return s.substr(lp + 1, rp - lp - 1);
    }

public:
    string longestPalindrome(string s)
    {
        int slength = s.size();
        //异常情况处理
        if (slength < 2)
        {
            return s;
        }

        int maxLen = 1;
        //存放返回的子串
        string res = s.substr(0, 1);

        // 中心位置枚举到 len - 2 即可
        for (int i = 0; i < slength - 1; i++)
        {
            //奇数回文串
            string oddStr = centerSpread(s, i, i);

            //偶数回文串
            string evenStr = centerSpread(s, i, i + 1);

            //取较长的一串
            string maxLenStr = oddStr.size() > evenStr.size() ? oddStr : evenStr;

            //如果这次枚举的结果比原来存储的要长（一样长则保留最开始的一个），则进行替换
            if (maxLenStr.length() > maxLen)
            {
                maxLen = maxLenStr.size();
                res = maxLenStr;
            }
        }
        return res;
    }
};
// @lc code=end
