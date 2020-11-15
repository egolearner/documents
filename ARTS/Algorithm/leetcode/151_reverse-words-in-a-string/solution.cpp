/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (22.48%)
 * Likes:    1299
 * Dislikes: 3030
 * Total Accepted:    461.2K
 * Total Submissions: 2M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "  Bob    Loves  Alice   "
 * Output: "Alice Loves Bob"
 *
 *
 * Example 5:
 *
 *
 * Input: s = "Alice does not even like bob"
 * Output: "bob like even not does Alice"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 *
 * Follow up:
 *
 *
 * Could you solve it in-place with O(1) extra space?
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    string reverseWordsTwoReverse(string s) {
        if (s.empty()) {
            return s;
        }
        char* wb = &s[0];
        char* we = &s[0];
        bool find_begin = false;
        for (auto c : s) {
            if (c == ' ') {
                if (find_begin) {
                    reverse(wb, we);
                    *we++ = c;
                    find_begin = false;
                }
                continue;
            }
            if (!find_begin) {
                wb = we;
                find_begin = true;
            }
            *we++ = c;
        }
        if (*(we-1) == ' ') {
            --we;
        }
        if (find_begin) {
            reverse(wb, we);
        }
        s.resize(we-&s[0]);
        reverse(s.begin(), s.end());
        return s;
    }
    string reverseWords(string s) {
        if (s.empty()) {
            return {};
        }
        string res;
        auto end = s.size();
        auto start = s.size();
        while (true) {
            end = s.find_last_not_of(' ', start);
            if (end == string::npos) {
                break;
            }
            start = s.find_last_of(' ', end);
            if (start == string::npos) {
                res.append(s.c_str(), s.c_str()+end+1);
                break;
            }
            res.append(s.c_str()+start+1, s.c_str()+end+1);
            res.append(" ");
        }
        if (res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end

