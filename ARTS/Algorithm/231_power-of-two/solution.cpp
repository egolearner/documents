/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (43.76%)
 * Likes:    1061
 * Dislikes: 204
 * Total Accepted:    375.1K
 * Total Submissions: 857.2K
 * Testcase Example:  '1'
 *
 * Given an integer n, write a function to determine if it is a power of
 * two.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: true
 * Explanation: 2^0 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 16
 * Output: true
 * Explanation: 2^4 = 16
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: n = 4
 * Output: true
 *
 *
 * Example 5:
 *
 *
 * Input: n = 5
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n&(n-1)) == 0;
    }
};
// @lc code=end

// XXX 没有判断好0，INT_MIN，优先级记错

