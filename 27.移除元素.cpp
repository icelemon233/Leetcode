/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int numslength = nums.size();
        //特殊情况
        if (numslength == 0)
        {
            return 0;
        }
        //i是存放非val数的数组下标
        int i = 0;
        //j是移动指针，检测位置i和j的数是否相同
        for (int j = 0; j < numslength; j++)
        {
            //下一个数与位置i的数不相同，证明这个数不是val了，那么i应该移到这个位置
            if (nums[j] != val)
            {
                //此处先赋值再i++，因为第0个位置也要检查是否和val相同
                nums[i] = nums[j];
                i++;
            }
        }
        //注意这里为什么不用删除元素，题目已经说明了：
        //函数应该返回新的长度，并且原数组被修改，你不需要考虑数组中超出新长度后面的元素。
        //为什么最后返回的长度是i：原理同26.删除排序数组中的重复项，但是这里稍微改了一下，循环退出时得到的是i+1，这里我们就不要再+1了
        return i;
    }
};
// @lc code=end
