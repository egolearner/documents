/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (79.68%)
 * Likes:    565
 * Dislikes: 1698
 * Total Accepted:    234.4K
 * Total Submissions: 293.8K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "Hello"
 * Output: "hello"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "here"
 * Output: "here"
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "LOVELY"
 * Output: "lovely"
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for (auto c : str) {
            res.push_back(tolower(c));
        }
        return res;
    }
};
// @lc code=end

