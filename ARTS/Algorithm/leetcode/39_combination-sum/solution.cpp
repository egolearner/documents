/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (57.71%)
 * Likes:    4731
 * Dislikes: 130
 * Total Accepted:    621.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 *
 *
 * Example 5:
 *
 *
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 *
 *
 */

// @lc code=start
class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, int i, vector<pair<int,int>>& cur, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back({});
            for (auto c : cur) {
                res.back().insert(res.back().end(), c.first, c.second);
            }
            return;
        }
        if (i == candidates.size() || candidates[i] > target) {
            return;
        }
        combinationSum(candidates, target, i+1, cur, res);
        for (int j = 1; j <= target / candidates[i]; j++) {
            cur.push_back(make_pair(j, candidates[i]));
            combinationSum(candidates, target-j*candidates[i], i+1, cur, res);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<pair<int,int>> cur;
        combinationSum(candidates, target, 0, cur, res);
        return res;
    }
};
// @lc code=end

/* 1st submit
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int i) {
        vector<vector<int>> res;
        if(target == 0) {
            res.push_back({});
            return res;
        }
        if (i == candidates.size() || candidates[i] > target) {
            return res;
        }
        for (int j = 0; j <= target / candidates[i]; j++) {
            for (auto x : combinationSum(candidates, target-j*candidates[i], i+1)) {
                res.push_back(vector<int>(j, candidates[i]));
                res.back().insert(res.back().end(), x.begin(), x.end());
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum(candidates, target, 0);
    }
};
*/

