/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        if (nums.size() == 1) {
            return nums[0] == target;
        }
        int begin = 0, end = nums.size()-1;
        if (nums[begin] == nums[end]) {
            if (nums[begin] == target) {
                return true;
            }
            // XXX 没有判断begin <= end
            while(begin<=end && nums[begin] == nums[0]) {
                ++begin;
            }
        }
        while (begin <= end) {
            int mid = begin + (end-begin)/2;
            if (nums[mid] == target) {
                return true;
            }
            if(nums[mid]>=nums[begin]) {
                if (nums[mid]>target && nums[begin] <= target) {
                    end = mid-1;
                } else {
                    begin = mid+1;
                }
            } else {
                if (nums[mid]<target && nums[end] >= target) {
                    begin = mid+1;
                } else {
                    end = mid-1;
                }
            }
        }
        return false;
    }
};

// XXX 用了search-in-rotated-sorted-array的机智思路

