/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.47%)
 * Likes:    1351
 * Dislikes: 5704
 * Total Accepted:    304.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 *
 * Note:
 *
 *
 * Assume we are dealing with an environment that could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For this
 * problem, assume that your function returns 2^31 − 1 when the division result
 * overflows.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 *
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 *
 *
 * Example 3:
 *
 *
 * Input: dividend = 0, divisor = 1
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: dividend = 1, divisor = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 *
 *
 */

// @lc code=start
class Solution {
public:
    pair<int, int> div(int d1, int d2) {
        if (d1 < d2) {
            return {0, d1};
        }
        if ((d1>>1) >= d2) {
            auto res = div(d1>>1, d2);
            auto res_of_remain = div(res.second*2+(d1%2==1), d2);
            return {res.first*2+res_of_remain.first, res_of_remain.second};
        }
        int first = 0;
        while (d1 >= d2) {
            d1 -= d2;
            first ++;
        }
        return {first, d1};
    }
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) {
                return 1;
            }
            return 0;
        }
        bool neg = (dividend > 0 ) != (divisor > 0);
        int f = 0, s = 0;
        int add = 0;
        if (dividend == INT_MIN) {
            add = 1;
            f = INT_MAX - abs(divisor)+1;
            s = abs(divisor);
        } else {
            f = abs(dividend);
            s = abs(divisor);
        }
        auto res = div(f, s);
        return neg ? -add-res.first : add==1 && res.first==INT_MAX ? INT_MAX : res.first+add;
    }
};
// @lc code=end

