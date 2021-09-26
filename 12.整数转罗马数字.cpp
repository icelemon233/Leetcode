/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        //一一对应法，简单且直观
        int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        for (int i = 0; i < 13; i++)
        {
            while (num >= arabic[i])
            {
                num -= arabic[i];
                res += romans[i];
            }
        }
        return res;
    }
};
// @lc code=end
