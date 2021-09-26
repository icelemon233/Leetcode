/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int numslength = nums.size();
        //特殊情况
        if (numslength == 3)
        {
            return nums[0] + nums[1] + nums[2];
        }

        //restg：返回值
        //threesum：计算过程中三个数的值
        //dist：threesum和target的差值
        int restg = 0;
        int threesum = 0;
        int dist = INT_MAX;

        sort(nums.begin(), nums.end());
        //这里排序加双指针法比较好理解，重点是要如何减少查询次数
        //1. 一重循环和二重循环重复的数不再查
        //一重循环比如[1,1,1,3,4,5]，第一个1和第二个1如果都查，那么类似[1,3,4][1,3,5]这种就重复了
        //二重循环比如上面例子的第一个1固定，第一次查找是[1,1]+[1,3,4,5]中的一个，第二次查找是[1,1]+[3,4,5]中的一个，就有重复了
        for (int i = 0; i < numslength; i++)
        {
            //注意这里不要漏i>0，因为一开始i=0的话，i-1是非法的
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = numslength - 1;
            while (left < right)
            {
                threesum = nums[i] + nums[left] + nums[right];
                if (abs(threesum - target) < dist)
                {
                    dist = abs(threesum - target);
                    restg = threesum;
                }

                // 如果直接就是target，那么可以直接返回
                if (threesum == target)
                {
                    return target;
                }
                // 如果小了，左指针往右；如果大了，右指针往左
                else if (threesum < target)
                {
                    left++;
                }
                else if (threesum > target)
                {
                    right--;
                }
            }
        }
        return restg;
    }
};
// @lc code=end
