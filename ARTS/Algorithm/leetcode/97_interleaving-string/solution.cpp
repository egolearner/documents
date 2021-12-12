/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (33.66%)
 * Likes:    2936
 * Dislikes: 156
 * Total Accepted:    223.1K
 * Total Submissions: 659.5K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving
 * of s1 and s2.
 *
 * An interleaving of two strings s and t is a configuration where they are
 * divided into non-empty substrings such that:
 *
 *
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
 * t3 + s3 + ...
 *
 *
 * Note: a + b is the concatenation of strings a and b.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: s1 = "", s2 = "", s3 = ""
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1, s2, and s3 consist of lowercase English letters.
 *
 *
 *
 * Follow up: Could you solve it using only O(s2.length) additional memory
 * space?
 *
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t l1 = s1.length(), l2 = s2.length();
        if (l1 + l2 != s3.size()) {
            return false;
        }
        if (s1.empty()) {
            return s2 == s3;
        }
        if (s2.empty()) {
            return s1 == s3;
        }
        vector<vector<bool>> dp{l1, vector<bool>(l2, false)};
        for (size_t i = 0; i < l1 && s1[i] == s3[i]; i++) {
            dp[i][0] = true;
        }
        for (size_t j = 0; j < l2 && s2[j] == s3[j]; j++) {
            dp[0][j] = true;
        }
        for (size_t i = 0; i < l1; i++) {
            for (size_t j = 0; j < l2; j++) {
                size_t p = i + j + 1;
                if (i > 0) {
                    dp[i][j] = dp[i][j] || (dp[i-1][j] && s3[p] == s1[i]);
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j] || (dp[i][j-1] && s3[p] == s2[j]);
                }
            }
        }
        return dp[l1-1][l2-1];
    }
};
// @lc code=end

// XXX 处理空串有问题
