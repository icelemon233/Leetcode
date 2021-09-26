/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
#include <memory>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getNext(string needle, int nlen)
    {
        //定义 next 数组
        vector<int> next(nlen + 1);
        // 初始化
        next[0] = -1;
        int i = 1, j = -1;
        while (i < nlen)
        {
            //存在最长前缀但是不相等了，则返回上一个对应位置的next值
            while (j != -1 && needle[j + 1] != needle[i])
            {
                j = next[j];
            }
            //相同，那么检查下一个元素，next也可以加1
            if (needle[j + 1] == needle[i])
            {
                ++j;
            }
            next[++i] = j;
        }
        return next;
    }

    int kmp(string haystack, string needle, int hlen, int nlen)
    {
        //获取next 数组
        vector<int> next = getNext(needle, nlen);
        int i = 0, j = 0;
        for (int i = 0; i < hlen; ++i)
        {
            //不相等，参考next数组回到某个位置再次匹配
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1] + 1;
                //超出长度时，可以直接返回不存在
                if (nlen - j + i > hlen)
                {
                    return -1;
                }
            }
            //相等则检查下一个
            if (haystack[i] == needle[j])
            {
                ++j;
            }
            //遍历完整个模式串，返回模式串的起点下标
            if (j == nlen)
            {
                return i - nlen + 1;
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle)
    {
        int hlength = haystack.size();
        int nlength = needle.size();
        // 两种特殊情况
        if (nlength == 0)
        {
            return 0;
        }
        if (hlength == 0)
        {
            return -1;
        }
        return kmp(haystack, needle, hlength, nlength);
    }
};

// @lc code=end
