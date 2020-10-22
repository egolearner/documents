/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (36.53%)
 * Likes:    4256
 * Dislikes: 168
 * Total Accepted:    576.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * Follow up: Could you write an algorithm with O(log n) runtime complexity?
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int low = 0, high = nums.size()-1;
        int start=-1, end=-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (nums[mid] > target) {
                high = mid-1;
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                if (mid > 0 && nums[mid-1] == target) {
                    high = mid-1;
                } else {
                    start = mid;
                    break;
                }
            }
        }
        if (start == -1) {
            return {-1, -1};
        }
        low = start;
        high = nums.size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (nums[mid] > target) {
                high = mid-1;
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                if (mid < nums.size()-1 && nums[mid+1] == target) {
                    low = mid+1;
                } else {
                    end = mid;
                    break;
                }
            }
        }
        return {start, end};
    }
};
// @lc code=end

