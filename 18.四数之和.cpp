/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> resnums;
        int numslength = nums.size();
        //特殊情况
        if (numslength < 4)
        {
            return resnums;
        }
        sort(nums.begin(), nums.end());
        //这里排序加双指针法，参考15.三数之和
        //以下是4种减少运行时间的剪枝，来源leetcode官方，讲的很好
        //1.在确定第一个数之后，如果 nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target，说明此时剩下的三个数无论取什么值，四数之和一定大于 target，因此退出第一重循环；
        //2.在确定第一个数之后，如果 nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<nums[i]+nums[n−3]+nums[n−2]+nums[n−1]<target，说明此时剩下的三个数无论取什么值，四数之和一定小于 target，因此第一重循环直接进入下一轮，枚举 nums[i+1]；
        //3.在确定前两个数之后，如果 nums[i]+nums[j]+nums[j+1]+nums[j+2]>nums[i]+nums[j]+nums[j+1]+nums[j+2]>target，说明此时剩下的两个数无论取什么值，四数之和一定大于 target，因此退出第二重循环；
        //4.在确定前两个数之后，如果 nums[i]+nums[j]+nums[n-2]+nums[n-1]<nums[i]+nums[j]+nums[n−2]+nums[n−1]<target，说明此时剩下的两个数无论取什么值，四数之和一定小于 target，因此第二重循环直接进入下一轮，枚举 nums[j+1]。
        //!!!!!注意i的取值：i < numslength - 3，否则一定会发生越界错误！j同理。
        for (int i = 0; i < numslength - 3; i++)
        {
            //注意这里不要漏i>0，因为一开始i=0的话，i-1是非法的
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            //剪枝1
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                return resnums;
            }
            //剪枝2
            if (nums[i] + nums[numslength - 1] + nums[numslength - 2] + nums[numslength - 3] < target)
            {
                continue;
            }
            //进入第二层，也就是第二个数
            for (int j = i + 1; j < numslength - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                //剪枝3：注意和剪枝1的区别，这里不能直接退出！
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }
                //剪枝4
                if (nums[i] + nums[j] + nums[numslength - 2] + nums[numslength - 1] < target)
                {
                    continue;
                }

                //这里和15.三数之和是一模一样的了，做些许改动即可。
                int left = j + 1, right = numslength - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        resnums.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // 这个if循环是找到答案了，那么现在left和right都不需要了，直接移动到下一顺位
                        // 如果出现重复情况，需要再次顺位
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                }
            }
        }
        return resnums;
    }
};
// @lc code=end
