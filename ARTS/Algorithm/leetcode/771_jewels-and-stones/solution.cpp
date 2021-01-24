/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (86.61%)
 * Likes:    2454
 * Dislikes: 394
 * Total Accepted:    586.9K
 * Total Submissions: 675.7K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings jewels representing the types of stones that are
 * jewels, and stones representing the stones you have. Each character in
 * stones is a type of stone you have. You want to know how many of the stones
 * you have are also jewels.
 *
 * Letters are case sensitive, so "a" is considered a different type of stone
 * from "A".
 *
 *
 * Example 1:
 * Input: jewels = "aA", stones = "aAAbbbb"
 * Output: 3
 * Example 2:
 * Input: jewels = "z", stones = "ZZ"
 * Output: 0
 *
 *
 * Constraints:
 *
 *
 * 1 <= jewels.length, stones.length <= 50
 * jewels and stones consist of only English letters.
 * All the characters of jewels are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        char mark[128] = {0};
        for (auto c : jewels) {
            mark[c] = 1;
        }
        int cnt = 0;
        for (auto c : stones) {
            cnt += (mark[c] == 1);
        }
        return cnt;
    }
};
// @lc code=end

