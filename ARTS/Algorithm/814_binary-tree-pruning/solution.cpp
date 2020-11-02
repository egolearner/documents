/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 *
 * https://leetcode.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (73.74%)
 * Likes:    1197
 * Dislikes: 48
 * Total Accepted:    73K
 * Total Submissions: 99.4K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * We are given the head node root of a binary tree, where additionally every
 * node's value is either a 0 or a 1.
 *
 * Return the same tree where every subtree (of the given tree) not containing
 * a 1 has been removed.
 *
 * (Recall that the subtree of a node X is X, plus every node that is a
 * descendant of X.)
 *
 *
 * Example 1:
 * Input: [1,null,0,0,1]
 * Output: [1,null,0,null,1]
 * ⁠
 * Explanation:
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer.
 *
 *
 *
 *
 *
 * Example 2:
 * Input: [1,0,1,0,0,0,1]
 * Output: [1,null,1,null,1]
 *
 *
 *
 *
 *
 *
 * Example 3:
 * Input: [1,1,0,1,1,0,1,0]
 * Output: [1,1,0,1,1,null,1]
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * The binary tree will have at most 200 nodes.
 * The value of each node will only be 0 or 1.
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
    pair<TreeNode*, bool> prune(TreeNode* root) {
        if (!root) {
            return {root, false};
        }
        auto l = prune(root->left);
        auto r = prune(root->right);
        root->left = l.first;
        root->right = r.first;
        bool hasOne = l.second || r.second || root->val == 1;
        return {hasOne ? root : nullptr, hasOne};
    }
    TreeNode* pruneTree(TreeNode* root) {
        return prune(root).first;
    }
};
// @lc code=end

/* XXX 更简洁
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(root->val == 0 && root->left==NULL && root->right==NULL)  root=NULL;
        return root;
    }
};
*/

