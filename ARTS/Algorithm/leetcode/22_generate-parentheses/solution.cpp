/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (66.40%)
 * Likes:    8631
 * Dislikes: 354
 * Total Accepted:    787.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
class Solution {
public:
    void gen(int n, int diff, vector<string>& res, std::string& cur) {
        if (n == 0 && diff == 0) {
            res.push_back(cur);
            return;
        }
        if (diff > 0) {
            cur.push_back(')');
            gen(n, diff-1, res, cur);
            cur.pop_back();
        }
        if (n > 0) {
            cur.push_back('(');
            gen(n-1, diff+1, res, cur);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> res;
        gen(n, 0, res, cur);
        return res;
    }
};
// @lc code=end

