/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
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
    vector<TreeNode*> res;
    unordered_set<int> tod;
    TreeNode* postorder(TreeNode* root) {
        if (!root || tod.empty()) {
            return root;
        }
        root->left = postorder(root->left);
        root->right = postorder(root->right);
        if (tod.erase(root->val) > 0) {
            if (root->left) {
                res.push_back(root->left);
            }
            if (root->right) {
                res.push_back(root->right);
            }
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        tod.insert(to_delete.begin(), to_delete.end());
        auto newroot = postorder(root);
        if (newroot) {
            res.push_back(newroot);
        }
        return res;
    }
};
