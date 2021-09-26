/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> resnums;
        int numslength = nums.size();
        //特殊情况
        if (numslength < 3)
        {
            return resnums;
        }
        sort(nums.begin(), nums.end());
        //这里排序加双指针法比较好理解，重点是要如何减少查询次数
        //1. 一重循环和二重循环重复的数不再查
        //一重循环比如[1,1,1,3,4,5]，第一个1和第二个1如果都查，那么类似[1,3,4][1,3,5]这种就重复了
        //二重循环比如上面例子的第一个1固定，第一次查找是[1,1]+[1,3,4,5]中的一个，第二次查找是[1,1]+[3,4,5]中的一个，就有重复了
        for (int i = 0; i < numslength - 2; i++)
        {
            if (nums[i] > 0)
                break;
            //注意这里不要漏i>0，因为一开始i=0的话，i-1是非法的
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            //由于已知target为0，就可以三数之和转化为两数之和=target
            int target = -nums[i];
            int left = i + 1, right = numslength - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    resnums.push_back({nums[i], nums[left], nums[right]});

                    // 这个if循环是找到答案了，那么现在left和right都不需要了，直接移动到下一顺位
                    // 如果出现重复情况，需要再次顺位
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else if (nums[left] + nums[right] > target)
                {
                    right--;
                }
            }
        }
        return resnums;
    }
};
// @lc code=end
