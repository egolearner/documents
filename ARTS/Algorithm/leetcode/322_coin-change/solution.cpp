/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (36.16%)
 * Likes:    6071
 * Dislikes: 183
 * Total Accepted:    566.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: coins = [1], amount = 1
 * Output: 1
 *
 *
 * Example 5:
 *
 *
 * Input: coins = [1], amount = 2
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    void helper(vector<int>& coins) {
        for (size_t i = 1; i < mincount.size(); i++) {
            for (auto j : coins) {
                if (i < j) {
                    break;
                }
                if (mincount[i-j] >= 0) {
                    if (mincount[i] == -1) {
                        mincount[i] = mincount[i-j] + 1;
                    } else {
                        mincount[i] = min(mincount[i], mincount[i - j] + 1);
                    }
                }
            }
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        mincount.clear();
        mincount.resize(amount+1, -1);
        mincount[0] = 0;
        helper(coins);
        return mincount[amount];
    }
    vector<int> mincount;
};
// @lc code=end

