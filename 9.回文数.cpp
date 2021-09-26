/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int rex = 0;

        //负数和最后一位数是0的均不是回文
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        //检查一半数，避免了rex溢出的问题
        while (x > rex)
        {
            // rex增大10倍后面就会多出一个0，这个0的位置就是留给x%10的值
            // x%10就是取x最后一位数
            rex = rex * 10 + x % 10;

            //x/10就是把最后一位数抹掉
            x /= 10;
        }

        //上面while退出时x已经小于rex，即位数必定小于等于rex
        //奇数位数时，举例12321，x为12，rex为123（从右边往左边数），去掉rex最后一位并检查即可
        //偶数位数时，举例1221，x和rex都为12，直接检查即可
        return rex == x || rex / 10 == x;
    }
};
// @lc code=end
