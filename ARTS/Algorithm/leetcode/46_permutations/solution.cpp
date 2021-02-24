/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (64.68%)
 * Likes:    4590
 * Dislikes: 112
 * Total Accepted:    676.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
public:
    void backtrack(size_t i, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (size_t j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(i+1, nums, res);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (!nums.empty()) {
            backtrack(0, nums, res);
        }
        return res;
    }
};
// @lc code=end

