/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (47.55%)
 * Likes:    4584
 * Dislikes: 452
 * Total Accepted:    679.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void letterCombinations(const char *cur,         string& s) {
        if(*cur == '\0') {
            return res.push_back(s);
        }
        for (auto c : letters[*cur-'2']) {
            s.append(1, c);
            letterCombinations(cur+1, s);
            s.resize(s.size()-1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        string s;
        letterCombinations(&digits[0], s);
        return res;
    }
};
// @lc code=end

