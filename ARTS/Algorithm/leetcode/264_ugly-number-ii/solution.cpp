/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (43.23%)
 * Likes:    2984
 * Dislikes: 175
 * Total Accepted:    218.3K
 * Total Submissions: 500.8K
 * Testcase Example:  '10'
 *
 * An ugly number is a positive integer whose prime factors are limited to 2,
 * 3, and 5.
 *
 * Given an integer n, return the n^th ugly number.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first
 * 10 ugly numbers.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * limited to 2, 3, and 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1690
 *
 *
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            int m2 = (res[p2])*2;
            int m3 = (res[p3])*3;
            int m5 = (res[p5])*5;
            res[i] = min({m2, m3, m5});
            if (res[i] == m2) {
                p2++;
            }
            if (res[i] == m3) {
                p3++;
            }
            if (res[i] == m5) {
                p5++;
            }
        }
        return res[n-1];
    }
};
// @lc code=end

