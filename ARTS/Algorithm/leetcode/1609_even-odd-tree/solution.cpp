/*
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

 

Example 1:



Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
Example 2:



Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in the level 2 must be in strictly increasing order, so the tree is not Even-Odd.
Example 3:



Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
Example 4:

Input: root = [1]
Output: true
Example 5:

Input: root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
Output: true
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 106
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> queue;
        if (root) {
            queue.push(root);
        }
        bool is_even = true;
        auto test = [&](int n) {return bool(n&1) == is_even;};
        auto cmp = [&](int a, int b) {return is_even ? a < b : a > b;};
        while (!queue.empty()) {
            auto prev = is_even ? INT_MIN : INT_MAX;
            for (int size = queue.size(); size > 0; size--) {
                auto node = queue.front();
                queue.pop();
                if (!test(node->val) || !cmp(prev, node->val)) {
                    return false;
                }
                prev = node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            is_even = !is_even;
        }
        return true;
    }
};

/*
 * XXX
 * 可以用DFS+map记录每一层的值来优化
class Solution {
 
    unordered_map<int , int > m;
    
    bool dfs(TreeNode* root , int level ){
        
        if (root == NULL )  return true;
        
        if (level & 1){
            if ( root->val  &  1  )  return false; // if level is odd then value should not be odd
        }
        else if ( !(root->val & 1) ) return false; // if level is even then value should not be even
        
        
        if (m.find(level) != m.end() ){
            if (level & 1 ){
                if (m[level] <= root->val ) return false; // should be strictely strictly decreasing   
            }
            else if (m[level] >= root->val ) return false; // should be strictely strictly increasing  
            
        }
        
        m[level] =  root->val;
    
        return dfs(root->left , level + 1) && dfs(root->right, level +  1);
    }
    
    
public:
    bool isEvenOddTree(TreeNode* root) {
        
        return dfs(root, 0 );
        
        
    }
};
*/
