/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        //由于words中单词长度相同，只需要直接存储该变量
        auto words_length = words[0].size();
        auto words_num = words.size();

        if (words_num == 0)
        {
            return {};
        }
        if (words_length * words_num > s.size())
        {
            return {};
        }

        //非空，新建两个哈希表
        //存储答案的int数组
        vector<int> ret;
        unordered_map<string, int> wordsstringcount;
        unordered_map<string, int> substringcount;

        //将words里的词写到wordsstringcount里面去
        for (int i = 0; i < words_num; i++)
        {
            wordsstringcount[words[i]]++;
        }

        //通过给定s的滑动子串，检查是否符合words的规则
        //第一层是滑动字串
        for (int i = 0; i + words_num * words_length <= s.size(); i++)
        {
            //第二层是依次检查字串中某个单词的数量是否有超过words中该单词的计数
            //j是字串中所依次检查单词的首位
            //此处将j外置，否则跳出循环时局部变量作用消失，另一种方法是设置临时变量temp
            int j = 0;
            for (j = i; j < i + words_num * words_length; j += words_length)
            {
                //提取字串
                string temp_str = s.substr(j, words_length);
                //words中没有该串，直接跳过这个子串
                if (wordsstringcount[temp_str] == 0)
                {
                    break;
                }
                else
                {
                    //子串中的某个单词计数
                    substringcount[temp_str]++;
                    //这里默认做了两个操作
                    //1：如果words中没有这个单词，那么条件将直接成立并退出该次循环
                    //2：如果words中有这个单词，那么检查条件，如成立，则退出该次循环
                    if (wordsstringcount[temp_str] < substringcount[temp_str])
                        break;
                }
            }
            //跳出循环时，j刚好到子串结尾，证明全部符合条件
            if (j == (i + words_length * words_num))
            {
                ret.push_back(i);
            }

            //字串计数清空，进行下一轮搜索
            substringcount.clear();
        }
        return ret;
    }
}

;
// @lc code=end
