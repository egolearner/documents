/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/
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
    bool isvalid(TreeNode* root, int64_t mini, int64_t maxi) {
        if (!root) {
            return true;
        }
        int64_t val = (int64_t)root->val;
        if (val <= mini || val >= maxi) {
            return false;
        }
        return isvalid(root->left, mini, min(maxi, val)) && isvalid(root->right, max(mini, val), maxi);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root, int64_t(INT_MIN)-1, int64_t(INT_MAX)+1);
    }
};
