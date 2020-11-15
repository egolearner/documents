/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (36.02%)
 * Likes:    4622
 * Dislikes: 208
 * Total Accepted:    552.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where "adjacent" cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const char* w, int i, int j) {
        if (*w == '\0') {
            return true;
        }
        int dir[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == *w && !visited[i][j]) {
            visited[i][j] = true;
            for (int k = 0; k < 4; k++) {
                if(dfs(board, visited, w+1, i+dir[k][0], j+dir[k][1])) {
                    return true;
                }
            }
            visited[i][j] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, visited, word.c_str(), i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

