/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (47.72%)
 * Likes:    6300
 * Dislikes: 74
 * Total Accepted:    381.8K
 * Total Submissions: 790.1K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following three operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t r = word2.size() + 1;
        vector<int> dp((word1.size()+1)*(word2.size()+1), 0);
        for (size_t i = 1; i <=word1.size(); i++) {
            dp[i * r + 0] = i;
        }
        for (size_t i = 1; i <= word2.size(); i++) {
            dp[i] = i;
        }
        for (size_t i = 0; i < word1.size(); i++) {
            for (size_t j = 0; j < word2.size(); j++) {
                dp[(i+1)*r+j+1] = min({
                    dp[i*r + j+1]+1,
                    dp[(i+1)*r + j]+1,
                    dp[i * r + j] + int(word1[i] != word2[j])});
            }
        }
        return dp[word1.size() * r + word2.size()];
    }
};
// @lc code=end

// XXX 没有初始化好dp

