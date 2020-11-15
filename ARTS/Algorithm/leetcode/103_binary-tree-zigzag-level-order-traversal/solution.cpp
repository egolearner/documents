/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> queue;
        if (root) {
            queue.push(root);
        }
        bool rev = false;
        while (!queue.empty()) {
            result.push_back({});
            auto& cur = result.back();
            for (int size = queue.size(); size != 0; size--) {
                auto n = queue.front();
                queue.pop();
                cur.push_back(n->val);
                if (n->left) {
                    queue.push(n->left);
                }
                if (n->right) {
                    queue.push(n->right);
                }
            }
            if (rev) {
                reverse(cur.begin(), cur.end());
            }
            rev = !rev;
        }
        return result;
    }
};
/*
 * 想不出如何更好的处理，偷懒用了reverse
 * 答案中用两个stack的思路
 * 交替先push left和先push right
 All you have to do is do the standard bfs(with two stacks instead) with two adjustments -

1. instead of dequeueing from a queue, pop() from our first stack pointer. Simmilarly instead of enqueueing push to our second stack pointer.
2. In queue you will push in left child then right child in every level. Here we alternately first push right and left (why? because you want to have level two in reverse order), then in second iteration left and right and so on.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        
        stack<TreeNode*> s1,s2;
        s1.push(root);
        vector<int> v1;
        while(!s1.empty() || !s2.empty())
        {
            if(!s1.empty())
            {
                while(!s1.empty())
                {
                    TreeNode* odd = s1.top();
                    s1.pop();
                    v1.push_back(odd->val);
                    if(odd->left)
                        s2.push(odd->left);
                    if(odd->right)
                        s2.push(odd->right);
                }
                v.push_back(v1);
                v1.clear();
            }
            if(!s2.empty())
            {
                while(!s2.empty())
                {
                    TreeNode* even = s2.top();
                    s2.pop();
                    v1.push_back(even->val);
                    if(even->right)
                        s1.push(even->right);
                    if(even->left)
                        s1.push(even->left);
                }
                v.push_back(v1);
                v1.clear();
            }
        }
        return v;
       
    }
};
*/
