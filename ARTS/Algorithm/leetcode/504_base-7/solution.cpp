/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (46.34%)
 * Likes:    265
 * Dislikes: 154
 * Total Accepted:    60K
 * Total Submissions: 129.4K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 *
 * Input: 100
 * Output: "202"
 *
 *
 *
 * Example 2:
 *
 * Input: -7
 * Output: "-10"
 *
 *
 *
 * Note:
 * The input will be in range of [-1e7, 1e7].
 *
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        int anum = abs(num);
        bool minus = anum != num;
        string res;
        do {
            res.push_back('0' + anum % 7);
            anum /= 7;
        } while (anum);
        if (minus) {
            res.push_back('-');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

