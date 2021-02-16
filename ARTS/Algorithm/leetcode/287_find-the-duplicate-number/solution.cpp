/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (56.29%)
 * Likes:    5734
 * Dislikes: 644
 * Total Accepted:    396.9K
 * Total Submissions: 704.8K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 *
 * There is only one duplicate number in nums, return this duplicate number.
 *
 * Follow-ups:
 *
 *
 * How can we prove that at least one duplicate number must exist in nums? 
 * Can you solve the problem without modifying the array nums?
 * Can you solve the problem using only constant, O(1) extra space?
 * Can you solve the problem with runtime complexity less than O(n^2)?
 *
 *
 *
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * Example 3:
 * Input: nums = [1,1]
 * Output: 1
 * Example 4:
 * Input: nums = [1,1,2]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 3 * 10^4
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums.size();
        int slow = nums.size() ;
        do {
            slow = nums[slow-1];
            fast = nums[nums[fast-1]-1];
        } while (fast != slow);
        fast = nums.size();
        while (fast != slow) {
            fast = nums[fast-1];
            slow = nums[slow-1];
        }
        return nums[slow-1];
    }
};
// @lc code=end

// XXX 想不出来符合题目要求的解
// 1. O(nlogn) 计算mid，根据前后两部分区间的个数确定在哪个区间
// 2. 把数字当作链表的next指针，变为求有环链表的起点问题
