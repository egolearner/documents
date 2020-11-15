/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> queue;
        if (root) {
            queue.push(root);
        }
        while (!queue.empty()) {
            result.push_back({});
            auto& cur = result.back();
            for (int size = queue.size(); size != 0; size--) {
                auto n = queue.front();
                queue.pop();
                cur.push_back(n->val);
                if (n->left) {
                    queue.push(n->left);
                }
                if (n->right) {
                    queue.push(n->right);
                }
            }
        }
        return result;
    }
};
