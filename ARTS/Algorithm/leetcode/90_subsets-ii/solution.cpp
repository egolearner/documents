/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (49.05%)
 * Likes:    2654
 * Dislikes: 112
 * Total Accepted:    349.6K
 * Total Submissions: 704.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<pair<int,int>>& nums, vector<vector<int>>& res, vector<int>& cur, size_t ind) {
        if (ind >= nums.size()) {
            res.push_back(cur);
            return;
        }
        int num = nums[ind].first;
        int count = nums[ind].second;
        dfs(nums, res, cur, ind+1);
        for (int i = 0; i < count; i++) {
            cur.push_back(num);
            dfs(nums, res, cur, ind+1);
        }
        cur.resize(cur.size()-count);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> ns;
        int prev = nums[0];
        int count = 1;
        for (size_t i = 1; i <nums.size(); i++) {
            if (nums[i] != prev) {
                ns.push_back({prev, count});
                prev = nums[i];
                count = 1;
            } else {
                count++;
            }
        }
        ns.push_back({prev, count});
        vector<vector<int>> res;
        vector<int> cur;
        dfs(ns, res, cur, 0);
        return res;
    }
};
// @lc code=end

/*
XXX 非递归算法
    class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};
*/

