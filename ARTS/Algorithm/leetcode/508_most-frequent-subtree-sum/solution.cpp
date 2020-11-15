/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    unordered_map<int, int> sum_to_freq;
    int subTreeSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lsum = subTreeSum(root->left);
        int rsum = subTreeSum(root->right);
        int sum = lsum+rsum+root->val;
        sum_to_freq[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subTreeSum(root);
        vector<pair<int, int>>  heap;
        for(auto& i : sum_to_freq) {
            heap.push_back({i.second, i.first});
        }
        make_heap(heap.begin(), heap.end());
        vector<int> res;
        for(auto& i : sum_to_freq) {
            if (i.second == freq) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
// XXX 比较快的是，一边dfs一边记录最大频次和和
