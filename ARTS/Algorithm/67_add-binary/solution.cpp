/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (45.89%)
 * Likes:    2165
 * Dislikes: 297
 * Total Accepted:    516.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 *
 *
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int ia = a.size()-1, ib = b.size()-1;
        int carry = 0;
        while (ia >= 0 || ib >= 0) {
            int sum = carry;
            if (ia >= 0) {
                sum += a[ia]-'0';
                --ia;
            }
            if (ib >= 0) {
                sum += b[ib]-'0';
                --ib;
            }
            res.append(1, "01"[sum&1]);
            carry = sum>>1;
        }
        if (carry) {
            res.append(1, '1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

