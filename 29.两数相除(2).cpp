/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
#include <limits.h>
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int count = 0;
        auto divcopy = dividend;
        if (dividend == 0)
        {
            return 0;
        }
        if (dividend == divisor)
        {
            return 1;
        }
        if (dividend == -divisor)
        {
            return -1;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        while (1)
        {
            if (dividend > 0)
            {
                if (divisor > 0)
                {
                    dividend -= divisor;
                }
                else
                {
                    dividend += divisor;
                }
            }
            else
            {
                if (divisor < 0)
                {
                    dividend -= divisor;
                }
                else
                {
                    dividend += divisor;
                }
            }
            if (divcopy > 0)
            {
                if (dividend > 0)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (dividend < 0)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count == INT_MAX && count == INT_MIN)
            {
                return INT_MAX;
            }
        }
        if (divcopy > 0)
        {
            if (divisor > 0)
            {
                return count;
            }
            else
            {
                return 0 - count;
            }
        }

        else
        {
            if (divisor < 0)
            {
                return count;
            }
            else
            {
                return 0 - count;
            }
        }
    }
};
// @lc code=end
