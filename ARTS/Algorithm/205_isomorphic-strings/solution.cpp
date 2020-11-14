/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (40.03%)
 * Likes:    1651
 * Dislikes: 406
 * Total Accepted:    323K
 * Total Submissions: 804.9K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * Example 1:
 *
 *
 * Input: s = "egg", t = "add"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Example 3:
 *
 *
 * Input: s = "paper", t = "title"
 * Output: true
 *
 * Note:
 * You may assume both s and t have the same length.
 *
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[256] = {0}, rev[256] = {0};
        for (size_t i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            if (map[c1] == 0) {
                map[c1] = c2;
                if (rev[c2] != 0) {
                    return false;
                }
                rev[c2] = c1;
            } else {
                if (map[c1] != c2 || rev[c2] != c1) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

