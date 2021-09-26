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
        int s0length = strs[0].size();
        int strlength = strs.size();
        //以第一个单词为基准
        //在strs[0]的范围内去检测，如果后面单词的字母数比第一个单词都要大，这个for循环就会循环到最后才退出
        for (int i = 0; i < s0length; i++)
        {
            char nowstr = strs[0][i];
            for (int j = 1; j < strlength; j++)
            {
                //i == strs[j].size()表明第一个单词还没数完，目前这第j个单词已经数完了，就要退出
                //strs[j][i] != nowstr表明第j个单词第i个字母对照第一个并不一样，退出
                if (i == strs[j].size() || strs[j][i] != nowstr)
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        //如果上面for循环执行完毕到了这句，说明第一个单词所有字母都通过了检测，直接返回这个基准就行了
        return strs[0];
    }
};
// @lc code=end