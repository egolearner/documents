/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.11%)
 * Likes:    2614
 * Dislikes: 157
 * Total Accepted:    521.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minsum = INT_MIN;
        int absminsum = INT_MAX;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int low = i+1;
            int high = nums.size()-1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum > target) {
                    --high;
                } else if (sum < target) {
                    ++low;
                } else {
                    return target;
                }
                if (abs(target-sum) < absminsum) {
                    minsum = sum;
                    absminsum = abs(target-sum);
                }
            }
        }
        return minsum;
    }
};
// @lc code=end

