/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //特殊情况特殊处理
        if (nums.size() == 0)
        {
            return -1;
        }
        else if (nums.size() == 1)
        {
            return (target != nums[0]) ? -1 : 0;
        }
        else
        {
            //右点是size-1，不要犯低级错误
            int lpoint = 0, rpoint = nums.size() - 1;

            //二分法
            while (lpoint <= rpoint)
            {
                //中点计算一定要放在while里面，否则midpoint不会自动更新！
                int midpoint = (lpoint + rpoint) / 2;
                //检查中点，正确则返回
                if (target == nums[midpoint])
                {
                    return midpoint;
                }
                //左边比中点小，那么左边到中点的部分是升序
                else if (nums[0] <= nums[midpoint])
                {
                    //如果目标点数值在左边和中点数值之间，那么就检查左边部分
                    if (target >= nums[lpoint] && target < nums[midpoint])
                    {
                        rpoint = midpoint - 1;
                    }
                    //否则检查右边部分
                    else
                    {
                        lpoint = midpoint + 1;
                    }
                }
                //与上面同理
                else
                {
                    if (target > nums[midpoint] && target <= nums[nums.size() - 1])
                    {
                        lpoint = midpoint + 1;
                    }
                    else
                    {
                        rpoint = midpoint - 1;
                    }
                }
            }
            return -1;
        }
    }
};
// @lc code=end
