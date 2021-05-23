/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (62.77%)
 * Likes:    1372
 * Dislikes: 175
 * Total Accepted:    132.7K
 * Total Submissions: 210.6K
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, return the leftmost value in the last row
 * of the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */

// @lc code=start
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int val = -1;
        while (!q.empty()) {
            val = q.front()->val;
            for (int size = q.size(); size; size--) {
                TreeNode* n = q.front();
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
                q.pop();
            }
        }
        return val;
    }
};
// @lc code=end


/*
XXX 从右向左BFS，拿到的最后一个元素就是答案
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
         root=q.front();
            q.pop();
            if(root->right)
                q.push(root->right);
            if(root->left)
                q.push(root->left);

        }
        return root->val;
    }
};
*/