/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (50.55%)
 * Likes:    6323
 * Dislikes: 334
 * Total Accepted:    739.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 *
 * You must solve this problem without using the library's sort function.
 *
 *
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is 0, 1, or 2.
 *
 *
 *
 * Follow up: Could you come up with a one-pass algorithm using only constant
 * extra space?
 *
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one_count = 0;
        int low = 0, high = nums.size()-1;
        int low_w = low, high_w = high;
        while (low <= high) {
            while (low <= high && (nums[low] == 1 || nums[low] == 0)) {
                if (nums[low] == 1) {
                    one_count++;
                } else {
                    nums[low_w++] = 0;
                }
                low++;
            }
            while (low <= high  && (nums[high] == 1 || nums[high]== 2)) {
                if (nums[high] == 1) {
                    one_count++;
                } else {
                    nums[high_w--] = 2;
                }
                high--;
            }
            if (low < high) {
                nums[low_w++] = 0;
                nums[high_w--] = 2;
                low++;
                high--;
            } else if (low == high) {
                if (nums[low] == 0) {
                    nums[low_w++] = 0;
                    low++;
                } else {
                    nums[high_w--] = 2;
                    high--;
                }
            } else {
                break;
            }
        }
        while (low_w <= high_w) {
            nums[low_w++] = 1;
        }
    }
};
// @lc code=end


/* XXX
    class Solution {
    public:
        void sortColors(int A[], int n) {
            int second=n-1, zero=0;
            for (int i=0; i<=second; i++) {
                while (A[i]==2 && i<second) swap(A[i], A[second--]);
                while (A[i]==0 && i>zero) swap(A[i], A[zero++]);
            }
        }
    };
*/