/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (34.73%)
 * Likes:    4504
 * Dislikes: 333
 * Total Accepted:    421.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any node sequence from some starting
 * node to any node in the tree along the parent-child connections. The path
 * must contain at least one node and does not need to go through the root.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 3 * 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> maxPathSumHelper(TreeNode* root) {
        if (!root) {
            // XXX 一开始写得{0, 0}
            return {-2000, -2000};
        }
        auto l = maxPathSumHelper(root->left);
        auto r = maxPathSumHelper(root->right);
        auto max_one_side = max({l.second + root->val, r.second + root->val, root->val});
        auto max_two_side = max(max_one_side, l.second+r.second+root->val);
        auto all_max = max({l.first, r.first, max_one_side, max_two_side});
        return {all_max, max_one_side};
    }
    int maxPathSum(TreeNode* root) {
        return maxPathSumHelper(root).first;
    }
};
// @lc code=end

