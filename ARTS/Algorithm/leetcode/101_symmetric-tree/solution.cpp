/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (47.33%)
 * Likes:    4826
 * Dislikes: 114
 * Total Accepted:    732.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Follow up: Solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty()) {
            auto n1 = q.front();
            q.pop();
            auto n2 = q.front();
            q.pop();
            if (bool(n1) != bool(n2)) {
                return false;
            }
            if (n1) {
                if (n1->val != n2->val) {
                    return false;
                }
                q.push(n1->left);
                q.push(n2->right);
                q.push(n1->right);
                q.push(n2->left);
            }
        }
        return true;
    }
};
// @lc code=end

