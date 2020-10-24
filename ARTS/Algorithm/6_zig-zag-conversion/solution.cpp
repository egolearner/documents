/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (36.91%)
 * Likes:    1916
 * Dislikes: 5039
 * Total Accepted:    499.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
 * Example 3:
 *
 *
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.length() <= 1) {
            return s;
        }
        vector<pair<int, int>> dis(numRows);
        int dis0 = (numRows-1)*2;
        dis[0] = {dis0, dis0};
        dis[numRows-1] = {dis0, dis0};
        for (int i = 2; i < numRows; i++) {
            dis[i-1] = {(numRows-i)*2, (i-1)*2};
        }
        string res;
        res.reserve(s.length());
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); ) {
                res.push_back(s[j]);
                j += dis[i].first;
                if (j >= s.length()) {
                    break;
                }
                res.push_back(s[j]);
                j += dis[i].second;
            }
        }
        return res;
    }
};
// @lc code=end

