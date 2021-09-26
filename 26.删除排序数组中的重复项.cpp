/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int numslength = nums.size();
        //特殊情况
        if (numslength == 0)
        {
            return 0;
        }
        //i是存放不重复数的数组下标
        int i = 0;
        //j是移动指针，检测位置i和j的数是否相同
        for (int j = 1; j < numslength; j++)
        {
            //下一个数与位置i的数不相同，证明这个数已经不重复了，那么i应该移到这个位置
            if (nums[j] != nums[i])
            {
                //此处先i++再赋值，因为第0个位置默认就是放原数组的第一个数
                i++;
                nums[i] = nums[j];
            }
        }
        //注意这里为什么不用删除元素，题目已经说明了：
        //函数应该返回新的长度，并且原数组被修改，你不需要考虑数组中超出新长度后面的元素。
        //为什么最后返回的长度是i+1：仔细观察上面的循环，我们将原本的nums当成了新的数组来存放不重复的元素，那么从0开始到i，这里的长度当然是i+1
        return i + 1;
    }
};
// @lc code=end
