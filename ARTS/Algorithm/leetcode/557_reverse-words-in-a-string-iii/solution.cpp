/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (70.71%)
 * Likes:    1293
 * Dislikes: 98
 * Total Accepted:    236.4K
 * Total Submissions: 330.7K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 *
 *
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 *
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        char* begin = &s[0];
        char* end = &s[0];
        while (true) {
            if (*end == ' ') {
                reverse(begin, end);
                ++end;
                begin = end;
            } else if (*end == '\0') {
                reverse(begin, end);
                break;
            } else {
                ++end;
            }
        }
        return s;
    }
};
// @lc code=end

