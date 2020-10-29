/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (36.68%)
 * Likes:    2302
 * Dislikes: 170
 * Total Accepted:    365K
 * Total Submissions: 990.7K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [], target = 0
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 0 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int br = 0, er = matrix.size()-1;
        int mid = 0;
        while (br < er) {
            mid = er - (er-br)/2;
            if (matrix[mid][0] > target) {
                er = mid-1;
            } else if (matrix[mid][0] < target) {
                br = mid;
            } else {
                return true;
            }
        }
        int row = er;
        int bc = 0, ec = matrix[0].size()-1;
        while (bc <= ec) {
            mid = bc + (ec-bc)/2;
            if (matrix[row][mid] > target) {
                ec = mid-1;
            } else if (matrix[row][mid] < target) {
                bc = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
/* 另一种思路
    //Just simply convert the 2D matrix to 1D array.
    bool searchMatrix01(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = row>0 ? matrix[0].size() : 0;

        int len = row * col;
        int low = 0, high = len -1;
        while (low <= high) {

            int mid = low + (high - low) / 2;
            int r = mid / col;
            int c = mid % col;

            int n = matrix[r][c];
            if (n == target) return true;
            if (n < target) low = mid+1;
            else high = mid -1;
        }
        return false;
    }
*/

