/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    pair<int, int> depthAndDiameter(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto l = depthAndDiameter(root->left);
        auto r = depthAndDiameter(root->right);
        return {max(l.first, r.first)+1, max({l.second, r.second, l.first+r.first})};
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto dd = depthAndDiameter(root);
        return dd.second;
    }
};

//XXX 第二个max有重复比较
