/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int hlength = haystack.size();
        int nlength = needle.size();
        unordered_map<char, int> shift_table;
        // 建立模式串的偏移表
        //规则： 模式串中该字母出现的最右位置到尾部的距离+1
        for (int i = 0; i < nlength; i++)
        {
            shift_table[needle[i]] = nlength - i;
        }

        //进行匹配
        int i = 0;
        while (i <= hlength - nlength)
        {
            //从位置i开始nlength的长度，如果匹配模式串，则结束
            if (haystack.substr(i, nlength) == needle)
                return i;

            else
            {
                //模式串中存在该字符，则按照偏移值偏移
                if (shift_table.find(haystack[i + nlength]) != shift_table.end())
                {
                    i += shift_table[haystack[i + nlength]];
                }
                //否则直接跳过一个模式串的长度
                else
                {
                    i += nlength + 1;
                }
            }
        }
        return -1;
    }
};

// @lc code=end
