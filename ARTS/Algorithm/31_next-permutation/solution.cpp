/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.89%)
 * Likes:    4089
 * Dislikes: 1457
 * Total Accepted:    415.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ri = -1;
        for (int i = nums.size()-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                ri = i;
                break;
            }
        }
        if (ri == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int lb = -1;
        for (int j = nums.size()-1; j >= ri; j--) {
            if (nums[j] > nums[ri-1]) {
                lb = j;
                break;
            }
        }
        swap(nums[ri-1], nums[lb]);
        reverse(nums.begin()+ri, nums.end());
    }
};
// @lc code=end

