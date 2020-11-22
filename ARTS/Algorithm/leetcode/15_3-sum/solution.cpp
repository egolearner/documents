/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (27.25%)
 * Likes:    8319
 * Dislikes: 897
 * Total Accepted:    1.1M
 * Total Submissions: 3.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            int low = i + 1;
            int high = nums.size()-1;
            while (low < high) {
                if (nums[low] + nums[high] == target) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low+1]) {
                        low = low+1;
                    }
                    low++;
                    while (low < high && nums[high] == nums[high-1]) {
                        high = high-1;
                    }
                    high--;
                } else if (nums[low] + nums[high] < target) {
                    low = low+1;
                } else {
                    --high;
                }
            }
        }
        return res;
    }
};
// @lc code=end
// XXX 写的常数很大的N^2实现，只超过了3%
// 想到了排序，但没想清楚如何去重，以为也需要用hashtable来去重。
/*
using S = tuple<int, int, int>;
bool operator==(const S& lhs, const S& rhs) {
    return get<0>(lhs) == get<0>(rhs) &&
           get<1>(lhs) == get<1>(rhs) &&
           get<2>(lhs) == get<2>(rhs);
}
namespace std
{
    template<> struct hash<S>
    {
        typedef S argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& s) const noexcept
        {
            auto hasher = std::hash<int>{};
            return hasher(get<0>(s)) ^ hasher(get<1>(s)) ^ hasher(get<2>(s));
        }
    };
}
class Solution {
public:
    S gets(int a, int b, int c) {
        if (a <= b) {
            if (b <= c) {
                return make_tuple(a, b, c);
            } else {
                if (a >= c) {
                    return make_tuple(c, a, b);
                } else {
                    return make_tuple(a, c, b);
                }
            }
        } else {
            if (b >= c) {
                return make_tuple(c, b, a);
            } else {
                if (a >= c) {
                    return make_tuple(b, c, a);
                } else {
                    return make_tuple(b, a, c);
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        unordered_map<int, int> cnt;
        for (auto i : nums) {
            cnt[i]++;
        }
        vector<vector<int>> res;
        unordered_set<S> unique;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i+1; j < nums.size(); j++) {
                int to_find = -(nums[i]+nums[j]);
                auto it = cnt.find(to_find);
                if (it == cnt.end()) {
                    continue;
                }
                if(it->second >= 3 ||  (it->second == 2 && to_find != 0)|| (it->second == 1 && (to_find != nums[i] && to_find != nums[j]))) {
                    auto ui = unique.insert(gets(nums[i], nums[j], to_find));
                    if (ui.second) {
                        res.push_back({nums[i], nums[j], to_find});
                    }
                }
            }
        }
        return res;
    }
};
*/

