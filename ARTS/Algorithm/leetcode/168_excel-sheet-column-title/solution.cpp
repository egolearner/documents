/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (31.32%)
 * Likes:    1388
 * Dislikes: 266
 * Total Accepted:    231.3K
 * Total Submissions: 738.2K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 *
 * For example:
 *
 *
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB
 * ⁠   ...
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "A"
 *
 *
 * Example 2:
 *
 *
 * Input: 28
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: 701
 * Output: "ZY"
 *
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string digits = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res;
        while (n) {
            n--;
            auto c = n % 26;
            n /= 26;
            res.push_back(digits[c]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

