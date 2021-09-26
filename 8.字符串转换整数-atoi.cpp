/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int slength = s.size();
        //正负标志
        int flag = 1;
        int index = 0;
        int renum = 0;

        //判断前导空格
        while (index < slength && s[index] == ' ')
        {
            i++;
            if (index == slength)
            {
                return 0;
            }
        }

        // 判断正负，非数字则直接停止
        if (s[index] == '-')
        {
            flag = -1;
            index++;
        }
        else if (s[index] == '+')
        {
            index++;
        }
        else if (!isdigit(s[index]))
        {
            return 0;
        }

        while (isdigit(s[index]) && index < slength)
        {
            //这里注意3个点
            //1. renum是当作无符号数，只可能比最大的int还大，不用写min
            //2. 每次renum都要乘以10，同时加上最后一个数，都有可能造成溢出（直接造成int报错），如果renum*10+s[i]比int_max大，必为溢出
            //3. 10*renum会报错！要用10.0。
            if (10.0 * renum + (s[index] - '0') > INT_MAX)
            {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            renum = 10.0 * renum + (s[index] - '0');
            index++;
        }
        return flag * renum;
    }
};
// @lc code=end