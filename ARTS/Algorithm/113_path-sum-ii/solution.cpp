/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void helper(TreeNode* root, int sum, vector<int>* cur, vector<vector<int>>* result) {
        if (!root) {
            return;
        }
        cur->push_back(root->val);
        int val = sum-root->val;
        if (val == 0 && !root->left && !root->right) {
            result->push_back(*cur);
            cur->pop_back();
            return;
        }
        helper(root->left, val, cur, result);
        helper(root->right, val, cur, result);
        cur->pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> cur;
        helper(root, sum, &cur, &result);
        return result;
    }
};
