/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (51.16%)
 * Likes:    1098
 * Dislikes: 206
 * Total Accepted:    332.1K
 * Total Submissions: 648.8K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th row of the Pascal's
 * triangle.
 *
 * Notice that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 *
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= rowIndex <= 40
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p;
        vector<int> c;
        p.reserve(rowIndex+1);
        c.reserve(rowIndex+1);
        p.push_back(1);
        for (; rowIndex; rowIndex--) {
            c.push_back(1);
            for (int i = 0; i < p.size()-1; i++) {
                c.push_back(p[i]+p[i+1]);
            }
            c.push_back(1);
            swap(p, c);
            c.clear();
        }
        return p;
    }
};
// @lc code=end

