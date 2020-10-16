/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.92%)
 * Likes:    4054
 * Dislikes: 109
 * Total Accepted:    406.3K
 * Total Submissions: 812.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(&preorder[0], 0, preorder.size()-1, &inorder[0], 0, inorder.size()-1);
    }
    TreeNode *buildTreeHelper(int *pre, int pre_begin, int pre_end, int *in, int in_begin, int in_end) {
        if (pre_begin > pre_end) {
            return NULL;
        }
        if (pre_begin == pre_end) {
            return new TreeNode(pre[pre_begin]);
        }
        TreeNode *root = new TreeNode(pre[pre_begin]);
        int root_loc = std::find(in+in_begin, in+in_end+1, root->val)-in;
        int left_num = root_loc - in_begin;
        root->left = buildTreeHelper(pre, pre_begin+1, pre_begin+left_num, in, in_begin, root_loc-1);
        root->right = buildTreeHelper(pre, pre_begin+left_num+1, pre_end, in, root_loc+1, in_end);
    }
};
// @lc code=end

