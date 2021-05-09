/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (75.00%)
 * Likes:    1702
 * Dislikes: 91
 * Total Accepted:    323.8K
 * Total Submissions: 431.8K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 *
 * You may return any answer array that satisfies this condition.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int low = 0;
        int high = A.size()-1;
        while (true) {
            while (low <= high && A[low] % 2 == 0) {
                low++;
            }
            while (low <= high && A[high] % 2 == 1) {
                high--;
            }
            if (low <= high) {
                swap(A[low], A[high]);
                low++;
                high--;
            } else {
                break;
            }
        }
        return A;
    }
};
// @lc code=end

