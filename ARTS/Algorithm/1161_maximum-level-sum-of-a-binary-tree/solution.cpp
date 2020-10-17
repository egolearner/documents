/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (72.07%)
 * Likes:    550
 * Dislikes: 26
 * Total Accepted:    51.3K
 * Total Submissions: 71.3K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 *
 * Return the smallest level X such that the sum of all the values of nodes at
 * level X is maximal.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation:
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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
    map<int, int> sum;
    void maxLevelSum(TreeNode* root, int level) {
        if (!root) {
            return;
        }
        sum[level] += root->val;
        maxLevelSum(root->left, level+1);
        maxLevelSum(root->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        maxLevelSum(root, 1);
        int level = 0, ms = INT_MIN;
        for (auto it : sum) {
            if (it.second > ms || (!level && it.second == ms)) {
                level = it.first;
                ms = it.second;
            }
        }
        return level;
    }
};
// @lc code=end

