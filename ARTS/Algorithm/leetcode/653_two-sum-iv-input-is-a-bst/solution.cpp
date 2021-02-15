/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (55.79%)
 * Likes:    1817
 * Dislikes: 147
 * Total Accepted:    175.9K
 * Total Submissions: 313.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a Binary Search Tree and a target number k, return true if
 * there exist two elements in the BST such that their sum is equal to the
 * given target.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1,3], k = 4
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: root = [2,1,3], k = 1
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: root = [2,1,3], k = 3
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
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
    bool findTarget(TreeNode* root, int target) {
        stack<TreeNode*> left;
        stack<TreeNode*> right;
        auto push_left = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            left.push(root);
            while (root->left) {
                left.push(root->left);
                root = root->left;
            }
        };
        auto push_right = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            right.push(root);
            while (root->right) {
                right.push(root->right);
                root = root->right;
            }
        };
        push_right(root);
        push_left(root);
        while (!left.empty() && !right.empty()) {
            int sum = left.top()->val + right.top()->val;
            if (sum > target) {
                auto t = right.top();
                right.pop();
                push_right(t->left);
            } else if (sum < target) {
                auto t = left.top();
                left.pop();
                push_left(t->right);
            } else if (sum == target && left.top() != right.top()) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

