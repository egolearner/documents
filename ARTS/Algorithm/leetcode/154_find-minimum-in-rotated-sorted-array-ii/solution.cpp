/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t begin = 0;
        size_t end = nums.size()-1;
        if (nums[begin] < nums[end]) {
            return nums[begin];
        }
        if (nums[begin] == nums[end]) {
            for (; begin <= end && nums[begin] == nums[0]; ++begin) {
            }
            if (begin == end+1) {
                return nums[0];
            }
            if (nums[begin] < nums[0]) {
                return nums[begin];
            }
        }
        while (begin+1<end) {
            size_t mid = begin+(end-begin)/2;
            if (nums[mid] >= nums[begin]) {
                begin = mid;
            } else if (nums[mid] < nums[begin]) {
                end = mid;
            }
        }
        return min(nums[begin], nums[end]);
    }
};
