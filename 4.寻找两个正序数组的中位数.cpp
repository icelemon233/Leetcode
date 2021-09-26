/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution
{
public:
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        // 定义两个数组的长度
        int m = nums1.size();
        int n = nums2.size();

        //定义两个数组的左指针，均放在[0]的位置
        int index1 = 0, index2 = 0;

        while (true)
        {
            // 边界情况
            // index不可能超过m或n（因为newIndex检测到越界时，只会返回数组最后一个元素）
            // 如果index恰好为数组长度，证明这个数组已经被“删完了”，那么我们可以立刻返回另一个数组中第k大的元素，这个元素就是中位数
            // 如果不明白，用极端例子解释，nums1=[]，nums2=[1,2,3]，此时k= (nums1.size() + nums2.size() + 1)/2
            // 即用这个式子算出来的k就是我们数学上这个中位数的位置，此处k=2
            // 而c++下标从0开始，所以应该减去1，得到了以下的操作
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }

            //如果算到k=1时没有一个数组被删除完，意味着当前指针指向的这两个数最小的那个就是中位数（数学知识）
            if (k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            /* 
            如果index+k/2-1没有越界（数组长度分别为m-1和n-1），就返回index+k/2-1下标
            如果越界，就返回最后一个元素下标
            */
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);

            // 取出这两个位置的元素
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];

            /*
            A[k/2−1]<B[k/2−1]：证明A[0]到A[k/2−1]必然小于中位数，全部排除
            A[k/2−1]>B[k/2−1]：证明B[0]到B[k/2−1]必然小于中位数，全部排除
            A[k/2−1]=B[k/2−1]：可以排除A[0]到A[k/2−1]，也可以排除B[0]到B[k/2−1]（2选1）
            */
            if (pivot1 <= pivot2)
            {
                //“删除”index到newIndex之间的元素，让新的index指向newIndex的下一个位置
                //实际上就是移动指针操作，逻辑上忽略前面的元素
                //下面同理
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 定义总长度
        int totalLength = nums1.size() + nums2.size();

        // 奇数个元素（totalLength为什么要加1，上面已经说明，这里是数学上的中位数位置，而不是下标的位置）
        if (totalLength % 2 == 1)
        {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }

        // 偶数个元素
        else
        {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end
