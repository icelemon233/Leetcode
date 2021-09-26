/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int hlength = height.size();
        //双指针
        int lp = 0, rp = hlength - 1;
        //记录最大容量
        int maxvol = 0;
        while (lp < rp)
        {
            //公式计算
            int vol = min(height[lp], height[rp]) * (rp - lp);
            maxvol = max(maxvol, vol);

            //小的往里进1，数学原理已经解释
            if (height[lp] <= height[rp])
            {
                lp++;
            }
            else
            {
                rp--;
            }
        }
        return maxvol;
    }
};
// @lc code=end
