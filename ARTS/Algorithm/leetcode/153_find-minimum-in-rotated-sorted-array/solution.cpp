class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        int mid = begin + (end-begin)/2;
        while (true) {
            if (end == begin+1 || begin == end) {
                return std::min(nums[begin], nums[end]);
            }
            mid = begin + (end-begin)/2;
            if (nums[mid] > nums[begin] && nums[mid] < nums[end]) {
                return nums[begin];
            } else if (nums[mid] < nums[begin]) {
                end = mid;
            } else if (nums[mid] > nums[end]) {
                begin = mid;
            }
        }
        return nums[0];
    }
};
