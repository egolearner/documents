/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (64.81%)
 * Likes:    1920
 * Dislikes: 120
 * Total Accepted:    176.1K
 * Total Submissions: 271K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * Follow up: Your algorithm should run in linear runtime complexity. Could you
 * implement it using only constant space complexity?
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 30000
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto i : nums) {
            x ^= i;
        }
        int i = 0;
        for (i = 0; i < 32 && (x & (1<<i)) == 0; i++) {
        }
        int fx = 0, sx = 0;
        for (auto n : nums) {
            if ((n & (1<<i)) == 0) {
                fx ^= n;
            } else {
                sx ^= n;
            }
        }
        return {fx, sx};
    }
};
// @lc code=end

