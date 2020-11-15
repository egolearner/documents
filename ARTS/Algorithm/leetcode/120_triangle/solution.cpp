/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (44.78%)
 * Likes:    2383
 * Dislikes: 266
 * Total Accepted:    268.9K
 * Total Submissions: 598.2K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> buf(triangle.size());
        buf[0] = triangle[0][0];
        for (size_t i = 1; i < triangle.size(); i++) {
            int prev = buf[0];
            buf[0] = prev + triangle[i][0];
            for (size_t j = 1; j < triangle[i].size()-1; j++) {
                int res = min(prev, buf[j])+triangle[i][j];
                prev = buf[j];
                buf[j] = res;
            }
            buf[triangle[i].size()-1] = prev + triangle[i][triangle[i].size()-1];
        }
        int res = INT_MAX;
        for (auto i : buf) {
            res = min(i, res);
        }
        return res;
    }
};
// @lc code=end

/* XXX 从下往上dp，可以直接返回结果。而且不需要考虑异常分支。
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 0) return 0;
        int n = triangle[m - 1].size();
        if(n == 0) return 0;
        vector<int> dp(n + 1);
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
*/
