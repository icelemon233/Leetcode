/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
<<<<<<< HEAD
=======
//leetcode中国版不支持负数左移，因此只能使用unsigned int
#include <limits.h>
#include <math.h>
>>>>>>> master
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
<<<<<<< HEAD
=======
        int count = 0;
        if (divisor == INT_MIN || divisor == INT_MAX)
        {
            if (dividend == divisor)
            {
                return 1;
            }
            else if (dividend == -divisor)
            {
                return -1;
            }
            else
                return 0;
        }
        if (dividend == divisor)
        {
            return 1;
        }
        if (dividend == 0)
        {
            return 0;
        }
        if (dividend == -divisor)
        {
            return -1;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        //leetcode迷幻操作
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        bool symbol = false; //判断大于0的个数，用于判断商的符号
        //均转为正数方便后续移位计算（只用-号）
        if (dividend > 0)
        {

            if (divisor > 0)
            {
                symbol = true;
            }
        }
        else
        {
            if (divisor < 0)
            {
                symbol = true;
            }
        }
        unsigned int div1 = abs(dividend);
        unsigned int div2 = abs(divisor);
        //应对除数为最小的情况
        if (dividend == INT_MIN)
        {
            //逃票操作
            dividend += 1;
            unsigned int div1 = abs(dividend);
            int result = getcount(div1, div2);
            return symbol ? result : -result - 1;
        }
        else
        {
            int result = getcount(div1, div2);
            //如果符号不同则返回负数
            return symbol ? result : -result;
        }
    }

    int getcount(unsigned int dividend, unsigned int divisor)
    {
        int nomore = 0;
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            if (dividend >= (divisor << i))
            {
                nomore++;
                continue;
            }
            if (nomore == 0)
            {
                break;
            }
            sum += 1 << i - 1;
            dividend -= divisor << (i - 1);
            nomore = 0;
            i = -1;
        }
        return sum;
>>>>>>> master
    }
};
// @lc code=end
