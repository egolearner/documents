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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        std::vector<TreeNode*> cur;
        std::vector<TreeNode*> next;
        if (root) {
            cur.push_back(root);
        }
        while (!cur.empty()) {
            next.clear();
            result.push_back(cur.back()->val);
            for (auto p : cur) {
                if (p->left) {
                    next.push_back(p->left);
                }
                if (p->right) {
                    next.push_back(p->right);
                }
            }
            std::swap(cur, next);
        }
        return result;
    }
};
/*
 * XXX 层序遍历可以用queue，while(size-- >= 0) 不需要用两个vector
 * dfs 先右后左遍历，通过深度判断是否需要添加
 */
