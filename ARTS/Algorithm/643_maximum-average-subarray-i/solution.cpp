/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (41.64%)
 * Likes:    815
 * Dislikes: 123
 * Total Accepted:    84.9K
 * Total Submissions: 203.7K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 *
 * Example 1:
 *
 *
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return 0.0;
        }
        int i = 0;
        int sum = 0;
        for (i = 0; i < k; i++) {
            sum += nums[i];
        }
        int msum = sum;
        for (; i < nums.size(); i++) {
            sum += nums[i]-nums[i-k];
            msum = max(sum, msum);
        }
        return double(msum) / k;
    }
};
// @lc code=end


/* XXX 前缀和的思路，虽然时间复杂度是一样的
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        for(int i=1; i<nums.size(); i++)
            nums[i] += nums[i-1];
        double res = (double)nums[k-1]/k;
        double temp;
        for(int i=k; i<nums.size(); i++){
            temp = ((double)nums[i] - (double)nums[i-k])/k;
            res = max(res, temp);
        }
        return res;
    }
};
*/

