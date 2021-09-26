/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slength = s.size();
        int plength = p.size();
        //定义动态规划矩阵，注意这里我们矩阵也是用数学上的计算，所以下标应该再多一个
        vector<vector<bool>> dp(slength + 1);
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i].resize(plength + 1);
        }

        // 先填上可以填的
        // 如果i，j都是0，那么两个空字符串一定匹配
        // 如果i是0，j是1，那么非空字符串（且第一位一定不是*）一定不匹配空字符串

        dp[0][0] = true;
        dp[0][1] = false;

        //i=0的一行是有规律的，因为是非空字符串匹配空字符串，
        //只有x*这样的子串才能自己消掉自己，这个字串长度是2，
        //所以结果一定与dp[i][j-2]匹配
        for (int j = 2; j <= plength; j++)
        {
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        }

        // 如果i≠0，j是0，那么空字符串一定不匹配不为空的字符串
        for (int i = 1; i <= slength; i++)
        {
            dp[i][0] = false;
        }

        //i=0行和j=0列都填完了，这里要开始按方法填表
        //！！！注意，这里矩阵是数学形式，而字符串还是用的下标
        //！！！所以，举个例，当dp的i取1的时候，s[i]应该取0，j同理
        for (int i = 1; i <= slength; i++)
        {
            for (int j = 1; j <= plength; j++)
            {
                //1.匹配情况：普通字母匹配相等，或者是通配符.号，就看前面的那段是否匹配
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                //2.*号情况：分类讨论
                else if (p[j - 1] == '*')
                {
                    //假如字符串p是ab*，对字符串s进行匹配，s的情况如下
                    //3.1 s是a，那么ab*应该减去2个字符进行匹配（b*匹配0个b，自己消掉自己），这是dp[i][j - 2]的情况
                    //3.2 s是ab，那么ab*应该减去1个字符进行匹配（b*匹配1个b，把*号删掉就可以了），这是dp[i][j - 1]的情况
                    //3.3 s是abb或者abbb等，那么这类可以看作ab*与a（n个b，n>=2）进行匹配
                    //我们应该参考ab*与a（n-1个b）的匹配结果，毕竟后面多一个b是不影响*号的多个作用的
                    //比如ab*与abb，就应该参考ab*与ab是否匹配。所以看出规律，是dp[i][j]=dp[i-1][j]
                    //上面三种情况综合考虑，有一种为true，这次匹配就可以判true
                    //注意，这里也要分前面的b是否匹配以及通配符的情况

                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') //x*的x匹配上了，或者是通配符加星号 .* 形式
                    {
                        //注意，即使匹配上了，也要看dp[i][j - 2]
                        //因为对于a和aa*的这种情况，由于字母重复导致误认为要用到后面这组“a*”进行匹配，实际上归到没匹配上的情况里去
                        dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                    }
                    else //证明这次的x*的x没匹配上，可以丢掉
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
                //3.不匹配情况：普通字母匹配且不相等，直接返回false
                //这个一定要摆在最后面！否则*号判断会被这个覆盖
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[slength][plength];
    }
};
// @lc code=end
