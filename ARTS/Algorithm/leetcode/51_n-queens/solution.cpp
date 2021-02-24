/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (47.69%)
 * Likes:    2666
 * Dislikes: 98
 * Total Accepted:    241.2K
 * Total Submissions: 486.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isvalid(vector<string>&board, int r, int c) {
        for (size_t i = 0; i < r; i++) {
            if (board[i][c] == 'Q') {
                return false;
            }
        }
        for (int row = r-1, col = c+1; row >= 0 && col < board.size(); row--, col++) {
            if (board[row][col] == 'Q') {
                return false;
            }
        }
        for (int row = r-1, col = c-1; row >= 0 && col >= 0; row--, col--) {
            if (board[row][col] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backtrack(size_t row, vector<string>& board, vector<vector<string>>& res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (size_t c = 0; c < board.size(); c++) {
            if (isvalid(board, row, c)) {
                board[row][c] = 'Q';
                backtrack(row+1, board, res);
                board[row][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board{(size_t)n, string((size_t)n, '.')};
        vector<vector<string>> res;
        backtrack(0, board, res);
        return res;
    }
};
// @lc code=end

//XXX 按行递归
