/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (48.11%)
 * Likes:    2119
 * Dislikes: 39
 * Total Accepted:    258.6K
 * Total Submissions: 537K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    using I = vector<int>::iterator;
    TreeNode* build(I ib, I ie, I pb, I pe) {
        if (ib == ie) {
            return nullptr;
        }
        auto root = find(ib, ie, *(pe-1));
        int left_dis = distance(ib, root);
        I post_left_end = pb;
        advance(post_left_end, left_dis);
        return new TreeNode(*root, build(ib, root, pb, post_left_end), build(root+1, ie, post_left_end, pe-1));
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
// @lc code=end


/* XXX 比较快的答案都是用map记录inorder值和index的关系，借此确定如何递归
class Solution {
public:
    int postIndex;
    unordered_map<int,int> m;
    TreeNode* build(vector<int>& post,int inStrt,int inEnd)
    {
        if(inStrt>inEnd) return NULL;
        TreeNode* nn=new TreeNode(post[postIndex--]);
        if(inStrt==inEnd) return nn;
        int idx=m[nn->val];
        nn->right=build(post,idx+1,inEnd);
        nn->left=build(post,inStrt,idx-1);
        return nn;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++)
        {
            m[in[i]]=i;
        }
        postIndex=post.size()-1;
        return build(post,0,in.size()-1);
    }
};
*/