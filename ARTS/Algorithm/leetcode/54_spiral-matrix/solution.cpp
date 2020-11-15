/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (34.57%)
 * Likes:    2973
 * Dislikes: 611
 * Total Accepted:    418.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // XXX 没有判断
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int row = matrix.size(), col = matrix[0].size();
        int mr = 0, mc = 0, mmr = row-1, mmc = col -1;
        int i = 0, j = 0;
        vector<int> v;
        v.reserve(row*col);
        while (true) {
            for (i = mr, j = mc; j <= mmc; j++) {
                v.push_back(matrix[i][j]);
            }
            ++mr;
            if (mr > mmr) {
                break;
            }
            for (i = mr, j = mmc; i <= mmr; i++) {
                v.push_back(matrix[i][j]);
            }
            --mmc;
            if (mc > mmc) {
                break;
            }
            for (i = mmr, j = mmc; j >= mc; j--) {
                v.push_back(matrix[i][j]);
            }
            --mmr;
            if (mr > mmr) {
                break;
            }
            for (i = mmr, j = mc; i >= mr; i--) {
                v.push_back(matrix[i][j]);
            }
            ++mc;
            if (mc > mmc) {
                break;
            }
        }
        return v;
    }
};
// @lc code=end

