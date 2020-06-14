/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root!=nullptr) {
            string path;
            visitNode(root, move(path), &result);
        }
        return result;
    }
    void visitNode(TreeNode* cur, string path, vector<string> *result) {
        if (!path.empty()) {
            path.append("->");
        }
        path.append(to_string(cur->val));
        if (cur->left) {
            if (cur->right) {
                visitNode(cur->left, path, result);
            } else {
                visitNode(cur->left, move(path), result);
            }
        }
        if (cur->right) {
            visitNode(cur->right, move(path), result);
        }
        if (!cur->left  && !cur->right) {
            result->emplace_back(move(path));
        }
    }
};
