/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (57.91%)
 * Likes:    1921
 * Dislikes: 81
 * Total Accepted:    165.5K
 * Total Submissions: 285.8K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * Find this single element that appears only once.
 *
 * Follow up: Your solution should run in O(log n) time and O(1) space.
 *
 *
 * Example 1:
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: nums = [3,3,7,7,10,11,11]
 * Output: 10
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int begin = 0, end = nums.size()-1;
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (mid == 0) {
                if (nums[mid] != nums[mid+1]) {
                    return nums[mid];
                }
                begin = mid+2;
            } else if (mid == nums.size()-1) {
                if (nums[mid] != nums[mid-1]) {
                    return nums[mid];
                }
                end = mid-2;
            } else {
                if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                    return nums[mid];
                }
                if (nums[mid] == nums[mid-1]) {
                    --mid;
                }
                if ((mid - begin) % 2 == 0) {
                    begin = mid+2;
                } else {
                    end = mid-1;
                }
            }
        }
        // can not go here
        return -1;
    }
};
// @lc code=end

