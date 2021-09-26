/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //异常输入排除
        if (s.size() == 0)
        {
            return 0;
        }
        else if (s.size() == 1)
        {
            return 1;
        }

        // 以哈希表为基础的set
        unordered_set<char> subs;

        // lp为左指针，rp为右指针，subslength为当前子串长度，maxlength为最大子串长度
        int lp = 0, rp = 1, maxlength = 0;

        //第一个字符插入子串
        subs.insert(s[0]);

        while (rp < s.size())
        {
            //如果找到了之前subs中的字符（重复）
            if (subs.find(s[rp]) != subs.end())
            {
                //擦掉最左边的字符，左指针加1
                subs.erase(s[lp]);
                lp++;
            }
            //没有重复的情况
            else
            {
                //当前右指针指向的元素入set
                subs.insert(s[rp]);

                //右指针+1
                rp++;

                //确定一次最大长度
                maxlength = (subs.size() > maxlength) ? subs.size() : maxlength;
            }
        }

        return maxlength;
    }
};

// @lc code=end
