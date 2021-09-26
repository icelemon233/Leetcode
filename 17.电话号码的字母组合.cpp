/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        //这里也可以将这三个变量选择放在public处，dfs就不需要引用那么多参数了，但是不安全
        unordered_map<char, string> phonemap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        //combinations是总的返回答案，one_comb_str是每一次搭配得出的字母组合，pos是对应digits长度的字母组合长度指针
        vector<string> combinations;
        string one_comb_str;
        //特殊情况
        if (digits.empty())
        {
            return combinations;
        }
        NumToLetter_dfs(0, combinations, one_comb_str, phonemap, digits);
        return combinations;
    }

    void NumToLetter_dfs(int pos, vector<string> &combinations, string &one_comb_str, const unordered_map<char, string> &phoneMap, const string &digits)
    {
        //pos等于digits，也就是一次组合完毕后，可以回到上一级
        //比如"23"，得出"ad"后返回上一级
        if (pos == digits.size())
        {
            // 将这次的组合词放入combinations中
            combinations.push_back(one_comb_str);
            return;
        }

        //进入正常流程，以下以"23"为例
        else
        {
            //先找到'2',然后从map中找到'2'对应的 "abc"
            string letters = phoneMap.at(digits[pos]);
            //C++11 里面的for的新写法，表示依次取出字符串数组letters中的元素，赋给变量letter
            //对比python的range，是不是感觉很像！
            //分次取出a，b，c
            for (char letter : letters)
            {
                //第一次循环会放入a，之后两次循环就是b和c
                one_comb_str.push_back(letter);
                //回溯，这一步我们可以一次性得到 "ad" "ae" "af"，之后请如法炮制
                NumToLetter_dfs(pos + 1, combinations, one_comb_str, phoneMap, digits);
                //如果第一次循环到这了，说明 a 的部分已经检查完了，下一次就到b了
                one_comb_str.pop_back();
            }
            //最后说一下清晰的顺序，第一次正常流程先push'a'，然后回溯，检测到长度不够，继续push'd'，继续回溯
            //此时检测到长度满足，放入返回数组中，return，跳到最后一句，把'd'pop出来
            //请注意这时候的for循环在第二层(是3对应的 "def"那层，而不是最外层的2对应的 "abc"层)
            //所以下一步循环会放入'e'，而不是'b'，好好想清楚！
        }
    }
};

// @lc code=end
