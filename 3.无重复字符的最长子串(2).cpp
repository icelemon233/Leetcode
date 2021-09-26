/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] ���ظ��ַ�����Ӵ�
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //�쳣�����ų�
        if (s.size() == 0)
        {
            return 0;
        }
        else if (s.size() == 1)
        {
            return 1;
        }

        // �Թ�ϣ��Ϊ������set
        unordered_set<char> subs;

        // lpΪ��ָ�룬rpΪ��ָ�룬subslengthΪ��ǰ�Ӵ����ȣ�maxlengthΪ����Ӵ�����
        int lp = 0, rp = 1, maxlength = 0;

        //��һ���ַ������Ӵ�
        subs.insert(s[0]);

        while (rp < s.size())
        {
            //����ҵ���֮ǰsubs�е��ַ����ظ���
            if (subs.find(s[rp]) != subs.end())
            {
                //��������ߵ��ַ�����ָ���1
                subs.erase(s[lp]);
                lp++;
            }
            //û���ظ������
            else
            {
                //��ǰ��ָ��ָ���Ԫ����set
                subs.insert(s[rp]);

                //��ָ��+1
                rp++;

                //ȷ��һ����󳤶�
                maxlength = (subs.size() > maxlength) ? subs.size() : maxlength;
            }
        }

        return maxlength;
    }
};

// @lc code=end
