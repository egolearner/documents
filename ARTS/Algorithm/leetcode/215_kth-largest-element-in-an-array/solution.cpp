/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (56.33%)
 * Likes:    4409
 * Dislikes: 290
 * Total Accepted:    718.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */

#include <vector>
#include <cstdio>
using namespace std;
// @lc code=start
class Solution {
public:
    int kth(int* begin, int *end, int k) {
        if (begin >= end) {
            return -1;
        }
        int first = *begin;
        int *small = begin+1;
        int *big = end-1;
        while (small<=big) {
            // XXX 没有判断small <= big
            while (small <= big && *small<=first) {
                ++small;
            }
            // XXX 没有判断small <= big
            while (small <= big && *big > first) {
                --big;
            }
            if (small > big) {
                break;
            }
            swap(*small, *big);
            ++small;
            --big;
        }
        --small;
        // printf("%d %d\n", (int)(small-begin), (int)(end-small));
        swap(*begin, *small);
        int pivot_index = distance(small, end);
        if (pivot_index == k) {
            return *small;
        }
        if (pivot_index > k) {
            // XXX 没有small+1
            return kth(small+1, end, k);
        }
        return kth(begin, small, k-pivot_index);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return kth(&nums[0], &nums[0]+nums.size(), k);
    }
};
// @lc code=end
int main() {
    vector<int> v{2, 1};
    Solution s;
    printf("%d\n", s.findKthLargest(v, 1));
    return 0;
}
