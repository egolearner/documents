/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (54.87%)
 * Likes:    1229
 * Dislikes: 121
 * Total Accepted:    210.2K
 * Total Submissions: 381.8K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int row = matrix.size(), col = matrix[0].size();
        int mr = 0, mc = 0, mmr = row-1, mmc = col -1;
        int i = 0, j = 0;
        int v = 1;
        while (true) {
            for (i = mr, j = mc; j <= mmc; j++) {
                matrix[i][j] = v++;
            }
            ++mr;
            if (mr > mmr) {
                break;
            }
            for (i = mr, j = mmc; i <= mmr; i++) {
                matrix[i][j] = v++;
            }
            --mmc;
            if (mc > mmc) {
                break;
            }
            for (i = mmr, j = mmc; j >= mc; j--) {
                matrix[i][j] = v++;
            }
            --mmr;
            if (mr > mmr) {
                break;
            }
            for (i = mmr, j = mc; i >= mr; i--) {
                matrix[i][j] = v++;
            }
            ++mc;
            if (mc > mmc) {
                break;
            }
        }
        return matrix;
    }
};
// @lc code=end

