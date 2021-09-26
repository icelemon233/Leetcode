/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
private:
    int getValue(char ch) //寻找对应字符的函数，注意这里没有类似4和9的描述
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

public:
    int romanToInt(string s)
    {
        int slength = s.size();
        int sum = 0;
        //先提取出第一个字符，这非常关键
        int preNum = getValue(s[0]);
        for (int i = 1; i < slength; i++)
        {
            //提取当前字符，也就是preNum的下一个字符
            int num = getValue(s[i]);
            //如果是4和9的类型，就会出现preNum < num的情况
            //对于4，减去I（1）加上V（5）刚好是结果
            //对于9，减去I（1）加上X（10）也刚好是结果
            //所以如果有preNum < num的情况，应该减去preNum
            //这里不用担心下一次是否自然会加上后一个字符，因为特殊情况只会是两个字符搭配，不可能三个字符同时递增
            if (preNum < num)
            {
                sum -= preNum;
            }
            //
            else
            {
                sum += preNum;
            }
            //pre指向本次字符，使得preNum和num同步
            preNum = num;
        }
        sum += preNum;
        return sum;
    }
};
// @lc code=end
