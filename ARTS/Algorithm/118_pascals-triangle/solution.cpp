/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (53.40%)
 * Likes:    1840
 * Dislikes: 120
 * Total Accepted:    419K
 * Total Submissions: 784.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0){
            return res;
        }
        res.reserve(numRows);
        res.push_back({1});
        for(--numRows; numRows; --numRows) {
            auto &b = res.back();
            res.push_back({});
            auto& cur = res.back();
            cur.reserve(b.size()+1);
            cur.push_back(1);
            for (int i = 0; i < int(b.size())-1; i++) {
                cur.push_back(b[i]+b[i+1]);
            }
            cur.push_back(1);
        }
        return res;
    }
};
// @lc code=end

