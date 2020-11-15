/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 *
 * https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (59.48%)
 * Likes:    511
 * Dislikes: 89
 * Total Accepted:    65.9K
 * Total Submissions: 110.8K
 * Testcase Example:  '5'
 *
 * Given a positive integer, check whether it has alternating bits: namely, if
 * two adjacent bits will always have different values.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: true
 * Explanation: The binary representation of 5 is: 101
 *
 *
 * Example 2:
 *
 *
 * Input: n = 7
 * Output: false
 * Explanation: The binary representation of 7 is: 111.
 *
 * Example 3:
 *
 *
 * Input: n = 11
 * Output: false
 * Explanation: The binary representation of 11 is: 1011.
 *
 * Example 4:
 *
 *
 * Input: n = 10
 * Output: true
 * Explanation: The binary representation of 10 is: 1010.
 *
 * Example 5:
 *
 *
 * Input: n = 3
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n & 1;
        n >>= 1;
        while (n) {
            int cur = n & 1;
            if ((cur^pre) != 1) {
                return false;
            }
            pre = cur;
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end


/* XXX 机智的答案
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long q = n;
        long nq = q + (q >> 1) + 1;
        return (nq & (nq - 1)) == 0;
    }
};
*/

