/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stack;
        if (root) {
            stack.push({root, false});
        }
        vector<int> result;
        while (!stack.empty()) {
            auto& n_status = stack.top();
            auto node = n_status.first;
            if (n_status.second || (!node->left && !node->right)) {
                result.push_back(node->val);
                stack.pop();
                continue;
            }
            n_status.second = true;
            if (node->right) {
                stack.push({node->right, false});
            }
            if (node->left) {
                stack.push({node->left, false});
            }
        }
        return result;
        
    }
};

/** XXX 不用标记的方案
vector<int> postorderTraversal1(TreeNode *root) {
    vector<int> v;
    vector<TreeNode*> stack;
    if (root) {
        stack.push_back(root);
    }
    while (stack.size()>0){
        TreeNode *n = stack.back();
        stack.pop_back();
        v.push_back(n->val);
        if (n->left){
            stack.push_back(n->left);
        } 
        if (n->right) {
            stack.push_back(n->right);
        }
    }
    std::reverse(v.begin(), v.end());  // the trick
    return v;
}

// traditional and standard way.
// using the stack to simulate the recursive function stack.
vector<int> postorderTraversal2(TreeNode *root) {
    vector<int> v;
    vector<TreeNode*> stack;
    TreeNode *node = root;
    TreeNode *lastVisitNode = NULL;
    while(stack.size()>0 || node!=NULL){

        if (node != NULL){
            // keep going the left
            stack.push_back(node);
            node = node->left;
        }else{
            TreeNode *n = stack.back();
            // left way is finsised, keep going to the right way
            if (n->right != NULL && lastVisitNode != n->right){
                node = n->right;
            }else{
                // both left and right has been accessed.
                stack.pop_back();
                v.push_back(n->val);
                lastVisitNode = n;
            }
        }
    }
    return v;
}
*/
