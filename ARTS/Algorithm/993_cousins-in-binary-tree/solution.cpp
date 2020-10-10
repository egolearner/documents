/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> queue;
        bool fx = false, fy = false;
        int xd = -1, yd = -1, xp = -1, yp = -1;
        int depth = 0;
        auto check = [&](int val, int p) {
            if (val == x) {
                xd = depth;
                xp = p;
                fx = true;
            }
            if (val == y) {
                yd = depth;
                yp = p;
                fy = true;
            }
        };
        if (root) {
            queue.push(root);
            check(root->val, -1);
        }
        while (!queue.empty()  && (!fx && !fy)) {
            ++depth;
            for (int size = queue.size(); size > 0; size--) {
                auto n = queue.front();
                queue.pop();
                if (n->left) {
                    check(n->left->val, n->val);
                    queue.push(n->left);
                }
                if (n->right) {
                    check(n->right->val, n->val);
                    queue.push(n->right);
                }
            }
        }
        return xd == yd && xp != yp;
    }
};

//XXX 涉及深度的问题太喜欢用层序遍历了，效率不如dfs
