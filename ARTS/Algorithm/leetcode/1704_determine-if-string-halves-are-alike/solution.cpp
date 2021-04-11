/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 *
 * https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
 *
 * algorithms
 * Easy (77.14%)
 * Likes:    265
 * Dislikes: 24
 * Total Accepted:    51.4K
 * Total Submissions: 64.7K
 * Testcase Example:  '"book"'
 *
 * You are given a string s of even length. Split this string into two halves
 * of equal lengths, and let a be the first half and b be the second half.
 *
 * Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
 * 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
 * lowercase letters.
 *
 * Return true if a and b are alike. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "book"
 * Output: true
 * Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
 * Therefore, they are alike.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "textbook"
 * Output: false
 * Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
 * Therefore, they are not alike.
 * Notice that the vowel o is counted twice.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "MerryChristmas"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: s = "AbCdEfGh"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= s.length <= 1000
 * s.length is even.
 * s consists of uppercase and lowercase letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool is_vowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            return true;
        }
        return false;
    }
    int count_vowel(const string& s, size_t begin, size_t end) {
        int c = 0;
        for (auto i = begin; i < end; ++i) {
            if (is_vowel(s[i])) {
                ++c;
            }
        }
        return c;
    }
    bool halvesAreAlike(string s) {
        return count_vowel(s, 0, s.size()/2) == count_vowel(s, s.size()/2, s.size());
    }
};
// @lc code=end

