/*
You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
*/
class Solution {
public:
    template <class P>
    int bsearch(int begin, int end, P p) {
        while (begin < end) {
            int mid = begin + (end-begin)/2;
            int r = p(mid, begin);
            if (r == 0) {
                return mid;
            } else if (r > 0) {
                begin = mid+1;
            } else {
                end = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        auto match = [&](int i, int begin){
            if (target == nums[i]) {
                return 0;
            }
            if (nums[i] < target) {
                return 1;
            }
            return -1;
        };
        if (nums[0] < nums[nums.size()-1]) {
            return bsearch(0, nums.size()-1, match);
        }
        int rotate = bsearch(0, nums.size()-1, [&](int i, int begin) {
                if (i == 0) {
                    return 1;
                }
                if ((nums)[i]<(nums)[i-1]) {
                    return 0;
                }
                if (nums[i] > nums[begin]) {
                    return 1;
                }
                return -1;
                });
        int fi = bsearch(0, rotate-1, match);
        if(fi != -1) {
            return fi;
        }
        int si = bsearch(rotate, nums.size()-1, match);
        return si;
    }
};

/* XXX 这个思路牛，一次二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        
        while(i <= j){
            int mid = i + (j-i)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid] >= nums[i]){
                if(nums[mid] > target && nums[i] <= target){
                    j = mid-1;
                }else{
                    i = mid+1;
                }
            }else{
                if(nums[mid] < target && target <= nums[j]){
                    i = mid+1;
                }else{
                    j = mid-1;
                }
            }
        }
        
        return -1;
    }
};
*/
