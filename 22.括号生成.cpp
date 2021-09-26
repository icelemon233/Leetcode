/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        //本题与17.电话号码的字母组合十分相似，可互相参考
        //定义左右括号数
        int left_brackets_num = n;
        int right_brackets_num = n;

        //定义每一轮得到的组合和最终返回的组合串
        string valid_gene;
        vector<string> res_gene;

        //dfs回溯
        getBrackets(valid_gene, res_gene, left_brackets_num, right_brackets_num);
        return res_gene;
    }

    void getBrackets(string gene, vector<string> &res, int leftnum, int rightnum)
    {
        //括号都没了，撤退
        if (leftnum == 0 && rightnum == 0)
        {
            res.push_back(gene);
            return;
        }
        //剩余左右括号数相等，下一个只能用左括号
        if (leftnum == rightnum)
        {

            getBrackets(gene + "(", res, leftnum - 1, rightnum);
        }
        //剩余左括号小于右括号，下一个可以用左括号也可以用右括号
        else if (leftnum < rightnum)
        {

            if (leftnum > 0)
            {
                getBrackets(gene + "(", res, leftnum - 1, rightnum);
            }
            getBrackets(gene + ")", res, leftnum, rightnum - 1);
        }
    }
};
// @lc code=end
