/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 *
 * https://leetcode.com/problems/thousand-separator/description/
 *
 * algorithms
 * Easy (59.17%)
 * Likes:    141
 * Dislikes: 7
 * Total Accepted:    17.2K
 * Total Submissions: 29.5K
 * Testcase Example:  '987'
 *
 * Given an integer n, add a dot (".") as the thousands separator and return it
 * in string format.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 987
 * Output: "987"
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1234
 * Output: "1.234"
 *
 *
 * Example 3:
 *
 *
 * Input: n = 123456789
 * Output: "123.456.789"
 *
 *
 * Example 4:
 *
 *
 * Input: n = 0
 * Output: "0"
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n < 2^31
 *
 *
 */

// @lc code=start
class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        do {
            int rem = n % 1000;
            n /= 1000;
            int count = 0;
            while(rem) {
                int single = rem % 10;
                rem /= 10;
                res.push_back('0'+single);
                count++;
            }
            if (n) {
                res.append(3 - count, '0');
                res.append(1, '.');
            }
        } while (n);
        if (res.empty()) {
            res.append(1, '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

