/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (50.85%)
 * Likes:    2936
 * Dislikes: 92
 * Total Accepted:    418.4K
 * Total Submissions: 822.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<pair<int,int>>& can, int target, vector<vector<int>>&res, vector<int>& cur, int index) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || index >= can.size()) {
            return;
        }
        int value = can[index].first;
        int limit = min(can[index].second, target / value);
        dfs(can, target, res, cur, index+1);
        for (int i = 1; i <= limit; i++) {
            cur.push_back(value);
            target -= value;
            dfs(can, target, res, cur, index+1);
        }
        cur.resize(cur.size()-limit);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<pair<int,int>> can;
        int prev = candidates[0];
        int count = 1;
        for (size_t i = 1; i <candidates.size(); i++){
            if (prev == candidates[i]) {
                count++;
            } else {
                can.push_back({prev, count});
                prev = candidates[i];
                count=1;
            }
        }
        can.push_back({prev, count});
        vector<vector<int>> res;
        vector<int> cur;
        dfs(can, target, res, cur, 0);
        return res;
    }
};
// @lc code=end

