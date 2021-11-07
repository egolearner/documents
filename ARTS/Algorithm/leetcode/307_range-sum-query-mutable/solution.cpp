/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (37.29%)
 * Likes:    2395
 * Dislikes: 131
 * Total Accepted:    166.1K
 * Total Submissions: 435K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, handle multiple queries of the following
 * types:
 *
 *
 * Update the value of an element in nums.
 * Calculate the sum of the elements of nums between indices left and right
 * inclusive where left <= right.
 *
 *
 * Implement the NumArray class:
 *
 *
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * void update(int index, int val) Updates the value of nums[index] to be
 * val.
 * int sumRange(int left, int right) Returns the sum of the elements of nums
 * between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +
 * ... + nums[right]).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output
 * [null, 9, null, 8]
 *
 * Explanation
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1, 2, 5]
 * numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * At most 3 * 10^4 calls will be made to update and sumRange.
 *
 *
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        seg.resize(nums.size()*4);
        int index = 0;
        init(nums, 0, nums.size()-1, index);
        numa = &nums;
    }

    void update(int index, int val) {
        int begin = 0, end = numa->size()-1;
        int delta = val - (*numa)[index];
        int i = 0;
        while (begin < end) {
            seg[i] += delta;
            int mid = begin + (end-begin)/2;
            if (mid >= index) {
                end = mid;
                i = 2*i+1;
            } else {
                begin = mid+1;
                i = 2*i+2;
            }
        }
        seg[i] += delta;
        (*numa)[index] = val;
    }

    int sumRange(int left, int right) {
        return sum_impl(left, right, 0, numa->size()-1, 0);
    }

private:
    int init(vector<int>& nums, int begin, int end, int index) {
        if (begin == end) {
            seg[index] = nums[begin];
            return nums[begin];
        }
        int mid = begin + (end-begin)/2;
        int left_sum = init(nums, begin, mid, index*2+1) ;
        int right_sum = init(nums, mid+1, end, index*2+2);
        seg[index] = left_sum + right_sum;
        return seg[index];
    }
    int sum_impl(int left, int right, int begin, int end, int i) {
        if (left > end || right < begin) {
            return 0;
        }
        if (left <= begin && right >= end) {
            return seg[i];
        }
        int mid = begin + (end-begin)/2;
        return sum_impl(left, right, begin, mid, i*2+1) +
            sum_impl(left, right, mid+1, end, i*2+2);
    }
    vector<int> seg;
    vector<int>* numa;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end


class NumArrayFenwick {
public:
    NumArray(vector<int>& nums) {
        fenwick.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            update_impl(i, nums[i]);
        }
        this->numa = &nums;
    }

    void update(int index, int val) {
        update_impl(index, val - (*numa)[index]);
        (*numa)[index] = val;
    }

    int sumRange(int left, int right) {
        return prefix_sum(right) - prefix_sum(left-1);
    }

private:
    int step(int i) {
        return i & (-i);
    }
    void  update_impl(int i, int delta) {
        for (i += 1; i < fenwick.size(); i += step(i)) {
            fenwick[i] += delta;
        }
    }

    int prefix_sum(int i) {
        if (i < 0) {
            return 0;
        }
        int sum = 0;
        for (i += 1; i; i -= step(i)) {
            sum += fenwick[i];
        }
        return sum;
    }

    vector<int> fenwick;
    vector<int>* numa;
};