/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        //特殊情况
        if (!strs.size())
        {
            return "";
        }
        //prefix记录公共前缀，当然先记录整个的第一个字符串
        string prefix = strs[0];
        int strlength = strs.size();

        //从第二个字符串开始，依次用匹配函数得到公共前缀
        for (int i = 1; i < strlength; ++i)
        {
            prefix = matchCommonPrefix(prefix, strs[i]);
            //如果公共前缀为空，可以直接退出了，避免冗余查询
            if (!prefix.size())
            {
                break;
            }
        }
        return prefix;
    }

    string matchCommonPrefix(const string &str1, const string &str2)
    {
        //匹配要注意的两个点，一是用index记录最长公共前缀下标
        //二是检查的最大长度不应该超过两个字符串较短的长度
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index])
        {
            ++index;
        }
        return str1.substr(0, index);
    }
};

// @lc code=end