/*
We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.

 

Example 1:



Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:



Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
 

Example 3:



Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]
 

Note:

The number of nodes in the original tree is between 1 and 1000.
Each node will have a value between 1 and 10^9.
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
    TreeNode* recoverFromPreorder(string S) {
        if (S.empty()) {
            return nullptr;
        }
        const char* begin = S.c_str();
        const char *end = begin + S.size();
        char *nb;
        int depth = 0;
        stack<pair<TreeNode*, int >>  stack;
        TreeNode dummy;
        stack.push({&dummy, INT_MAX});
        while (begin != end) {
            for (depth = 0; *begin == '-'; begin++) {
                ++depth;
            }
            int val = strtol(begin, &nb, 10);
            begin = nb;
            while (depth >= stack.top().second) {
                stack.pop();
            }
            printf("%d %d %d %d\n", val, depth, stack.top().first->val, stack.top().second);
            auto node = new TreeNode(val);
            if (!stack.top().first->left) {
                stack.top().first->left = node;
            } else {
                stack.top().first->right = node;
            }
            stack.push({node, depth});
        }
        return dummy.left;
    }
};

/* XXX 用stack.size()来表示depth
class Solution {
public:
    
    typedef pair<int, int> pr;
 TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> stack;
        for (int i = 0, level, val; i < S.length();) {
            for (level = 0; S[i] == '-'; i++)
                level++;
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stack.size() > level) stack.pop_back();
            if (!stack.empty())
                if (!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            stack.push_back(node);
        }
        return stack[0];
    }
};
*/
