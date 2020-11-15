/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (44.43%)
 * Likes:    1376
 * Dislikes: 738
 * Total Accepted:    280.9K
 * Total Submissions: 631.1K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appeared at most twice and return the new length.
 *
 * Do not allocate extra space for another array; you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * Clarification:
 *
 * Confused why the returned value is an integer, but your answer is an array?
 *
 * Note that the input array is passed in by reference, which means a
 * modification to the input array will be known to the caller.
 *
 * Internally you can think of this:
 *
 *
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 *
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3]
 * Output: 5, nums = [1,1,2,2,3]
 * Explanation: Your function should return length = 5, with the first five
 * elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what
 * you leave beyond the returned length.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,1,1,1,1,2,3,3]
 * Output: 7, nums = [0,0,1,1,2,3,3]
 * Explanation: Your function should return length = 7, with the first seven
 * elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively. It
 * doesn't matter what values are set beyond the returned length.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in ascending order.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int binary_search_greater(vector<int>&nums, int begin, int end, int value) {
        while (begin < end) {
            int mid = begin + (end-begin)/2;
            if (nums[mid] <= value) {
                begin = mid+1;
            } else {
                end = mid;
            }
        }
        return begin;
    }
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int size = 0;
        for (int i = 0, ni = 0; i < nums.size(); i = ni) {
            ni = binary_search_greater(nums, i, nums.size(), nums[i]);
            if (ni - i >= 2) {
                nums[size] = nums[size+1] = nums[i];
                size += 2;
            } else {
                nums[size] = nums[i];
                size ++;
            }
        }
        return size;
    }
};
// @lc code=end

