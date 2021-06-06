/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (65.47%)
 * Likes:    6019
 * Dislikes: 115
 * Total Accepted:    783.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, size_t i, vector<vector<int>>& res, vector<int>& cur) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }
        dfs(nums, i+1, res, cur);
        cur.push_back(nums[i]);
        dfs(nums, i+1, res, cur);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, res, cur);
        return res;
    }
};
// @lc code=end


/*
XXX 其他算法
Iterative

Using [1, 2, 3] as an example, the iterative process is like:

Initially, one empty subset [[]]
Adding 1 to []: [[], [1]];
Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};


Bit Manipulation

To give all the possible subsets, we just need to exhaust all the possible combinations of the numbers. And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.

Using [1, 2, 3] as an example, 1 appears once in every two consecutive subsets, 2 appears twice in every four consecutive subsets, and 3 appears four times in every eight subsets (initially all subsets are empty):

[], [ ], [ ], [    ], [ ], [    ], [    ], [       ]
[], [1], [ ], [1   ], [ ], [1   ], [    ], [1      ]
[], [1], [2], [1, 2], [ ], [1   ], [2   ], [1, 2   ]
[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
}；


*/

