/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (34.83%)
 * Likes:    5110
 * Dislikes: 368
 * Total Accepted:    540.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i][j] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t curMax = 0;
        for (size_t i = 0; i < nums.size() && curMax >= i; i++) {
            curMax = max(curMax, i+nums[i]);
        }
        return curMax >= nums.size()-1;
    }
};
// @lc code=end

/* XXX 一开始TLE了
    bool canJump(vector<int>& nums) {
        vector<int> visited(nums.size(), false);
        stack<int> queue;
        queue.push(nums.size()-1);
        visited[nums.size()-1] = true;
        while (!queue.empty() && !visited[0]) {
            int cur = queue.top();
            queue.pop();
            for (int i = cur-1; i >= 0; i--) {
                if (!visited[i] && nums[i] >= cur-i) {
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
        return visited[0];
    }
*/

