/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        //算法原理请查看discussion官方解答
        //当nums长度>=2时，才进行操作
        if (nums.size() == 2)
        {
            reverse(nums.begin(), nums.end());
        }

        else if (nums.size() > 2)
        {
            //设置变量存储需要交换的数字
            int index1 = nums.size() - 2;

            //从后面开始，按顺序寻找非升序的数字
            //如果没有，如2023，则直接将index1维持原位置，并可以进行下一步交换
            while (nums[index1] >= nums[index1 + 1] && index1 >= 0)
            {
                index1--;
                if (index1 < 0)
                {
                    break;
                }
            }

            //如果index1==-1，那么原序列就是降序排列，直接进行逆序就是下一个排列
            if (index1 >= 0)
            {
                int index2 = nums.size() - 1;
                //寻找比这一位置大的数字，找到立即退出
                while (nums[index2] <= nums[index1] && index2 >= 0)
                {
                    index2--;
                }

                //交换位置
                swap(nums[index1], nums[index2]);
            }

            //根据原理，交换后原index1 后 （所以要加1）的数字一定是降序排列，重排使之变为升序
            //或者检验出原序列就是降序排列，直接进行逆序就是下一个排列
            reverse(nums.begin() + index1 + 1, nums.end());
        }
    }
};
// @lc code=end
