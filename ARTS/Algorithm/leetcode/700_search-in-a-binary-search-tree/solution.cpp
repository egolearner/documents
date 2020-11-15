/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (73.26%)
 * Likes:    1084
 * Dislikes: 123
 * Total Accepted:    224.6K
 * Total Submissions: 306.4K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * Given the root node of a binary search tree (BST) and a value. You need to
 * find the node in the BST that the node's value equals the given value.
 * Return the subtree rooted with that node. If such node doesn't exist, you
 * should return NULL.
 *
 * For example, 
 *
 *
 * Given the tree:
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 *
 * And the value to search: 2
 *
 *
 * You should return this subtree:
 *
 *
 * ⁠     2
 * ⁠    / \
 * ⁠   1   3
 *
 *
 * In the example above, if we want to search the value 5, since there is no
 * node with value 5, we should return NULL.
 *
 * Note that an empty tree is represented by NULL, therefore you would see the
 * expected output (serialized tree format) as [], not null.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        return searchBST(root->left, val);
    }
};
// @lc code=end

