#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //定义存放key-num的hash地图
        map<int, int> key_num_map;

        //定义返回数组(现在是一个空数组)
        vector<int> reloc;

        //遍历一次数组，如果数组中存在target-nums[i]的数，则直接返回
        for (int i = 0; i < nums.size(); i++)
        {
            int tg = target - nums[i];
            vector<int>::iterator result = find(nums.begin(), nums.end(), tg);
            //返回找到元素的位置
            int loc = result - nums.begin();
            //当目前找到的数在数组中且不是同一个数时（同一个数不能用两遍）
            if (result == nums.end() || loc == i)
            {
                continue;
            }
            else if (loc != i)
            {
                reloc.push_back(i);
                reloc.push_back(loc);
                return reloc;
            }
        }

        //不存在这样的数对，返回空
        return {};
    }
};