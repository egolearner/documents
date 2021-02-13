/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (34.26%)
 * Likes:    2019
 * Dislikes: 876
 * Total Accepted:    324.8K
 * Total Submissions: 944.5K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 *
 *
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        auto to = [](char c) {return c-'0';};
        string res;
        int carry = 0;
        for (int i2 = num2.size()-1; i2 >= 0; --i2) {
            for (int i1 = num1.size()-1, ind=num2.size()-1-i2; i1 >= 0; i1--, ind++) {
                if (res.size() < ind+1) {
                    res.resize(ind+1, '0');
                }
                int num = to(num1[i1])*to(num2[i2])+carry+to(res[ind]);
                carry = num / 10;
                res[ind] = '0' + num%10;
            }
            for (int ind = num2.size()-i2 + num1.size() - 1; carry > 0; ind++) {
                if (res.size() < ind+1) {
                    res.resize(ind+1, '0');
                }
                int num = carry + to(res[ind]);
                carry = num / 10;
                res[ind] = '0' + num%10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

