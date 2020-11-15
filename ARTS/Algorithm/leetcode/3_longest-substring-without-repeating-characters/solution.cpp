/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (30.71%)
 * Likes:    11316
 * Dislikes: 626
 * Total Accepted:    1.8M
 * Total Submissions: 5.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 * Example 4:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ci[257] = {0};
        int cnt = 0;
        int mcnt = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (ci[s[i]] == 0) {
                ++cnt;
                ci[s[i]] = i+1;
                mcnt = max(cnt, mcnt);
            } else {
                auto ei = ci[s[i]]-1;
                for (size_t ii = i - cnt; ii < ei; ++ii, --cnt) {
                    // XXX ci[s[i]]
                    ci[s[ii]] = 0;
                }
                ci[s[i]] = i+1;
            }
        }
        return mcnt;
    }
};
// @lc code=end

/* XXX 获取上一个不重复的下标即可，不需要清零
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<int> hash(256, -1);
        int start = -1, res = 0;
        for (int i = 0; i < n; i ++){
            start = hash[s[i]] > start ? hash[s[i]] : start;
            res = max(res, i - start);
            hash[s[i]] = i;
        }
        return res;
    }
};
*/

