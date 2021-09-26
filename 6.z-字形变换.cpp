/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        //排除简单情况
        if (numRows == 1)
        {
            return s;
        }

        //返回字符串
        string res;

        //index存放当前行计算间隔之后的下标
        //比如numRows是4，那么
        //第一行是+6，+0交替，从a[0]开始
        //第二行是+4，+2交替，从a[1]开始
        //第三行是+2，+4交替，从a[2]开始
        //第四行是+0，+6交替，从a[3]开始
        int index = 0;
        int slength = s.size();
        //间距
        int steps1 = 2 * numRows - 2;
        int steps2 = 0;

        for (int i = 0; i < numRows; i++)
        {
            index = i;
            //注意steps2和steps1的计算方式
            steps2 = 2 * i;
            while (index < slength)
            {
                res += s[index];
                //中间层是交替出现两个相加为const的数，想一想，8-6=2,8-2=6
                //我们不需要动被减数，将上一次的答案直接拿过来作减数
                //得到的结果刚好就是2,6交替出现
                steps2 = steps1 - steps2;
                index += (i == 0 || i == numRows - 1) ? steps1 : steps2;
            }
        }
        return res;
    }
};
// @lc code=end
