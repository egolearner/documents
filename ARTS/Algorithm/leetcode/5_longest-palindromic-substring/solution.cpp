/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.73%)
 * Likes:    8368
 * Dislikes: 588
 * Total Accepted:    1.1M
 * Total Submissions: 3.6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a"
 * Output: "a"
 *
 *
 * Example 4:
 *
 *
 * Input: s = "ac"
 * Output: "a"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters (lower-case and/or
 * upper-case),
 *
 *
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        int max_len = 1;
        auto maxl = [&](int i) {
            if (i < 0 || i >= (int)s.size()) {
                return -1;
            }
            int half_size = max_len / 2;
            if (s.size()-i < half_size || i+1 < half_size) {
                return -1;
            }
            int len_odd = 1;
            for (int l = i-1, r = i+1; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++) {
                len_odd += 2;
            }
            int len_even = 0;
            for (int l = i, r = i+1; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++) {
                len_even += 2;
            }
            return max(len_odd, len_even);
        };
        int mid = s.size()/2;
        int mid_index = 0;
        for (int l = mid, r = mid+1; l >= 0 || r < s.size(); l--, r++) {
            int ml = maxl(l);
            if (ml > max_len) {
                max_len = ml;
                mid_index = l;
            }
            int mr = maxl(r);
            if (mr > max_len) {
                max_len = mr;
                mid_index = r;
            }
        }
        return s.substr(mid_index - max_len / 2 + (max_len%2==0), max_len);
    }
};
// @lc code=end

