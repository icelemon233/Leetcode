/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
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

        //如果字符串比numRows还小，那么建立一个长度为s.size()的数组就可以了，多了是浪费空间
        vector<string> rows(min(numRows, int(s.size())));

        //返回数组
        string res;
        int slength = s.size();

        //定义当前行变量
        int rowIndex = 0;

        //反转标志，false为向下（+），true为向上（-）
        bool flag = false;

        for (int i = 0; i < slength; i++)
        {
            if (flag == false)
            {
                //注意这里的操作，反转方向之后这一步是会跳出到下一个i的
                //但是我们不能丢掉这一次的i，所以应该跳到合适的行的位置
                //把这次的“鸡蛋”i放进篮子里
                if (rowIndex == numRows)
                {
                    flag = true;
                    rowIndex -= 2;
                    rows[rowIndex--] += s[i];
                    continue;
                }
                rows[rowIndex] += s[i];
                rowIndex++;
            }
            else if (flag == true)
            {
                if (rowIndex == -1)
                {
                    flag = false;
                    rowIndex += 2;
                    rows[rowIndex++] += s[i];
                    continue;
                }
                rows[rowIndex] += s[i];
                rowIndex--;
            }
        }

        for (int j = 0; j < rows.size(); j++)
        {
            res += rows[j];
        }
        return res;
    }
};
// @lc code=end
