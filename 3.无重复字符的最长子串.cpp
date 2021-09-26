/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] ���ظ��ַ�����Ӵ�
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //定义一个vevtor数组，128大小是为了包括所有的大小写字母
        vector<int> ascii_vector(128, 0);

        //定义最长子串长度变量
        int subslength = 0;

        //定义左指针，一开始指向位置0
        int lp = 0;

        //遍历字符串
        for (int i = 0; i < s.size(); i++)
        {
            /*
            原理：
            ascii_vector：保存了字符串中某个字符最后一次出现时，下一个字符的下标
            ascii_vector初始全为0，遍历数组：
            如果当前ascii码下标处（ascii_vector[s[i]]）为0，证明之前没出现过该字符。
            如果当前ascii码下标处不为0，则证明之前已经出现过该字符。
            lpcount：如果检测到重复的字符，应返回之前该重复字符最后一次出现的位置的下个字符的下标。
            */

            // 当出现重复字符时，ascii_vector一定比左指针大，lp就会指向该重复字符最后一次出现的位置的下个字符的下标。
            lp = max(lp, ascii_vector[s[i]]);

            // 既然检测到该字符，那么这个字符就是最后一次出现的位置，将下一个字符下标传进来vector里
            ascii_vector[s[i]] = i + 1;

            //i相当于右指针，lp相当于左指针，subslength每次都会记录最长子串长度
            subslength = max(subslength, i - lp + 1);
        }
        return subslength;
    }
};

// @lc code=end
