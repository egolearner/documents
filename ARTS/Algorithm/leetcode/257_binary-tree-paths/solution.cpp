/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/
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
/*
path可以重用，不需要每次创建新的
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        string actual = "";
        findLeafs(root,ans,actual);
        return ans;
    }
    
    void findLeafs(TreeNode* root, vector<string> &ans, string &actual) {
        string add;
        if(actual == "") add = to_string(root->val);
        else add += "->" + to_string(root->val);
        actual += add;
        if(root->right) {
            findLeafs(root->right, ans, actual);
        }
        if (root->left) {
            findLeafs(root->left, ans, actual);            
        }
        if(!root->right && !root->left) {
            ans.push_back(actual);
        }
        for(int i = 0; i < add.size(); i++) actual.pop_back();
    }
};
*/
