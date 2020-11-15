/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    TreeNode* prev;
    void preorder(TreeNode* root) {
        if (!root) {
            return;
        }
        auto* left = root->left;
        auto* right = root->right;
        prev->right = root;
        root->left = nullptr;
        prev = root;
        preorder(left);
        preorder(right);

    }
    void flatten(TreeNode* root) {
        TreeNode dummy;
        prev = &dummy;
        preorder(root);
    }
};
