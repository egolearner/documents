/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.05%)
 * Likes:    2576
 * Dislikes: 366
 * Total Accepted:    367.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Notice that the solution set must not contain duplicate quadruplets.
 *
 *
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * Input: nums = [], target = 0
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (size_t j = i+1; j < nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int low = j+1;
                int high = nums.size()-1;
                while (low < high) {
                    int sum = nums[i]+nums[j]+nums[low]+nums[high];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low]==nums[++low]) {
                        }
                        while (low < high && nums[high]==nums[--high]) {
                        }
                    } else if (sum > target) {
                        --high;
                    } else {
                        ++low;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


/* 官方题解
two pointer
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}
vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}
vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    int lo = start, hi = nums.size() - 1;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            ++lo;
        else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            --hi;
        else
            res.push_back({ nums[lo++], nums[hi--]});
    }
    return res;
}

# hash set
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}
vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}
vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    unordered_set<int> s;
    for (auto i = start; i < nums.size(); ++i) {
        if (res.empty() || res.back()[1] != nums[i])
            if (s.count(target - nums[i]))
                res.push_back({ target - nums[i], nums[i]});
        s.insert(nums[i]);
    }
    return res;
}
*/