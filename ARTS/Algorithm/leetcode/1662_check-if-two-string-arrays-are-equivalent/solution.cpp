/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 *
 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
 *
 * algorithms
 * Easy (82.64%)
 * Likes:    319
 * Dislikes: 76
 * Total Accepted:    74.7K
 * Total Submissions: 90.3K
 * Testcase Example:  '["ab", "c"]\n["a", "bc"]'
 *
 * Given two string arrays word1 and word2, return true if the two arrays
 * represent the same string, and false otherwise.
 *
 * A string is represented by an array if the array elements concatenated in
 * order forms the string.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation:
 * word1 represents string "ab" + "c" -> "abc"
 * word2 represents string "a" + "bc" -> "abc"
 * The strings are the same, so return true.
 *
 * Example 2:
 *
 *
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 10^3
 * 1 <= word1[i].length, word2[i].length <= 10^3
 * 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
 * word1[i] and word2[i] consist of lowercase letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        size_t i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        while (i1 < word1.size() && i2 < word2.size()) {
            if (j1 >= word1[i1].size()) {
                i1++;
                j1 = 0;
                continue;
            }
            if (j2 >= word2[i2].size()) {
                i2++;
                j2 = 0;
                continue;
            }
            if (word1[i1][j1] != word2[i2][j2]) {
                return false;
            }
            j1++;
            j2++;
        }
        return i1 >= word1.size() && i2+1 == word2.size()  && j2 == word2[i2].size();
    }
};
// @lc code=end

