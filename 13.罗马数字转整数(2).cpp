/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    //替换
    string string_replace(string s, string str1, string str2)

    {
        int position = s.find(str1);
        if (position != s.npos)
        {
            s.replace(position, str1.size(), str2);
        }
        return s;
    }

    int getValue(char ch)
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
        case 'a':
            return 4;
        case 'b':
            return 9;
        case 'c':
            return 40;
        case 'd':
            return 90;
        case 'e':
            return 400;
        case 'f':
            return 900;
        }
        return 0;
    }

public:
    int romanToInt(string s)
    {
        int result = 0;

        s = string_replace(s, "IV", "a");
        s = string_replace(s, "IX", "b");
        s = string_replace(s, "XL", "c");
        s = string_replace(s, "XC", "d");
        s = string_replace(s, "CD", "e");
        s = string_replace(s, "CM", "f");

        for (int i = 0; i < s.length(); i++)
        {
            result += getValue(s[i]);
        }
        return result;
    }
};
// @lc code=end