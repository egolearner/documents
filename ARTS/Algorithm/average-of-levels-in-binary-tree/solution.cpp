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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> queue;
        vector<TreeNode*> queue2;
        vector<double> result;
        if (root != nullptr) {
            queue.push_back(root);
        }
        while (!queue.empty()) {
            double sum = 0.0;
            queue2.clear();
            for (auto it : queue) {
                sum += it->val;
                if (it->left) {
                    queue2.push_back(it->left);
                }
                if (it->right) {
                    queue2.push_back(it->right);
                }
            }
            result.push_back(sum/queue.size());
            swap(queue, queue2);
        }
        return result;
    }
};
// XXX 可以用queue+count来实现一个数据结构保存层序
