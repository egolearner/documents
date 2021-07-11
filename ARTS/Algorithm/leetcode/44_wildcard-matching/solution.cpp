/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (25.72%)
 * Likes:    3199
 * Dislikes: 154
 * Total Accepted:    313.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*' where:
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "adceb", p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 *
 *
 * Example 5:
 *
 *
 * Input: s = "acdcb", p = "a*c?b"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        const char* ss = &s[0], *pp = &p[0];
        const char* last_star = nullptr, *star_match_pos = nullptr;
        while (*ss) {
            if (*ss == *pp || *pp == '?') {
                ss++;
                pp++;
                continue;
            }
            if (*pp == '*') {
                last_star = pp;
                pp++;
                star_match_pos = ss;
                continue;
            }
            if (last_star) {
                pp = last_star+1;
                ss = ++star_match_pos;
                continue;
            }
            return false;
        }
        while (*pp == '*') {
            pp++;
        }
        return *pp == '\0';
    }
};
// @lc code=end

/*
XXX: *有特殊性，如果前面的*能够覆盖后面的*之前的字符，则不需要再往前回溯
TLE
class Solution {
public:
    bool isMatch(string& s, size_t si, string& p, size_t pi) {
        char pc = p[pi];
        if (pc == '?') {
            return si < s.size() ? isMatch(s, si+1, p, pi+1) : false;
        }
        if (pc == '*') {
            if (isMatch(s, si, p, pi+1)) {
                return true;
            }
            for (size_t i = 0; i < s.size() - si; i++) {
                if (isMatch(s, si+i+1, p, pi+1)) {
                    return true;
                }
            }
            return false;
        }
        if (pc == '\0') {
            return si == s.size();
        }
        if (pc == s[si]) {
            return isMatch(s, si+1, p, pi+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};
*/

