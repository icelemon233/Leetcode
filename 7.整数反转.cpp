/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <limits.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        // 注意这里为什么要定义long而不是int
        long rex = 0;
        while (x)
        {
            // rex增大10倍后面就会多出一个0，这个0的位置就是留给x%10的值
            // x%10就是取x最后一位数
            rex = rex * 10 + x % 10;

            //x/10就是把最后一位数抹掉
            x /= 10;
        }

        // 超过最大值或小于最小值，则返回0
        // 否则符合规则，直接返回本身
        return rex > INT_MAX || rex < INT_MIN ? 0 : rex;
    }
};
// @lc code=end
